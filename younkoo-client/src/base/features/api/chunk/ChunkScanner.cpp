#include "ChunkScanner.h"

#include <wrapper/net/minecraft/client/Minecraft.h>
#include <JVM.hpp>



struct ChunkUpdateRequest : UpdateRequest {
	int x, z;
	std::shared_ptr<BlockChangeSubscriber> singleSubscriber;

	ChunkUpdateRequest(int x, int z, std::shared_ptr<BlockChangeSubscriber> sub = nullptr)
		: x(x), z(z), singleSubscriber(sub) {}
};

struct ChunkUnloadRequest : UpdateRequest {
	int x, z;

	ChunkUnloadRequest(int x, int z) : x(x), z(z) {}
};

struct BlockChangeRequest : UpdateRequest {
	TargetBlockPos pos;
	Wrapper::BlockState newState;

	BlockChangeRequest(TargetBlockPos pos, Wrapper::BlockState& newState)
		: pos(pos), newState(newState) {}
};
#include <base/features/modules/common/CommonData.h>
static void removeMarkedBlocksFromChunk(int x, int z) {
	for (const auto& sub : ChunkScanner::subscribers) {
		sub->clearChunk(x, z);
	}
}

static void scanChunk(const ChunkUpdateRequest* req) {
	static auto& common = CommonData::get();
	if (common.mc.isNULL()) return;
	auto level = common.mc.getWorld();
	if (level.isNULL()) return;
	auto chunk = level.getChunk(req->x, req->z);
	if (chunk.isNULL()) return;

	std::vector<std::shared_ptr<BlockChangeSubscriber>> currentSubscriber;

	if (req->singleSubscriber) {
		currentSubscriber.push_back(req->singleSubscriber);
	}
	else {
		std::lock_guard<std::mutex> lock(ChunkScanner::mutex);
		currentSubscriber = ChunkScanner::subscribers;
	}

	auto pos = chunk.getPos();

	for (const auto& sub : currentSubscriber) {
		sub->chunkUpdate(pos.x, pos.z);
	}

	auto start = std::chrono::high_resolution_clock::now();
	auto minPos = chunk.getMinPos();
	auto bottomY = chunk.getBottomY();

	std::vector<std::shared_ptr<BlockChangeSubscriber>> subscribersForRecordBlock;
	for (const auto& sub : currentSubscriber) {
		if (sub->shouldCallRecordBlockOnChunkUpdate()) {
			subscribersForRecordBlock.push_back(sub);
		}

	}

	for (int x = 0; x < 16; ++x) {
		for (int y = 0; y < chunk.getHeight(); ++y) {
			for (int z = 0; z < 16; ++z) {
				Wrapper::BlockPos pos(Math::Vector3D{ static_cast<double>(x + minPos.x),static_cast<double>(y + bottomY),static_cast<double>(z + minPos.z) });
				Wrapper::BlockState blockState = level.getBlockState(pos);

				for (const auto& sub : subscribersForRecordBlock) {
					sub->recordBlock(pos, blockState, true);
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	std::cout << "Scanning chunk took " << duration.count() << "us\n";
}


#include <base/Younkoo.hpp>
#include <base/event/Events.h>
void ChunkScanner::setup()
{
	auto& evt_bus = Younkoo::get().EventBus;
	static const auto registration_load_chunk = evt_bus->register_handler<EventLoadChunk>([](const EventLoadChunk& evt)
		{
			handleChunkLoad(evt.x, evt.z);
		});

	static const auto registration_unload_chunk = evt_bus->register_handler<EventUnloadChunk>([](const EventUnloadChunk& evt)
		{
			handleChunkUnload(evt.x, evt.z);
		});

	static const auto registration_update_chunk = evt_bus->register_handler<EventUpdateChunk>([](const EventUpdateChunk& evt)
		{
			handleChunkLoad(evt.x, evt.z);
		});

	static const auto registration_change_block = evt_bus->register_handler<EventChangeBlock>([](const EventChangeBlock& evt)
		{
			handleBlockChange(evt.pos, evt.state);
		});

	ChunkScannerThread::thread = std::thread(ChunkScannerThread::threadFunction);
}

void ChunkScanner::clean()
{
	{
		std::lock_guard<std::mutex> lock(ChunkScannerThread::queueMutex_);
		ChunkScannerThread::stopFlag_ = true;
	}
	ChunkScannerThread::queueCondition_.notify_all();
	ChunkScannerThread::thread.detach();
}

void ChunkScanner::subscribe(std::shared_ptr<BlockChangeSubscriber> newSubscriber)
{
	std::lock_guard<std::mutex> lock(mutex);
	subscribers.push_back(newSubscriber);
	std::cout << "Scanning " << loadedChunks.size() << " chunks for subscriber\n";
	for (const auto& loadedChunk : loadedChunks) {
		ChunkScannerThread::enqueueChunkUpdate(std::make_unique<ChunkUpdateRequest>(loadedChunk.x, loadedChunk.z, newSubscriber));
	}
}

void ChunkScanner::unsubscribe(std::shared_ptr<BlockChangeSubscriber> oldSubscriber)
{
	std::lock_guard<std::mutex> lock(mutex);
	subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), oldSubscriber), subscribers.end());
	oldSubscriber->clearAllChunks();
}

void ChunkScanner::handleChunkLoad(int x, int z)
{
	ChunkScannerThread::enqueueChunkUpdate(std::make_unique<ChunkUpdateRequest>(x, z));
	loadedChunks.emplace(x, z);
}

void ChunkScanner::handleChunkUnload(int x, int z)
{
	ChunkScannerThread::enqueueChunkUpdate(std::make_unique<ChunkUnloadRequest>(x, z));
	loadedChunks.erase({ x, z });
}

void ChunkScanner::handleBlockChange(Wrapper::BlockPos& pos, Wrapper::BlockState& newState)
{
	ChunkScannerThread::enqueueChunkUpdate(std::make_unique<BlockChangeRequest>(TargetBlockPos(pos), newState));
}

void ChunkScanner::handleDisconnect()
{
	std::lock_guard<std::mutex> lock(mutex);
	for (const auto& sub : subscribers) {
		sub->clearAllChunks();
	}
	loadedChunks.clear();
}

void ChunkScannerThread::threadFunction() {
	auto env = JVM::get().attachAndGetEnv();
	JNI::set_thread_env(env);
	while (true) {
		std::unique_lock<std::mutex> lock(queueMutex_);
		queueCondition_.wait(lock, [] { return stopFlag_ || !chunkUpdateQueue_.empty(); });

		if (stopFlag_) {
			break; // 如果停止标志为真且队列为空，则退出循环
		}

		auto request = std::move(chunkUpdateQueue_.front());
		chunkUpdateQueue_.pop();
		lock.unlock();

		if (!request) continue;

		// Process the request (chunk updates, unloads, block changes)
		processUpdateRequest(*request);
	}
}

inline void ChunkScannerThread::processUpdateRequest(UpdateRequest& request) {
	// Add processing logic here
	const auto* chunkUpdateReq = dynamic_cast<const ChunkUpdateRequest*>(&request);
	if (chunkUpdateReq) {
		scanChunk(chunkUpdateReq);
		return;
	}

	const auto* chunkUnloadReq = dynamic_cast<const ChunkUnloadRequest*>(&request);
	if (chunkUnloadReq) {
		removeMarkedBlocksFromChunk(chunkUnloadReq->x, chunkUnloadReq->z);
		return;
	}

	auto* blockChangeReq = dynamic_cast<BlockChangeRequest*>(&request);
	if (blockChangeReq) {
		for (auto& sub : ChunkScanner::subscribers) {
			sub->recordBlock(
				blockChangeReq->pos,
				blockChangeReq->newState,
				false
			);
		}
		return;
	}
}

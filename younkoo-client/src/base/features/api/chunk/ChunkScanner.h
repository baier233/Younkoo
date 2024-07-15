#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

#include <utils/Singleton.hpp>
#include <wrapper/net/minecraft/block/state/BlockState.h>
#include <wrapper/net/minecraft/util/BlockPos.h>

struct TargetBlockPos {
	int x, y, z;
	TargetBlockPos(int x, int y, int z) : x(x), y(y), z(z) {}
	TargetBlockPos(Wrapper::BlockPos& pos) : x(pos.getX()), y(pos.getY()), z(pos.getZ()) {}

	bool operator==(const TargetBlockPos& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	struct Hash {
		std::size_t operator()(const TargetBlockPos& pos) const {
			return std::hash<int>()(pos.x) ^ std::hash<int>()(pos.y) ^ std::hash<int>()(pos.z);
		}
	};
};


struct ChunkLocation {
	int x, z;

	bool operator==(const ChunkLocation& other) const {
		return x == other.x && z == other.z;
	}
};

namespace std {
	template <>
	struct hash<ChunkLocation> {
		std::size_t operator()(const ChunkLocation& loc) const {
			return std::hash<int>()(loc.x) ^ std::hash<int>()(loc.z);
		}
	};
}

class BlockChangeSubscriber {
public:
	virtual bool shouldCallRecordBlockOnChunkUpdate() const {
		return true;
	}

	virtual void recordBlock(TargetBlockPos pos, Wrapper::BlockState& state, bool cleared) = 0;
	virtual void chunkUpdate(int x, int z) = 0;
	virtual void clearChunk(int x, int z) = 0;
	virtual void clearAllChunks() = 0;
};


class ChunkScanner {
public:
	static void setup();
	static void clean();
	static void subscribe(std::shared_ptr<BlockChangeSubscriber> newSubscriber);
	static void unsubscribe(std::shared_ptr<BlockChangeSubscriber> oldSubscriber);

	static void handleChunkLoad(int x, int z);
	static void handleChunkUnload(int x, int z);
	static void handleBlockChange(Wrapper::BlockPos& pos, Wrapper::BlockState& newState);
	static void handleDisconnect();

	inline static std::vector<std::shared_ptr<BlockChangeSubscriber>> subscribers;
	inline static std::unordered_set<ChunkLocation> loadedChunks;
	inline static std::mutex mutex;
private:


};

struct UpdateRequest {
	virtual ~UpdateRequest() = default;
};

static class ChunkScannerThread {
public:

	inline static void enqueueChunkUpdate(std::unique_ptr<UpdateRequest> request) {
		std::unique_lock<std::mutex> lock(queueMutex_);
		chunkUpdateQueue_.push(std::move(request));
		queueCondition_.notify_one();
	}

	inline static std::thread thread;
	inline static std::mutex queueMutex_;
	inline static std::condition_variable queueCondition_;
	inline static std::atomic<bool> stopFlag_{ false };
	static void threadFunction();
private:
	inline static std::queue<std::unique_ptr<UpdateRequest>> chunkUpdateQueue_;

	static void processUpdateRequest(UpdateRequest& request);
};

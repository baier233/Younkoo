#pragma once

#include <unordered_map>
#include <memory>
#include <mutex>
#include "chunk/ChunkScanner.h"


template <typename T>
class AbstractBlockLocationTracker : public BlockChangeSubscriber {
public:
	AbstractBlockLocationTracker() = default;
	virtual ~AbstractBlockLocationTracker() = default;

	virtual std::shared_ptr<T> getStateFor(TargetBlockPos pos, Wrapper::BlockState& state) = 0;

	void recordBlock(TargetBlockPos pos, Wrapper::BlockState& state, bool cleared) override;
	void clearChunk(int x, int z) override;
	void clearAllChunks() override;
	void chunkUpdate(int x, int z) override;

	std::unordered_map<TargetBlockPos, std::shared_ptr<T>, TargetBlockPos::Hash> trackedBlockMap;
protected:
	std::mutex mapMutex;

};


template<typename T>
inline void AbstractBlockLocationTracker<T>::recordBlock(TargetBlockPos pos, Wrapper::BlockState& state, bool cleared)
{
	auto newState = this->getStateFor(pos, state);
	TargetBlockPos targetBlockPos(pos);

	std::lock_guard<std::mutex> lock(mapMutex);
	if (!newState) {
		if (!cleared) {
			trackedBlockMap.erase(targetBlockPos);
		}
		return;
	}

	trackedBlockMap[targetBlockPos] = newState;
}

template <typename T>
inline void AbstractBlockLocationTracker<T>::clearChunk(int x, int z) {
	std::lock_guard<std::mutex> lock(mapMutex);
	for (auto it = trackedBlockMap.begin(); it != trackedBlockMap.end(); ) {
		if ((static_cast<int>(it->first.x) >> 4) == x && (static_cast<int>(it->first.z) >> 4) == z) {
			it = trackedBlockMap.erase(it);
		}
		else {
			++it;
		}
	}
}

template <typename T>
inline void AbstractBlockLocationTracker<T>::clearAllChunks() {
	std::lock_guard<std::mutex> lock(mapMutex);
	trackedBlockMap.clear();
}

template <typename T>
inline void AbstractBlockLocationTracker<T>::chunkUpdate(int x, int z) {
	// Do nothing. Logic is already implemented in recordBlock
}

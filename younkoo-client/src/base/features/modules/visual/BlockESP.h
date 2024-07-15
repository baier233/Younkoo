#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"

#include <unordered_set>

#include <base/features/api/AbstractBlockLocationTracker.h>
#include <base/features/api/InventoryUtils.h>

class TrackedState {};
class BlockTracker : public AbstractBlockLocationTracker<TrackedState> {
public:
	BlockTracker(const std::vector<std::string>& targets);
	std::shared_ptr<TrackedState> getStateFor(TargetBlockPos pos, Wrapper::BlockState& state) override;

private:
	inline bool filterBlock(const Wrapper::Block& block) {
		auto klass = block.getClassBaseOnObject();
		for (auto& target : targets_)
		{
			if (JNI::get_env()->IsSameObject(klass, target))
			{
				return true;
			}
		}
		return false;
	}

	std::vector<jclass> targets_;
};
inline BlockTracker::BlockTracker(const std::vector<std::string>& targets)
{
	targets_ = InventoryUtils::findBlocksEndingWith(targets);
	std::cout << "targets_ :" << targets_.size() << std::endl;
}

inline std::shared_ptr<TrackedState> BlockTracker::getStateFor(TargetBlockPos pos, Wrapper::BlockState& state)
{
	if (!state.isAir() && filterBlock(state.getBlock())) {
		return std::make_shared<TrackedState>();
	}
	return nullptr;
}



class BlockESP : public AbstractModule
{
public:
	static BlockESP& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	void onRender3D(const EventRender3D& e);
private:
	BlockESP();
	std::vector<std::string> targets_;
	std::shared_ptr<BlockTracker> blockTracker_;
};

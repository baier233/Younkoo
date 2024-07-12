#include "AutoTool.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>
#include <base/features/modules/common/CommonData.h>


#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/net/minecraft/util/BlockPos.h>




AutoTool::AutoTool() : AbstractModule(xorstr_("AutoTool"), Category::PLAYER)
{
}


AutoTool& AutoTool::getInstance()
{
	static AutoTool instance = AutoTool();
	return instance;
}

void AutoTool::onEnable()
{
}

void AutoTool::onDisable()
{

}


void AutoTool::onUpdate()
{
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (NanoGui::available || mc.isInGuiState()) return;
	auto player = mc.getPlayer();
	auto level = mc.getWorld();
	if (IsKeyBeingDown(VK_LBUTTON)) {
		float bestSpeed = 1.f;
		int bestSlot = -1;
		Wrapper::MovingObjectPosition mouseover = mc.getMouseOver();

		if (mouseover.isNULL())
		{
			return;
		}
		if (!mouseover.isTypeOfBlock()) return;
		Wrapper::BlockState blockstate{};
		Wrapper::BlockPos blockpos = mouseover.getBlockPos();

		if (blockpos.isNULL())
		{
			return;
		}



		blockstate = level.getBlockState(blockpos);

		if (blockstate.isNULL()) return;



		auto inventory = player.getInventory();

		if (inventory.isNULL()) return;

		for (int i = 0; i <= 8; i++)
		{
			auto item = inventory.getStackInSlot(i);
			if (item.isNULL()) continue;

			float speed;
			speed = item.getStrVsBlock(blockstate);

			if (speed > bestSpeed) {
				bestSpeed = speed;
				bestSlot = i;
			}
		}

		if (bestSlot == -1)
		{
			return;
		}
		if (bestSlot == inventory.getCurrentSlot())
		{
			return;
		}

		inventory.setCurrentItem(bestSlot);
	}

	return;

}


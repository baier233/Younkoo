#include "Eagle.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>




Eagle::Eagle() :AbstractModule(xorstr_("Eagle"), Category::PLAYER)
{
}


Eagle& Eagle::getInstance()
{
	static Eagle instance = Eagle();
	return instance;
}

void Eagle::onEnable()
{
}

void Eagle::onDisable()
{

}


void Eagle::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto player = mc.getPlayer();
	auto level = mc.getWorld();

	auto state = level.getBlockState(player.getPosition() - Math::Vector3D{ 0,0.49,0 });
	auto result = !state.isNULL() && state.isAir();
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		auto options = mc.getSettings();
		if (options.isNULL()) return;
		options.setShiftKeyPressed(result);
	}
	else {
		player.setSneak(result);
	}

	return;

}


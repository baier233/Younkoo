#include "ESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
ESP::ESP() :AbstractModule(xorstr_("ESP"), Category::VISUAL)
{
}


ESP& ESP::getInstance()
{
	static ESP instance = ESP();
	return instance;
}

void ESP::onEnable()
{
}

void ESP::onDisable()
{
}

void ESP::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;
	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	for (auto& player : players)
	{
		if (player.isEqualTo(mc.getPlayer()))
		{
			continue;
		}
		player.setGlowing(true);
	}
}

void ESP::onRender(const EventRender2D& e)
{

	ToggleCheck;
}

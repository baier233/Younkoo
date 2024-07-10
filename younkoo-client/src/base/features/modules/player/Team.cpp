#include "Team.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>




Team::Team() :AbstractModule(xorstr_("Team"), Category::PLAYER)
{
}


Team& Team::getInstance()
{
	static Team instance = Team();
	return instance;
}

void Team::onEnable()
{
}

void Team::onDisable()
{

}


void Team::onUpdate()
{
}

bool Team::isSameTeam(Wrapper::EntityPlayer& other)
{
	if (this->getToggle() && SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		auto mc = Wrapper::Minecraft::getMinecraft();
		auto player = mc.getPlayer();
		return player.isSameTeam(other);
	}
	return false;
}



#include "Jamming.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <random>
#include <base/features/modules/player/Team.h>


Jamming::Jamming() :AbstractModule(xorstr_("Jamming"), Category::COMBAT, 'L')
{
	this->setToggle(false);

}

Jamming& Jamming::getInstance()
{
	static Jamming instance = Jamming();
	return instance;
}

void Jamming::onEnable()
{

}

void Jamming::onDisable()
{

}
#include <hotspot/classes/instance_klass.h>

void Jamming::onUpdate()
{
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (NanoGui::available || mc.isInGuiState()) return;

}
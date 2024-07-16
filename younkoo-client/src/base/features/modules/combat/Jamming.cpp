#include "Jamming.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <random>
#include <base/features/modules/player/Team.h>

#include <base/features/modules/ModuleManager.h>

#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>
Jamming::Jamming() :AbstractModule(xorstr_("Jamming"), Category::COMBAT, 'L')
{
	this->setToggle(false);
	REGISTER_EVENT(EventAttack, Jamming::onAttack);
}

Jamming& Jamming::getInstance()
{
	static Jamming instance = Jamming();
	return instance;
}

void Jamming::onAttack(const EventAttack& e)
{
	ToggleCheck;
	auto& entity = e.entity;
	static auto playerKlass = Wrapper::EntityPlayer::klass();
	if (!entity.instanceOf(playerKlass)) return;

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
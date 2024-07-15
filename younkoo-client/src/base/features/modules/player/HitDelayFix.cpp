#include "HitDelayFix.h"

HitDelayFix::HitDelayFix() :AbstractModule(xorstr_("HitDelayFix"), Category::PLAYER)
{
}

HitDelayFix& HitDelayFix::getInstance()
{
	static HitDelayFix instance = HitDelayFix();
	return instance;
}

void HitDelayFix::onEnable()
{
}

void HitDelayFix::onDisable()
{

}


void HitDelayFix::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	mc.setLeftClickCounter(0);
}
#include "FastPlace.h"

FastPlace::FastPlace() :AbstractModule(xorstr_("FastPlace"), Category::PLAYER)
{
}

FastPlace& FastPlace::getInstance()
{
	static FastPlace instance = FastPlace();
	return instance;
}

void FastPlace::onEnable()
{
}

void FastPlace::onDisable()
{

}


void FastPlace::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	mc.setRightClickDelayTimer(0);
}
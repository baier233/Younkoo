#include "SafeWalk.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>




SafeWalk::SafeWalk() :AbstractModule(xorstr_("SafeWalk"), Category::PLAYER)
{
}


SafeWalk& SafeWalk::getInstance()
{
	static SafeWalk instance = SafeWalk();
	return instance;
}

void SafeWalk::onEnable()
{
}

void SafeWalk::onDisable()
{

}


void SafeWalk::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto player = mc.getPlayer();
	double x = player.getMotion().x;
	double y = player.getMotion().y;
	double z = player.getMotion().z;
	if (player.isOnGround()) {
		double increment;
		for (increment = 0.05; x != 0.0; ) {
			if (x < increment && x >= -increment) {
				x = 0.0;
			}
			else if (x > 0.0) {
				x -= increment;
			}
			else {
				x += increment;
			}
		}
		for (; z != 0.0; ) {
			if (z < increment && z >= -increment) {
				z = 0.0;
			}
			else if (z > 0.0) {
				z -= increment;
			}
			else {
				z += increment;
			}
		}
		for (; x != 0.0 && z != 0.0; ) {
			if (x < increment && x >= -increment) {
				x = 0.0;
			}
			else if (x > 0.0) {
				x -= increment;
			}
			else {
				x += increment;
			}
			if (z < increment && z >= -increment) {
				z = 0.0;
			}
			else if (z > 0.0) {
				z -= increment;
			}
			else {
				z += increment;
			}
		}
	}
	player.setMotion(Math::Vector3D(x, y, z));
}


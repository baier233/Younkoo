#pragma once

#include <SDK.hpp>
#include "wrapper/net/minecraft/util/MovingObjectPosition.h"
#include "wrapper/net/minecraft/world/World.h"
#include "wrapper/net/minecraft/client/entity/EntityPlayerSP.h"
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/client/settings/GameSettings.h>

BEGIN_WRAP

class Minecraft :public Object {
public:
	using Object::Object;
	static Minecraft getMinecraft();
	static Minecraft static_obj();
	bool isInGuiState();
	World getWorld();
	EntityPlayerSP getPlayer();
	MovingObjectPosition getMouseOver();
	float getFrameTime();
	GameSettings getSettings();
	void setLeftClickCounter(int value);
	void setRightClickDelayTimer(int value);

private:
};

END_WRAP
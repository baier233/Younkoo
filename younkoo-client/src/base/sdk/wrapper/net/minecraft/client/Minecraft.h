#pragma once

#include <SDK.hpp>
#include "wrapper/versions/1_18_1/net/minecraft/client/MInecraft.h"
#include "wrapper/net/minecraft/util/MovingObjectPosition.h"
#include "wrapper/net/minecraft/client/player/LocalPlayer.h"
#include "wrapper/Object.h"

BEGIN_WRAP

class Minecraft :public Object {
public:
	using Object::Object;
	static Minecraft getMinecraft();
	static Minecraft static_obj();
	bool isInGuiState();
	MovingObjectPosition getMouseOver();
	LocalPlayer getPlayer();

private:
	Minecraft() = default;
};

END_WRAP
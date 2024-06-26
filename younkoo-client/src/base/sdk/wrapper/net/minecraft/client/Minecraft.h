#pragma once

#include <SDK.hpp>
#include "wrapper/versions/1_18_1/net/minecraft/client/MInecraft.h"
#include "wrapper/net/minecraft/util/MovingObjectPosition.h"
#include "wrapper/Object.h"

BEGIN_WRAP

class Minecraft :public Object {
public:
	using Object::Object;
	static Minecraft getMinecraft();
	static Minecraft get();
	bool isInGuiState();
	MovingObjectPosition getMouseOver();

private:
	Minecraft() = default;
};

END_WRAP
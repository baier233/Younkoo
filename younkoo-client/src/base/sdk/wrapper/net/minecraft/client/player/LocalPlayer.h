#pragma once

#include <SDK.hpp>
#include "wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h"
#include "wrapper/Object.h"

BEGIN_WRAP

class LocalPlayer :public Object {
public:
	using Object::Object;
	bool isHnadBusy();
private:
};

END_WRAP
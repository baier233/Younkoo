#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include "wrapper/net/minecraft/entity/player/EntityPlayer.h"

BEGIN_WRAP
class World :public Object {
public:
	using Object::Object;
	std::vector<EntityPlayer> getPlayerList();

};

END_WRAP
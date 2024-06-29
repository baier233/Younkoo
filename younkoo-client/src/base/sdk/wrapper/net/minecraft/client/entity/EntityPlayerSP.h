#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>

BEGIN_WRAP
class EntityPlayerSP :public EntityPlayer {
public:
	using EntityPlayer::EntityPlayer;

};

END_WRAP
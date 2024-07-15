#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include "wrapper/net/minecraft/entity/player/EntityPlayer.h"
#include <wrapper/net/minecraft/block/state/BlockState.h>
#include <wrapper/net/minecraft/util/BlockPos.h>
#include <wrapper/net/minecraft/world/chunk/Chunk.h>

BEGIN_WRAP
class World :public Object {
public:
	using Object::Object;
	std::vector<EntityPlayer> getPlayerList();
	std::vector<Entity> getEntityList();
	BlockState getBlockState(const Math::Vector3D& pos);
	BlockState getBlockState(const BlockPos& pos);
	Chunk getChunk(int x, int z);
};

END_WRAP
#include "World.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
#include <wrapper/net/minecraft/util/BlockPos.h>

std::vector<Wrapper::EntityPlayer> Wrapper::World::getPlayerList()
{
	std::vector<EntityPlayer> result;
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::ClientLevel level = this->getObject();
		auto players = level.players.get();

		if (!players.object_instance) return result;

		auto vec = (/*(JNI::Array<V1_18_1::Player>)*/players.toArray()).to_vector();
		for (auto& obj : vec)
		{
			result.push_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
		return result;
	}
	return result;
}

std::vector<Wrapper::Entity> Wrapper::World::getEntityList()
{
	auto result = std::vector<Entity>();
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::ClientLevel level = this->getObject();
		auto iterator = level.entitiesForRendering().iterator();
		while (iterator.hasNext()) {
			result.push_back(iterator.next());
		}
	}
	return result;
}

Wrapper::BlockState Wrapper::World::getBlockState(const Math::Vector3D& pos)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Level level = this->getObject();
		V1_18_1::BlockPos blockPos = V1_18_1::BlockPos::create(pos);
		return level.getBlockState(blockPos);
	}
	return BlockState();
}

Wrapper::BlockState Wrapper::World::getBlockState(const BlockPos& pos)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Level level = this->getObject();
		V1_18_1::BlockPos blockPos = pos.getObject();
		return level.getBlockState(blockPos);
	}
	return BlockState();
}

#include "World.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>

std::vector<Wrapper::EntityPlayer> Wrapper::World::getPlayerList()
{
	std::vector<EntityPlayer> result;
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::ClientLevel level = this->instance->object_instance;
		auto players = level.players.get();

		if (!players.object_instance) return result;

		auto vec = ((JNI::Array<V1_18_1::Player>)players.toArray()).to_vector();
		for (auto& obj : vec)
		{
			result.emplace_back(EntityPlayer(JNI::EmptyMembers(obj)));
		}
		return result;
	}
	return result;
}

#include "EntityPlayer.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
bool Wrapper::EntityPlayer::isSameTeam(EntityPlayer& other)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		if (!this->getObject() || this->isNULL()) return false;
		if (!other.getObject() || other.isNULL()) return false;


		V1_18_1::Player player = this->getObject();
		V1_18_1::Player another = other.getObject();
		if (!another.is_instance_of<V1_18_1::Player>()) return false;

		return !player.canHarmPlayer(another);
	}
	return false;
}

jclass Wrapper::EntityPlayer::klass()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		return V1_18_1::Player::static_obj().owner_klass;
	}
	return jclass();
}

Wrapper::InventoryPlayer Wrapper::EntityPlayer::getInventory()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Player player = this->getObject();
		return player.getInventory();
	}
	return InventoryPlayer();
}

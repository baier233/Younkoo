#include "InventoryPlayer.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Inventory.h>

Wrapper::ItemStack Wrapper::InventoryPlayer::getArrmorItem(int index)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Inventory inventory = this->getObject();
		auto arrmors = inventory.armor.get().list.get().toArray().to_vector();
		return arrmors.at(index);
	}
	return ItemStack();
}

Wrapper::ItemStack Wrapper::InventoryPlayer::getStackInSlot(int index)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.getItem(index);
	}
	return ItemStack();
}

void Wrapper::InventoryPlayer::setCurrentItem(int index)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.selected.set(index);
	}
}

int Wrapper::InventoryPlayer::getCurrentSlot()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Inventory inventory = this->getObject();
		return inventory.selected.get();
	}
	return 0;
}

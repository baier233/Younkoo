#include "ItemStack.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/Item.h>

float Wrapper::ItemStack::getStrVsBlock(const BlockState& state)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::ItemStack stack = this->getObject();
		V1_18_1::BlockState blockstate = state.getObject();
		return stack.getDestroySpeed(blockstate);
	}
	return 0.0f;
}

Wrapper::Item Wrapper::ItemStack::getItem()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::ItemStack stack = this->getObject();
		return stack.getItem();
	}
	return Item();
}


int Wrapper::ItemStack::getColorBasedOnRarity()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::ItemStack stack = this->getObject();
		V1_18_1::Rarity rarity = stack.getRarity();
		auto isRare = rarity == rarity.RARE.get() || rarity == rarity.UNCOMMON.get() || rarity == rarity.EPIC.get();
		return /*isRare ?*/ rarity.color.get().color.get().intValue() /*: 0XFFFFFF*/;
	}
	return 0;
}

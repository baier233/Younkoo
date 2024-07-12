#pragma once
#include <wrapper/Object.h>
#include <SDK.hpp>
#include <wrapper/net/minecraft/block/state/BlockState.h>
#include <wrapper/net/minecraft/item/Item.h>
BEGIN_WRAP;
class ItemStack : public Object
{
public:
	using Object::Object;
	float getStrVsBlock(const BlockState& state);
	int getColorBasedOnRarity();
	Wrapper::Item getItem();
};
END_WRAP;


#pragma once
#include <wrapper/Object.h>
#include <SDK.hpp>
#include <wrapper/net/minecraft/block/state/BlockState.h>
BEGIN_WRAP;
class ItemStack : public Object
{
public:
	using Object::Object;
	float getStrVsBlock(const BlockState& state);
	int getColorBasedOnRarity();
};
END_WRAP;


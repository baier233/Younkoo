#include "ItemStack.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>
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

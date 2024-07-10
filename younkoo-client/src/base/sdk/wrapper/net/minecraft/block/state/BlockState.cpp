#include "BlockState.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>
Wrapper::Block Wrapper::BlockState::getBlock()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::BlockState state = this->getObject();
		return state.getBlock();
	}
	return Block();
}

bool Wrapper::BlockState::isAir()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::BlockState state = this->getObject();
		return state.isAir();
	}
	return false;
}

#include "Block.h"
#include <wrapper/net/minecraft/block/state/BlockState.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/Block.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>
int Wrapper::Block::getID(Wrapper::BlockState& state)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Block block = this->getObject();

		//return block.getId(state.getObject());
	}
	return 0;
}

#include "ItemBlock.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/item/BlockItem.h>

jclass Wrapper::ItemBlock::klass()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		static auto klass = V1_18_1::BlockItem::static_obj().init();
		return klass;
	}
	return jclass();
}

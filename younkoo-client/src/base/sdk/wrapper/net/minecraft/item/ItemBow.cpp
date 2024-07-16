#include "ItemBow.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/item/BowItem.h>

jclass Wrapper::ItemBow::klass()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		static auto klass = V1_18_1::BowItem::static_obj().init();
		return klass;
	}
	return jclass();
}

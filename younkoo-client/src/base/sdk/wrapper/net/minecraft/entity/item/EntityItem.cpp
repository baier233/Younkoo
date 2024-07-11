#include "EntityItem.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/item/ItemEntity.h>

jclass Wrapper::EntityItem::klass()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		static auto klass = V1_18_1::ItemEntity::static_obj().init();
		return klass;
	}
	return jclass();
}

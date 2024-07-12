#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/item/ItemStack.h>

BEGIN_WRAP
class EntityItem :public Object {
public:

	static jclass klass();
	ItemStack getItemStack();
};

END_WRAP
#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/item/ItemStack.h>

BEGIN_WRAP
class InventoryPlayer :public Object {
public:
	using Object::Object;
	ItemStack getArrmorItem(int index);
	ItemStack getStackInSlot(int index);
	void setCurrentItem(int index);

	int getCurrentSlot();
	ItemStack getCurrentItem();
};


END_WRAP
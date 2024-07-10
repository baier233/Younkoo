#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/EntityLivingBase.h>
#include "InventoryPlayer.h"

BEGIN_WRAP
class EntityPlayer :public EntityLivingBase {
public:
	using EntityLivingBase::EntityLivingBase;

	bool isSameTeam(EntityPlayer& other);
	static jclass klass();
	InventoryPlayer getInventory();

};

END_WRAP
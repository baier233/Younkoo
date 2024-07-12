#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/Entity.h>
#include <wrapper/net/minecraft/item/ItemStack.h>
BEGIN_WRAP
class EntityLivingBase :public Entity {
public:
	using Entity::Entity;
	float getHealth();
	Wrapper::ItemStack getMainHandItemStack();
	Wrapper::ItemStack getOffhandItemStack();
};

END_WRAP
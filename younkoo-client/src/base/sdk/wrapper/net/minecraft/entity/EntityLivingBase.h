#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/Entity.h>

BEGIN_WRAP
class EntityLivingBase :public Entity {
public:
	using Entity::Entity;
	float getHealth();
};

END_WRAP
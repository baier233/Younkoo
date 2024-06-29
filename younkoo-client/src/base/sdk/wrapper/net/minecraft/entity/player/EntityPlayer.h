#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/EntityLivingBase.h>

BEGIN_WRAP
class EntityPlayer :public EntityLivingBase {
public:
	using EntityLivingBase::EntityLivingBase;

};

END_WRAP
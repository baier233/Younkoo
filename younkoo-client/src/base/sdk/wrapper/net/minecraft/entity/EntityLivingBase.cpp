#include "EntityLivingBase.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>

float Wrapper::EntityLivingBase::getHealth()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getHealth();
	}
	return 0.0f;
}

Wrapper::ItemStack Wrapper::EntityLivingBase::getMainHandItemStack()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getMainHandItem();
	}
	return ItemStack();
}

Wrapper::ItemStack Wrapper::EntityLivingBase::getOffhandItemStack()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LivingEntity livingEntity = this->getObject();
		return livingEntity.getOffhandItem();
	}
	return ItemStack();
}
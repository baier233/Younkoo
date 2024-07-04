#include "Entity.h"

#include "wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h"
void Wrapper::Entity::setGlowing(bool value)
{

	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		entity.setGlowingTag(value);
		return;
	}
	return;
}

Math::Vector3D Wrapper::Entity::getPosition()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;

		return entity.position.get().toVector3();
	}
	return Math::Vector3D();
}

Math::Vector3D Wrapper::Entity::getPosition(float tickDetla)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		return Math::Vector3D(
			entity.xOld.get() + (entity.getX() - entity.xOld.get()) * static_cast<double>(tickDetla),
			entity.yOld.get() + (entity.getY() - entity.yOld.get()) * static_cast<double>(tickDetla),
			entity.zOld.get() + (entity.getZ() - entity.zOld.get()) * static_cast<double>(tickDetla)
		);
	}
	return Math::Vector3D();
}

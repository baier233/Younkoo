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

Math::Vector3D Wrapper::Entity::getLastTickPos()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->instance->object_instance;
		return Math::Vector3D(
			entity.xOld.get(),
			entity.yOld.get(),
			entity.zOld.get()
		);
	}
	return Math::Vector3D();
}

std::string Wrapper::Entity::getDisplayName()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		return entity.getDisplayName().getString().toString();
	}
	return std::string();
}

float Wrapper::Entity::getWidth()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		return entity.getBbWidth();
	}
	return 0.0f;
}

float Wrapper::Entity::getHeight()
{

	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		return entity.getBbHeight();
	}
	return 0.0f;
}

Math::Vector2 Wrapper::Entity::getAngles()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		auto rotation = entity.getRotationVector();
		return { rotation.x.get(), rotation.y.get() };
	}
	return Math::Vector2();
}

void Wrapper::Entity::setAngles(Math::Vector2 angles)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		entity.setRot(angles.x, angles.y);
	}
	return;
}

float Wrapper::Entity::getEyeHeight()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		auto rotation = entity.getRotationVector();
		return entity.getEyeHeight();
	}
	return 0.0f;
}

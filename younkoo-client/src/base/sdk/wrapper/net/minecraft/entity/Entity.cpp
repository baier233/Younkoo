#include "Entity.h"

#include "wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h"
void Wrapper::Entity::setGlowing(bool value)
{

	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();
		entity.setGlowingTag(value);
		return;
	}
	return;
}

Math::Vector3D Wrapper::Entity::getPosition()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();

		return entity.position.get().toVector3();
	}
	return Math::Vector3D();
}

Math::Vector3D Wrapper::Entity::getPosition(float tickDetla)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();
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
		V1_18_1::Entity entity = this->getObject();
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

		V1_18_1::Entity entity = this->getObject();
		return entity.getDisplayName().getString().toString();
	}
	return std::string();
}

float Wrapper::Entity::getWidth()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();
		return entity.getBbWidth();
	}
	return 0.0f;
}

float Wrapper::Entity::getHeight()
{
	if (this->getObject() == nullptr) return 0.0f;
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();
		return entity.getBbHeight();
	}
	return 0.0f;
}

Math::Vector2 Wrapper::Entity::getAngles()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->getObject();
		auto rotation = entity.getRotationVector();
		//Yaw is yRot,Pitch is xRot
		return { rotation.y.get(), rotation.x.get() };
	}
	return Math::Vector2();
}

void Wrapper::Entity::setAngles(Math::Vector2 angles)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		angles = { angles.y,angles.x };
		V1_18_1::Entity entity = this->getObject();
		entity.setXRot(angles.x);
		entity.setYRot(angles.y);
		entity.setYHeadRot(angles.y);
		entity.xOld = angles.x;
		entity.yOld = angles.y;
	}
	return;
}

float Wrapper::Entity::getEyeHeight()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getEyeHeight();
	}
	return 0.0f;
}

bool Wrapper::Entity::isOnGround()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.isOnGround();
	}
	return false;
}

bool Wrapper::Entity::isSneaking()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.isShiftKeyDown();
	}
	return false;
}

Math::Vector3D Wrapper::Entity::getMotion()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getDeltaMovement().toVector3();
	}
	return Math::Vector3D();
}

void Wrapper::Entity::setMotion(Math::Vector3D motion)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		entity.setDeltaMovement(V1_18_1::Vec3::fromVector3(motion));
	}
}

void Wrapper::Entity::setSneak(bool value)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		entity.setShiftKeyDown(value);
	}
}

Math::Box<double> Wrapper::Entity::getBoundingBox()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Entity entity = this->getObject();
		return entity.getBoundingBox().toBox();
	}
	return Math::Box<double>();
}

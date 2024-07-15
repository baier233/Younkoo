#include "Vec3i.h"

#include <wrapper/versions/1_18_1/net/minecraft/core/Vec3i.h>

int Wrapper::Vec3i::getX()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.x.get();
	}
	return 0;
}

int Wrapper::Vec3i::getY()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.y.get();
	}
	return 0;
}

int Wrapper::Vec3i::getZ()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.z.get();
	}
	return 0;
}

Math::Vector3i Wrapper::Vec3i::toVector()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return Math::Vector3i{ vec3.x.get(),vec3.y.get(),vec3.z.get() };
	}
	return Math::Vector3i{};
}

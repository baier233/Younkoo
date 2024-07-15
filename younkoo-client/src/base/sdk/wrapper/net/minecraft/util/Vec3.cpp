#include "Vec3.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>
double Wrapper::Vec3::getX()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3 vec3 = this->getObject();
		return vec3.x.get();
	}
	return 0.0;
}

double Wrapper::Vec3::getY()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3 vec3 = this->getObject();
		return vec3.y.get();
	}
	return 0.0;
}

double Wrapper::Vec3::getZ()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3 vec3 = this->getObject();
		return vec3.z.get();
	}
	return 0.0;
}

Math::Vector3D Wrapper::Vec3::toVector()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Vec3 vec3 = this->getObject();
		return vec3.toVector3();
	}
	return Math::Vector3D();
}

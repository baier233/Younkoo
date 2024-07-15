#pragma once
#include <SDK.hpp>
#include <wrapper/Object.h>
#include <utils/types/Maths.hpp>
BEGIN_WRAP
class Vec3 : public Object
{
public:
	using Object::Object;
	double getX();
	double getY();
	double getZ();
	Math::Vector3D toVector();
};
END_WRAP


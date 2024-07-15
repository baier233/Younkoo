#pragma once
#include <SDK.hpp>
#include <wrapper/Object.h>
#include <utils/types/Maths.hpp>
BEGIN_WRAP
class Vec3i : public Object
{
public:
	using Object::Object;
	int getX();
	int getY();
	int getZ();
	Math::Vector3i toVector();
};
END_WRAP


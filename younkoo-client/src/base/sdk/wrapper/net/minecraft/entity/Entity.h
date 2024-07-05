#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>
BEGIN_WRAP
class Entity :public Object {
public:
	using Object::Object;
	// higer version only
	void setGlowing(bool value);
	Math::Vector3D getPosition();
	Math::Vector3D getPosition(float tickDetal);
	float getHeight();
};

END_WRAP
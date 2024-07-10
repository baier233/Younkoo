#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>

#include <string>

BEGIN_WRAP
class Entity :public Object {
public:
	using Object::Object;
	// higer version only
	void setGlowing(bool value);
	Math::Vector3D getPosition();
	Math::Vector3D getPosition(float tickDetal);
	Math::Vector3D getLastTickPos();
	std::string getDisplayName();
	float getWidth();
	float getHeight();
	Math::Vector2 getAngles();
	void setAngles(Math::Vector2 angles);
	float getEyeHeight();
	bool isOnGround();
	bool isSneaking();
	Math::Vector3D getMotion();
	void setMotion(Math::Vector3D motion);
};

END_WRAP
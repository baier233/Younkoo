#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class MovementInput :public Object {
public:
	using Object::Object;
	float getMoveForward();
};

END_WRAP
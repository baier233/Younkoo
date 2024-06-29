#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class Entity :public Object {
public:
	using Object::Object;
	// higer version only
	void setGlowing(bool value);
};

END_WRAP
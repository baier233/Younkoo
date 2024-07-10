#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class GameSettings : public Object {
public:
	using Object::Object;
	float getFov();

};
END_WRAP
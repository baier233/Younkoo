#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>

BEGIN_WRAP
class BlockPos :public Object {
public:
	using Object::Object;
	BlockPos(const Math::Vector3D pos);
};

END_WRAP
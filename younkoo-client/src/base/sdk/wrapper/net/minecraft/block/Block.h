#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
BEGIN_WRAP
class BlockState;
class Block :public Object {
public:
	using Object::Object;
	int getID(BlockState& state);
};

END_WRAP
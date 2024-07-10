#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/block/Block.h>

BEGIN_WRAP
class BlockState :public Object {
public:
	using Object::Object;
	Block getBlock();
	bool isAir();
};

END_WRAP
#pragma once
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/Entity.h>
#include <wrapper/net/minecraft/util/BlockPos.h>
BEGIN_WRAP

class MovingObjectPosition :public Object
{
public:
	using Object::Object;
	std::string getType();
	bool isTypeOfBlock();
	bool isTypeOfEntity();
	Entity getEntity();
	BlockPos getBlockPos();

protected:

};

END_WRAP


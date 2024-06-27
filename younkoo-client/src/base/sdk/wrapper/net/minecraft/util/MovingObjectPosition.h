#pragma once
#include "wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h"
#include "wrapper/Object.h"

BEGIN_WRAP

class MovingObjectPosition :public Object
{
public:
	using Object::Object;
	std::string getType();
	bool isTypeOfBlock();
	bool isTypeOfEntity();

protected:

};

END_WRAP


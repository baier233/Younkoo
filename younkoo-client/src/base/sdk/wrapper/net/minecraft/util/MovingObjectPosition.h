#pragma once
#include "wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h"
#include "wrapper/Object.h"

BEGIN_WRAP

class MovingObjectPosition :public Object
{
public:
	using Object::Object;
	bool isTypeOfBlock();


protected:

};

END_WRAP


#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>
BEGIN_WRAP
class Chunk :public Object {
public:
	using Object::Object;
	Math::ChunkPos getPos();
	Math::ChunkPos getMinPos();
	int getHeight();
	int getBottomY();
};

END_WRAP
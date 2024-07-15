#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>
#include <wrapper/net/minecraft/util/Vec3i.h>
BEGIN_WRAP
class BlockPos :public Vec3i {
public:
	using Vec3i::Vec3i;
	BlockPos(const Math::Vector3D pos);
	static BlockPos copy(BlockPos other);
};

END_WRAP
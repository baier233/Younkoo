#pragma once
namespace MathHelper {
	inline float clamp_float(float num, float min, float max)
	{
		return num < min ? min : (num > max ? max : num);
	}
}
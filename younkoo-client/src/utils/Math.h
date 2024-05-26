#pragma once
namespace MathHelper {
	inline float clamp_float(float num, float min, float max)
	{
		return num < min ? min : (num > max ? max : num);
	}
	inline double roundToHalf(double d) {
		return std::round(d * 2) / 2.0;
	}
}
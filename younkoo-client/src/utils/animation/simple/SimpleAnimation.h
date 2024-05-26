#pragma once
#include "../../TimerUtil.hpp"


class SimpleAnimation
{
public:
	SimpleAnimation() {
		this->value = 0.0F;
		this->lastMS = std::chrono::system_clock::now().time_since_epoch().count();
	}
	SimpleAnimation(float var1) :value(var1) {
		this->lastMS = std::chrono::system_clock::now().time_since_epoch().count();
	}

	void setAnimation(float var1, double var2) {
		long var4 = std::chrono::system_clock::now().time_since_epoch().count();
		long var6 = var4 - this->lastMS;
		this->lastMS = var4;
		double var8 = 0.0;
		if (var2 > 28.0) {
			var2 = 28.0;
		}

		if (var2 != 0.0) {
			var8 = (double)(std::abs(var1 - this->value) * 0.35F) / (10.0 / var2);
		}

		this->value = calculateCompensation(var1, this->value, var8, var6);
	}
	inline static float calculateCompensation(float var0, float var1, double var2, long var4) {
		float var6 = var1 - var0;
		double var7 = (double)var4 * (var2 / 50.0);
		if ((double)var6 > var2) {
			if ((double)var1 - var7 > (double)var0) {
				var1 = (float)((double)var1 - var7);
			}
			else {
				var1 = var0;
			}
		}
		else if ((double)var6 < -var2) {
			if ((double)var1 + var7 < (double)var0) {
				var1 = (float)((double)var1 + var7);
			}
			else {
				var1 = var0;
			}
		}
		else if ((double)std::abs(var1 - var0) < 0.03) {
			var1 = var0;
		}

		return var1;
	}
	float getValue() {
		return this->value;
	}
private:
	float value = 0;
	float lastMS = 0;
};


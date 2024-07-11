#pragma once
#include <cmath>
#include <functional>
#include <algorithm>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

class Easing {

private:
	using AnimationFunction = std::function<double(double)>;

	AnimationFunction equationFunction;

public:
	inline Easing(AnimationFunction func) : equationFunction(func) { }

	inline double getEquation(double x) const {
		return equationFunction(x);
	}

	static Easing EASE_IN_BACK;
	static Easing EASE_OUT_BACK;
	static Easing EASE_IN_OUT_BACK;
	static Easing EASE_OUT_CIRC;
	static Easing EASE_IN_CIRC;
	static Easing EASE_IN_OUT_CIRC;
	static Easing LINEAR;
	static Easing SMOOTH_STEP;
	static Easing EASE_IN_OUT_CUBIC;
	static Easing EASE_OUT_ELASTIC;
};

inline Easing Easing::EASE_IN_BACK([](double x) {
	double c1 = 1.70158;
	double c3 = c1 + 1;
	return c3 * x * x * x - c1 * x * x;
	});

inline Easing Easing::EASE_OUT_BACK([](double x) {
	double c1 = 1.70158;
	double c3 = c1 + 1;
	return std::max(0.0, 1 + c3 * std::pow(x - 1, 3) + c1 * std::pow(x - 1, 2));
	});

inline Easing Easing::EASE_IN_OUT_BACK([](double x) {
	double c1 = 1.70158;
	double c2 = c1 * 1.525;
	return x < 0.5
		? (std::pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (std::pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
	});

inline Easing Easing::EASE_OUT_CIRC([](double x) {
	return std::sqrt(1 - std::pow(x - 1, 2));
	});

inline Easing Easing::EASE_IN_CIRC([](double x) {
	return 1 - std::sqrt(1 - std::pow(x, 2));
	});

inline Easing Easing::EASE_IN_OUT_CIRC([](double x) {
	return x < 0.5
		? (1 - std::sqrt(1 - std::pow(2 * x, 2))) / 2
		: (std::sqrt(1 - std::pow(-2 * x + 2, 2)) + 1) / 2;
	});

inline Easing Easing::LINEAR([](double x) {
	return 1 - ((x - 1) * (x - 1));
	});

inline Easing Easing::SMOOTH_STEP([](double x) {
	return -2 * std::pow(x, 3) + (3 * std::pow(x, 2));
	});

inline Easing Easing::EASE_IN_OUT_CUBIC([](double x) {
	return x < 0.5 ? 4 * x * x * x : 1 - std::pow(-2 * x + 2, 3) / 2;
	});

inline Easing Easing::EASE_OUT_ELASTIC([](double x) {
	double c4 = (2 * M_PI) / 3;
	if (x == 0) {
		return 0.0;
	}
	else if (x == 1) {
		return 1.0;
	}
	else {
		return std::pow(2, -10 * x) * std::sin((x * 10 - 0.75) * c4) + 1.0;
	}
	});


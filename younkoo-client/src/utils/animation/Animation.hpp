#pragma once
#include <chrono>
#include <algorithm>
#include "../TimerUtil.hpp"
#include "Easing.hpp"

class Animation {

private:
	TimerUtil time = TimerUtil();
	int duration;
	double targetValue;
	bool state;
	Easing easing;

public:
	Animation(Easing easing, int duration, double targetValue, bool state)
		: duration(duration), targetValue(targetValue), state(state), easing(easing)
	{ }

	Animation(Easing easing, int duration, double targetValue)
		: Animation(easing, duration, targetValue, true)
	{ }

	Animation(Easing easing, int duration)
		: Animation(easing, duration, 1, true)
	{ }

	Animation(int duration)
		: Animation(Easing::LINEAR, duration, 1, true)
	{ }

	inline bool finished(bool state, float per) const {
		return isFinishedPer(per) && this->state == state;
	}

	inline bool finished(bool state) const { return finished(state, 1.f); }
	inline bool isStarted(float per) const { return finished(true, per); }
	inline bool isEnded(float per) const { return finished(false, per); }
	inline bool isStarted() const { return isStarted(1.f); }
	inline bool isEnded() const { return isEnded(1.f); }

	inline bool isFinishedPer(float per) const {
		return time.hasTimeElapsed(duration * per);
	}

	inline Animation setState(bool state) {
		if (this->state != state) {
			this->state = state;
			time.setTime(std::chrono::system_clock::now().time_since_epoch().count() - (duration - std::min(duration, (int)time.getTime())));
		}
		return *this;
	}

	inline double getOutput() const {
		if (state) {
			if (isFinishedPer(1.f)) {
				return targetValue;
			}
			return easing.getEquation(time.getTime() / (double)duration) * targetValue;
		}
		else {
			if (isFinishedPer(1.f)) {
				return 0.0;
			}
			if (&this->easing == &Easing::LINEAR) {
				return (1 - easing.getEquation(time.getTime() / (double)duration)) * targetValue;
			}
			double revTime = std::min(duration, std::max(0, duration - (int)time.getTime()));
			return easing.getEquation(revTime / (double)duration) * targetValue;
		}
	}

};

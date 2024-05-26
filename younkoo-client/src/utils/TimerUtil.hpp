#pragma once
#include <chrono>

class TimerUtil {

private:
	long lastMS = std::chrono::system_clock::now().time_since_epoch().count();

public:
	void reset() {
		lastMS = std::chrono::system_clock::now().time_since_epoch().count();
	}

	bool hasTimeElapsed(long time, bool reset) {
		if (std::chrono::system_clock::now().time_since_epoch().count() - lastMS > time) {
			if (reset) this->reset();
			return true;
		}
		return false;
	}

	bool hasTimeElapsedE(long time) const {
		return std::chrono::system_clock::now().time_since_epoch().count() - lastMS >= time;
	}

	bool hasTimeElapsed(long time) const {
		return std::chrono::system_clock::now().time_since_epoch().count() - lastMS > time;
	}

	bool hasTimeElapsed(double time) const {
		return hasTimeElapsed((long)time);
	}

	long getTime() const {
		return std::chrono::system_clock::now().time_since_epoch().count() - lastMS;
	}

	void setTime(long time) {
		lastMS = time;
	}

};
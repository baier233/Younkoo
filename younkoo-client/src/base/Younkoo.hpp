#pragma once
#include "../utils/Singleton.hpp"
#include <atomic>
#include "event/event_bus.hpp"

class Younkoo : public Singleton<Younkoo> {

public:
	Younkoo();
	bool setup();
	bool shutdown();
	std::atomic<bool> shouldShutDown = false;
	dp::event_bus EventBus;
};


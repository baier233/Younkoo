#pragma once
#include "../utils/Singleton.hpp"
#include "event/EventBus.hpp"
#include "render/gui/input/IOEvents.h"

#include <atomic>
#include <memory>

class Younkoo : public Singleton<Younkoo> {

public:
	Younkoo();
	bool setup();
	bool shutdown();
	std::atomic<bool> shouldShutDown = false;
	std::unique_ptr<dp::EventBus> EventBus = std::make_unique<dp::EventBus>();
};


﻿#pragma once
#include "../utils/Singleton.hpp"
#include <atomic>
#include "event/EventBus.hpp"
#include <memory>

class Younkoo : public Singleton<Younkoo> {

public:
	Younkoo();
	bool setup();
	bool shutdown();
	std::atomic<bool> shouldShutDown = false;
	std::unique_ptr<dp::EventBus> EventBus = std::make_unique<dp::EventBus>();
};


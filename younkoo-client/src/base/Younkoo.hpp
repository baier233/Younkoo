#pragma once
#include "../utils/Singleton.hpp"
#include <atomic>


class Younkoo : public Singleton<Younkoo> {
protected:
	NON_COPYABLE(Younkoo);
	DEFAULT_DTOR(Younkoo);
public:
	Younkoo();
	bool setup();
	bool shutdown();
	std::atomic<bool> shouldShutDown = false;
};


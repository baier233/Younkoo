#pragma once
#include <utils/Singleton.hpp>
#include <vector>
#include <memory>

#include "AbstractHook.h"
class HookManager :public Singleton<HookManager>
{
public:
	void setup();
	void clean();
	void handle();
private:
	std::vector<std::shared_ptr<AbstractHook>> hooks;
};


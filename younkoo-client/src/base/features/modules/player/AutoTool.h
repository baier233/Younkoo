#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <base/event/Events.h>

class AutoTool : public AbstractModule
{
public:
	static AutoTool& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	AutoTool();
private:
};

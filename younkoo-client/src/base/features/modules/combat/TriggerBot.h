#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
class TriggerBot : public AbstractModule
{
public:
	static TriggerBot& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	DEFINE_FLOAT_VALUE(maxCpsValue, "Max Cps", "Left Mouse Maximum Clicks per Second. ", 14, 0, 20);
	DEFINE_FLOAT_VALUE(minCpsValue, "Min Cps", "Left Mouse Minmum Clicks per Second. ", 8, 0, 20);
	TriggerBot();
};

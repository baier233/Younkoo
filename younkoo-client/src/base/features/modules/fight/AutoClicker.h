#pragma once
#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
class AutoClicker : public AbstractModule
{
public:
	static AutoClicker& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
private:

	FloatValue* leftMaxCpsValue = new FloatValue("Max CPS", 14, 0, 20);
	FloatValue* leftMinCpsValue = new FloatValue("Min CPS", 8, 0, 20);
	FloatValue* blockHitChanceValue = new FloatValue("BlockHitChance", 3, 1, 50);
	BoolValue* ignoreBlocksValue = new BoolValue("Ignore Block", true);
	BoolValue* blockHitValue = new BoolValue("BlockHit", false);
	BoolValue* inInventoryValue = new BoolValue("In Inventory", false);
	AutoClicker();
};

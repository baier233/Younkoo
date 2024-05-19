#pragma once
#include "../AbstractModule.h"

class RClick :public AbstractModule {
public:


	static RClick& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	FloatValue* rightMaxCpsValue = new FloatValue("Max CPS", 14.f, 1, 20);
	FloatValue* rightMinCpsValue = new FloatValue("Min CPS", 8.f, 1, 20);
	BoolValue* blocksOnlyValue = new BoolValue("Blocks Only", true);
private:
	RClick();
};
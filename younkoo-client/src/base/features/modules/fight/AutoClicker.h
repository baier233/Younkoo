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

	AutoClicker();
};

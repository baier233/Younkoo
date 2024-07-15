#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
class Jamming : public AbstractModule
{
public:
	static Jamming& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	Jamming();
};

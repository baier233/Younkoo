#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class Eagle : public AbstractModule
{
public:
	static Eagle& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
protected:
	Eagle();
private:
};

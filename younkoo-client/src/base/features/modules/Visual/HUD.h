#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include <GL/glew.h>
#include <nanovg.h>
class HUD : public AbstractModule
{
public:
	static HUD* getInstance();
	void onEnable();
	void onDisable();
	void onRender(const EventRender2D& e);
private:

	HUD();
	DefaultDeconstructor(HUD);
	NoMoveConstructor(HUD);
	NoCopyConstructor(HUD);
	NoAssignOperator(HUD);
};

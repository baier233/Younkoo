#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
class ESP : public AbstractModule
{
public:
	static ESP& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	void onRender3D(const EventRender3D& e);
private:

	ESP();
};

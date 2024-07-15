#pragma once

#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
class NameTag : public AbstractModule
{
public:
	static NameTag& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	void onRender3D(const EventRender3D& e);
protected:
	DEFINE_FLOAT_VALUE(fontSizeValue, "Size", "Nametag Text Size..", 20.f, 1.0f, 30.0f);
private:

	NameTag();
};

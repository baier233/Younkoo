#include "CommonData.h"
#include <base/features/modules/ModuleManager.h>
#include <base/Younkoo.hpp>

#include <wrapper/net/minecraft/client/Minecraft.h>

CommonData::CommonData()
{
	REGISTER_EVENT(EventRender3D, CommonData::onRender3D);
	renderPos = {};
	renderPartialTicks = 0;
	fov = 0;
	projection = {};
	modelView = {};
}
void CommonData::onRender3D(const EventRender3D& e)
{
	renderPos = e.CAMERA_POS;
	renderPartialTicks = e.TICK_DELTA;
	projection = e.PROJECTION_MATRIX;
	modelView = e.MODLEVIEW_MATRIX;
}

void CommonData::onUpdate()
{
	this->fov = Wrapper::Minecraft::getMinecraft().getSettings().getFov();
}




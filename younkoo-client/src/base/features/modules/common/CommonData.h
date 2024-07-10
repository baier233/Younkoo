#pragma once

#include <utils/Singleton.hpp>
#include <base/event/Events.h>
#include <utils/Math.h>

class CommonData : public Singleton<CommonData>
{
public:
	void onRender3D(const EventRender3D& e);
	void onUpdate();
	Math::Matrix projection;
	Math::Matrix modelView;
	Math::Vector3D renderPos;
	float renderPartialTicks;
	float fov;


	CommonData();
protected:
private:

};

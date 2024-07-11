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
	Math::Vector3D cameraPos;

	float renderPartialTicks;
	float eyeHeight;
	float fov;

	std::array<int, 4>viewport;


	CommonData();
protected:
private:

};

#pragma once
#include "../render/nano/NanovgHelper.hpp"
#include <utils/types/Maths.hpp>
class EventRender2D
{
public:
	NVGcontext*& vg;
	int winWidth, winHeight;
};

class EventRender3D
{
public:
	Math::Matrix PROJECTION_MATRIX;
	Math::Matrix MODELVIEW_MATRIX;
	Math::Vector3D CAMERA_POS;
	float TICK_DELTA;
	long START_TIME = 0;
	double GUI_SCALE = 0;
};
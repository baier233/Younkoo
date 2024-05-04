#pragma once
#include "../render/nano/NanovgHelper.hpp"

class EventRender2D
{
public:
	NVGcontext*& vg;
	int winWidth, winHeight;
};
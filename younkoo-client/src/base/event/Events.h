#pragma once
#include "../render/nano/NanovgHelper.hpp"

struct EventRender2D
{
	NVGcontext*& vg;
	int winWidth, winHeight;
};
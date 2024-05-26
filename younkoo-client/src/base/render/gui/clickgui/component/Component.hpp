#pragma once
#include "../../../nano/NanovgHelper.hpp"
class Component
{
public:
	virtual void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) {}

};


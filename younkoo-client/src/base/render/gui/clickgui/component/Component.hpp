#pragma once
#include <deque>

#include "../../../nano/NanovgHelper.hpp"
class Component
{
public:
	virtual void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) {}
protected:
	static std::deque<std::function<void()>> blur_render_queue;
};


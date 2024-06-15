#pragma once
#include <deque>
#include <functional>

#include "../../../nano/NanovgHelper.hpp"
class Component
{
public:
	virtual void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) {}
protected:
	static inline std::deque<std::function<void()>> blur_render_queue;
};


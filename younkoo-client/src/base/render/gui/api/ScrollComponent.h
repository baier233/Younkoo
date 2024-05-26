#pragma once
#include "../../nano/NanovgHelper.hpp"
#include "../../../../utils/animation/simple/SimpleAnimation.h"
class ScrollComponent
{
public:
	void renderScrollBar(NVGcontext* vg, float x, float y, float maxHeight) {
		using namespace NanoVGHelper;
		float percentage = scroll / max;;
		float scrollBarHeight = maxHeight - ((max / (max - maxHeight)) * maxHeight);

		scrollingIsAllowed = scrollBarHeight < maxHeight;
		if (!scrollingIsAllowed) return;

		float scrollY = y + maxHeight * percentage - scrollBarHeight * percentage;

		renderShadow(vg, x, scrollY, 1, scrollBarHeight, 1.f, 4);
		drawRoundedRect(vg, x, scrollY, 1, scrollBarHeight, rgbaToColor(220, 220, 220, 60), 1.f
		);

	}

	void animate() {
		animation.setAnimation(target, 20);
		scroll = animation.getValue();
	}
	float target, scroll, max = 25;
	SimpleAnimation animation = SimpleAnimation();
	bool scrollingIsAllowed = false;
};


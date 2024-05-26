#pragma once
#include <algorithm>

#include "../Component.hpp"
#include "ModuleComponent.h"
#include "../../../api/ScrollComponent.h"


class PanelComponent : public Component
{
public:
	PanelComponent(Category category);
	void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) override;

	float x = 0, y = 0;
	const float width = 145;
	float height = 0;
private:
	Category category;
	std::list<ModuleComponent> components;
	ScrollComponent scrollComponent = ScrollComponent();
};


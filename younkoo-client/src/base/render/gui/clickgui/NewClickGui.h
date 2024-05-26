#pragma once
#include "../src/utils/Animation.hpp"
#include "../../nano/NanovgHelper.hpp"

#include "component/impl/PanelComponent.h"
#include "../../../features/modules/AbstractModule.h"
class NewClickGui
{
public:
	NewClickGui() : openAnim(Easing::EASE_OUT_BACK, 300) {
		auto categories = { Category::COMBAT, Category::MOVEMENT, Category::PLAYER, Category::MISC, Category::VISUAL };
		std::transform(
			categories.begin(),
			categories.end(),
			std::back_inserter(components),
			[](const Category& category) {
				return PanelComponent(category);
			}
		);
	}
	void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) {
		using namespace NanoVGHelper;
		float output = static_cast<float>(openAnim.getOutput());
		startScale(vg, static_cast<float>(winSize.first / 2), static_cast<float>(winSize.second / 2), output);
		float offsetX = 0.f;
		for (auto& component : components)
		{
			static float spacing = 20;
			component.x = spacing + offsetX;
			component.y = spacing + 10;

			component.drawScreen(vg, winSize);

			offsetX += component.width + spacing;
		}
		stopScale();

	}
private:
	const Animation openAnim;
	std::list<PanelComponent> components;
};


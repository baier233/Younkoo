#pragma once

#include "../src/utils/Animation.hpp"
#include "../../nano/NanovgHelper.hpp"

#include "component/impl/PanelComponent.h"
#include "../../../features/modules/AbstractModule.h"
#include "../../../../utils/Math.h"
class NewClickGui : public Component
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
		if (openAnim.isEnded()) return;


		using namespace NanoVGHelper;
		float output = static_cast<float>(openAnim.getOutput());
		startScale(vg, static_cast<float>(winSize.first / 2), static_cast<float>(winSize.second / 2), output);
		blur_render_queue.push_back([vg, winSize, output] {
			startScale(vg, static_cast<float>(winSize.first / 2), static_cast<float>(winSize.second / 2), output);
			alpha(vg, MathHelper::clamp_float(output, 0.0f, 1.0f));
			});
		float offsetX = 0.f;
		for (auto& component : components)
		{
			static float spacing = 20;
			component.x = spacing + offsetX;
			component.y = spacing + 10;

			component.drawScreen(vg, winSize);

			offsetX += component.width + spacing;
		}
		blur_render_queue.push_back([] {
			stopScale();
			});
		stopScale();

	}
private:
	const Animation openAnim;
	std::list<PanelComponent> components;
};


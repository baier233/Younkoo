#include "PanelComponent.h"

#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"
static constexpr float TOP_BAR_HEIGHT = 28.f;

PanelComponent::PanelComponent(Category category) {
	this->category = category;

	auto mods = ModuleManager::get().getMods();
	std::transform(
		mods.begin(),
		mods.end(),
		std::back_inserter(components),
		[](const HMOD& mod) {
			return ModuleComponent(ToBaseModule(mod));
		}
	);
}


void PanelComponent::drawScreen(NVGcontext* vg, std::pair<int, int> winSize)
{
	using namespace NanoVGHelper;
	blur_render_queue.push_back([vg, this] {
		drawRoundedRect(vg, x, y, width, height, rgbaToColor(0, 0, 0, 255), 7.f);
		});

	static float rectHeight = 20.f;
	float contentY = y + TOP_BAR_HEIGHT;
	float contentHeight = height - TOP_BAR_HEIGHT;
	scissorHelper.scissor(vg, x, contentY, width, contentHeight);
}

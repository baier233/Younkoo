#include "PanelComponent.h"

#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"
#include "../../../../../../utils/Math.h"
#include <cmath>
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
std::array<std::wstring, 5> ICONS{ L"a",L"b",L"c",L"d",L"e" };
#include <utils/Wstr.h>
void PanelComponent::drawScreen(NVGcontext* vg, std::pair<int, int> winSize)
{
	using namespace NanoVGHelper;
	blur_render_queue.push_back([vg, this] {
		drawRoundedRect(vg, x, y, width, height, rgbaToColor(0, 0, 0, 255), 7.f);
		});

	renderShadow(vg, x, y, width, height, 7.f, 8);
	drawRoundedRect(vg, x, y, width, height, rgbaToColor(0, 0, 0, 200), 7.f);

	NanoVGHelper::nvgTextW(vg, ICONS[static_cast<int>(category)], x + 6.f,
		y + 8.f, NanoVGHelper::fontClickguiIcon, 32, NanoVGHelper::colorToRGBA(-1));

	NanoVGHelper::nvgTextW(vg, wstr::toString(getCategoryName(category)), x + 45.f, y + 12.f,
		NanoVGHelper::fontRobotoBold, 20, NanoVGHelper::colorToRGBA(-1));

	static float rectHeight = 20.f;
	float contentY = y + TOP_BAR_HEIGHT;
	float contentHeight = height - TOP_BAR_HEIGHT;
	scissorHelper.save();
	auto s = scissorHelper.scissor(vg, x, contentY, width, contentHeight);
	float componentHeight = 0.f;
	for (auto& component : components) {
		component.x = x;
		component.y = ((float)(contentY + componentHeight + MathHelper::roundToHalf(scrollComponent.scroll)));
		component.width = (width);
		component.height = (rectHeight);
		component.drawScreen(vg, winSize);

		componentHeight += component.height + component.expandHeight;
	}
	float maxHeight = 500.f;

	height = std::min(TOP_BAR_HEIGHT + componentHeight, maxHeight);

	scrollComponent.max = (-(componentHeight - contentHeight));

	if (componentHeight > maxHeight) {
		float scrollPadding = 8.f;
		scrollComponent.renderScrollBar(vg, x + width - 3, contentY + scrollPadding
			, contentHeight - scrollPadding * 2);
		scrollComponent.max = (-(componentHeight - contentHeight));
		//    scrollComponent.reset();
	}

	scissorHelper.restore(vg);
	scissorHelper.resetScissor(vg, s);
}

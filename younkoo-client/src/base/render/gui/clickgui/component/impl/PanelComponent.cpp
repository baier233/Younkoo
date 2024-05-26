#include "PanelComponent.h"

#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"
#include "../../../../../../utils/Math.h"
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

	renderShadow(vg, x, y, width, height, 7.f, 8);
	drawRoundedRect(vg, x, y, width, height, rgbaToColor(0, 0, 0, 200), 7.f);

	/*TODO
	// title
		NanoVGFontRenderer font22 = Fonts.ROBOTO_BOLD.getFont(22);

		NanoVGFontRenderer icon = Fonts.CLICKGUI_ICON.getFont(32);

		icon.drawString(ICONS[category.ordinal()], x + 6f,
				y + 8f, -1);

		font22.drawString(category.getName(), x + 28f, y + 10f, -1);
	*/


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
	scissorHelper.restore(vg);
	scissorHelper.resetScissor(vg, s);
}

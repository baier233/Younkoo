#include "PanelComponent.h"

#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"

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

}

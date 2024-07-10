#include "HUD.h"
#include "base/render/hooks/WndProcHook.hpp"
#include "base/GitInfo.h"

#include "../ModuleManager.h"
HUD::HUD() :AbstractModule(xorstr_("HUD"), Category::VISUAL, 'K')
{
	REGISTER_EVENT(EventRender2D, HUD::onRender);
	//ModuleManager::get().registrations.push_back(Younkoo::get().EventBus->register_handler<EventRender2D>(this, &HUD::onRender));

	this->setToggle(true);
}


HUD& HUD::getInstance()
{
	static HUD instance = HUD();
	return instance;
}

void HUD::onEnable()
{
}

void HUD::onDisable()
{
}

void HUD::onUpdate()
{
}

void HUD::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static int x2 = e.winWidth / static_cast<float>(2);
	if (WndProcHook::RESIZED)
	{
		x2 = e.winWidth / static_cast<float>(2);
	}
	using namespace NanoVGHelper;

	float x = 5;
	float y = 5;
	static std::wstring watermark(L"Akarin Client");
	auto bounds = nvgTextBoundsW(e.vg, watermark, NanoVGHelper::fontHarmony, 30);
	nvgTextW(e.vg, watermark, x2 - bounds.first / static_cast <float>(2), y, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
	auto mods = ModuleManager::get().getMods();
	for (auto iter = mods.cbegin(); iter < mods.cend(); iter++) {
		auto sbmod = reinterpret_cast<AbstractModule*>(*iter);
		if (sbmod && sbmod->getToggle())
		{
			auto sbname1 = sbmod->getName();
			std::wstring sbname(sbname1.begin(), sbname1.end());
			nvgTextW(e.vg, sbname, x, y, NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255));
			std::pair<float, float> bounds = nvgTextBoundsW(e.vg, sbname, NanoVGHelper::fontHarmony, 20);
			y += bounds.second;
		}

	}
}

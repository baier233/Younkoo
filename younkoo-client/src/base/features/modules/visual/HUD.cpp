#include "HUD.h"

HUD& HUD::getInstance()
{
	static HUD instance = HUD();
	return instance;
}

void HUD::onEnable()
{
	std::cout << "onEnable" << std::endl;
	//const auto OnRenderHandle = Younkoo::get().EventBus.register_handler<EventRender2D>([](const EventRender2D& e) {
	//	static std::wstring watermark(L"Younkoo Client");
	//	static float x = e.winWidth / static_cast<float>(2), y = 100;
	//	float bounds[4] = { 0 };
	//	using namespace NanoVGHelper;
	//	nvgFontSize(e.vg, 60);
	//	nvgTextAlign(e.vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	//	nvgFontFaceId(e.vg, NanoVGHelper::fontHarmony);
	//	nvgTextBoundsW(e.vg, x, y, watermark, bounds);
	//	float w = bounds[2] - bounds[0];
	//	float h = bounds[3] - bounds[1];
	//	w *= 1.5;
	//	h *= 1.5;

	//	nvgBeginPath(e.vg);
	//	NVGpaint shadowPaint = nvgBoxGradient(e.vg, x - w / 2, y - h / 2, w, h, 10, 20, nvgRGBA(0, 0, 0, 128), nvgRGBA(0, 0, 0, 0));
	//	nvgFillPaint(e.vg, shadowPaint);
	//	nvgRect(e.vg, x - w / 2, y - h / 2, w, h);
	//	nvgFill(e.vg);

	//	nvgBeginPath(e.vg);
	//	nvgFillColor(e.vg, nvgRGBA(255, 255, 255, 190));
	//	nvgTextW(e.vg, x + 15, y, watermark);
	//	std::cout << "call" << std::endl;
	//	});
}

void HUD::onDisable()
{
	std::cout << "onDisable" << std::endl;
}

void HUD::onUpdate()
{
	//std::cout << "HUD onUpdate" << std::endl;
}

void HUD::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static float x2 = e.winWidth / static_cast<float>(2);
	using namespace NanoVGHelper;

	float x = 5;
	float y = 5;
	static std::wstring watermark(L"Younkoo Client");
	nvgTextW(e.vg, watermark, x2, y, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
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
	 
	/*
	nvgBeginPath(e.vg);
	NVGpaint shadowPaint = nvgBoxGradient(e.vg, x - w / 2, y - h / 2, w, h, 10, 20, nvgRGBA(0, 0, 0, 128), nvgRGBA(0, 0, 0, 0));
	nvgFillPaint(e.vg, shadowPaint);
	nvgRect(e.vg, x - w / 2, y - h / 2, w, h);
	nvgFill(e.vg);
	*/
	//nvgRect(e.vg, 10, 10, 10, 10, nvgRGBA(255, 255, 255, 200));

}
#include "../ModuleManager.h"
HUD::HUD() :AbstractModule("HUD", Category::VISUAL, 'K')
{
	ModuleManager::get().registrations.push_back(Younkoo::get().EventBus->register_handler<EventRender2D>(this, &HUD::onRender));

	this->setToggle(true);
}

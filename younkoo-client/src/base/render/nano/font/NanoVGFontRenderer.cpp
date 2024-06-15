#include "NanoVGFontRenderer.h"


#include <atomic>


void NanoFontRender::drawStringWithFade(NVGcontext* vg, const std::string& text, double x, double y, float alpha, bool shadow)
{
	for (auto c : text)
	{
		auto opacity = std::min(1.f, std::max(0.f, alpha * 0.65f));
		auto color = NanoVGHelper::rgbaToColor(0, 0, 0, opacity);
	}
}

float NanoFontRender::getStringWidth(NVGcontext* vg, std::string text)
{
	float bounds[4]{};
	nvgFontSize(vg, size);
	nvgFontFace(vg, name.c_str());


	return 0.0f;
}

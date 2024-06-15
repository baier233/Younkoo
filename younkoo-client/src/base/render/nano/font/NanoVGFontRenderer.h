#pragma once
#include <string>
#include "../NanovgHelper.hpp"

class NanoFontRender {
public:
	NanoFontRender(const std::string& name, unsigned int size) : name(name), size(size) {};
	void drawStringWithFade(NVGcontext* vg, const std::string& text, double x, double y, float alpha, bool shadow);
	float getStringWidth(NVGcontext* vg, std::string text);
private:
	std::string name;
	unsigned int size;
};
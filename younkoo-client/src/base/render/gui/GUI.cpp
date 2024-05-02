#include "GUI.h"

#include "nanovg.h"
#include "../nano/NanovgHelper.hpp"
#include "input/Context.hpp"
#include <iostream>


static void drawWindow(NVGcontext* vg, const char* title, float x, float y, float w, float h)
{
	float cornerRadius = 3.0f;
	NVGpaint shadowPaint;
	NVGpaint headerPaint;

	nvgSave(vg);
	//	nvgClearState(vg);

		// Window
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, w, h, cornerRadius);
	nvgFillColor(vg, nvgRGBA(28, 30, 34, 192));
	//	nvgFillColor(vg, nvgRGBA(0,0,0,128));
	nvgFill(vg);

	// Drop shadow
	shadowPaint = nvgBoxGradient(vg, x, y + 2, w, h, cornerRadius * 2, 10, nvgRGBA(0, 0, 0, 128), nvgRGBA(0, 0, 0, 0));
	nvgBeginPath(vg);
	nvgRect(vg, x - 10, y - 10, w + 20, h + 30);
	nvgRoundedRect(vg, x, y, w, h, cornerRadius);
	nvgPathWinding(vg, NVG_HOLE);
	nvgFillPaint(vg, shadowPaint);
	nvgFill(vg);

	// Header
	headerPaint = nvgLinearGradient(vg, x, y, x, y + 15, nvgRGBA(255, 255, 255, 8), nvgRGBA(0, 0, 0, 16));
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x + 1, y + 1, w - 2, 30, cornerRadius - 1);
	nvgFillPaint(vg, headerPaint);
	nvgFill(vg);
	nvgBeginPath(vg);
	nvgMoveTo(vg, x + 0.5f, y + 0.5f + 30);
	nvgLineTo(vg, x + 0.5f + w - 1, y + 0.5f + 30);
	nvgStrokeColor(vg, nvgRGBA(0, 0, 0, 32));
	nvgStroke(vg);

	nvgFontSize(vg, 15.0f);
	nvgFontFaceId(vg, NanoVGHelper::fontHarmony);
	nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

	nvgFontBlur(vg, 2);
	nvgFillColor(vg, nvgRGBA(0, 0, 0, 128));
	nvgText(vg, x + w / 2, y + 16 + 1, title, NULL);

	nvgFontBlur(vg, 0);
	nvgFillColor(vg, nvgRGBA(220, 220, 220, 160));
	nvgText(vg, x + w / 2, y + 16, title, NULL);

	nvgRestore(vg);
}


void YounkooGui::drawScreen(NVGcontext* vg, int mouseX, int mouseY)
{
	static auto posX = context.ScreenWidth / static_cast<float>(2) - 200, posY = context.ScreenHeight / static_cast<float>(2) - 300;
	static double width = 400., height = 600.;
	bool isHovered = context.MouseInZone({ posX,posY }, { width, height / 5 });
	static bool isDrag = false;
	if (context.IsMousePressed(0))
	{
		if (isHovered) {
			isDrag = true;
		}

	}
	else {
		isDrag = false;
	}
	static double offsetX = 0, offsetY = 0;
	if (isDrag)
	{
		if (offsetX == 0 && offsetY == 0)
		{
			offsetX = mouseX - posX;
			offsetY = mouseY - posY;
		}

		posX = mouseX - offsetX;
		posY = mouseY - offsetY;
	}
	else {
		offsetX = 0;
		offsetY = 0;
	}
	drawWindow(vg, "Younkoo", posX, posY, width, height);
}

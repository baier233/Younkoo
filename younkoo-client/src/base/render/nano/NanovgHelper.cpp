#include "NanovgHelper.hpp"

#include <GL\glew.h>
#include "wrapper\gl3.h"
#include "wrapper\gl2.h"
//#include "nanovg_gl_utils.h"
#include <iostream>

void error_callback(int error, const char* description)
{
	std::cerr << "CALLBACK Error: " << description << std::endl;
}
#include "../resources/fonts/harmony_sc_light.h"
#include "../resources/fonts/harmony_sc_regular.h"

#include "../Renderer.hpp"

bool NanoVGHelper::InitContext(HWND window2Attach)
{
	if (Context) return true;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	if (Renderer::get().renderContext.ClassName == "LWJGL") {
		std::cout << "OpenGL Major Vesrion : 2" << std::endl;
		Context = gl2::init();
	}
	else {
		std::cout << "OpenGL Major Vesrion : 3" << std::endl;
		Context = gl3::init();
	}

	//fontHarmony = nvgCreateFont(Context, "raleway", "C:\\Users\\Baier\\AppData\\Local\\Microsoft\\Windows\\Fonts\\HarmonyOS_Sans_SC_Regular.ttf");
	fontHarmony = nvgCreateFontMem(Context, "harmony_sans_regular", harmony_sc_regular, harmony_sc_regular_size, 0);

	nvgShapeAntiAlias(Context, 1);
	return Context != nullptr;
}

bool NanoVGHelper::DeleteContext()
{
	//释放nvg 上下文时.font也会被释放。
	if (Renderer::get().renderContext.ClassName == "LWJGL") {
		gl2::clean(Context);
	}
	else {
		gl3::clean(Context);
	}
	Context = nullptr;
	return true;
}
void NanoVGHelper::renderGlow(NVGcontext* vg, float x, float y, float width, float height, float radius, float offset, int color)
{
	auto nvgColor = nvgFillColorEx(vg, color);
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, width, height, radius);
	nvgStrokeWidth(vg, offset);
	nvgStrokeColor(vg, nvgColor);
	nvgStroke(vg);
}
static std::string Wide2Utf8(const std::wstring& str) {
	int sizeRequired = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	std::string utf8Str(sizeRequired, 0);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8Str[0], sizeRequired, NULL, NULL);
	return utf8Str;
}
void NanoVGHelper::drawRect(NVGcontext* vg, float x, float y, float width, float height, int color)
{
	nvgBeginPath(vg);
	nvgRect(vg, x, y, width, height);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgFill(vg);
}
void NanoVGHelper::drawHollowRoundRect(NVGcontext* vg, float x, float y, float width, float height, int color, float radius, float thickness)
{
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x + thickness, y + thickness, width - thickness, height - thickness, radius);
	nvgStrokeWidth(vg, thickness + 0.5f);
	nvgPathWinding(vg, NVG_HOLE);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgStrokeColor(vg, nvgColor);
	nvgStroke(vg);
}
void NanoVGHelper::drawRoundedRectVaried(NVGcontext* vg, float x, float y, float width, float height, int color, float radiusTL, float radiusTR, float radiusBR, float radiusBL)
{
	nvgBeginPath(vg);
	nvgRoundedRectVarying(vg, x, y, width, height, radiusTL, radiusTR, radiusBR, radiusBL);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgFill(vg);
}
void NanoVGHelper::drawGradientRoundedRect(NVGcontext* vg, float x, float y, float width, float height, int color, int color2, float radius, GradientDirection direction)
{
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, width, height, radius);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	NVGcolor nvgColor2 = nvgFillColorEx(vg, color2);
	auto pts = getValues(x, y, width, height, direction);
	nvgFillPaint(vg, nvgLinearGradient(vg, pts[0], pts[1], pts[2], pts[3], nvgColor, nvgColor2));
	nvgFill(vg);
}
void NanoVGHelper::nvgTextW(NVGcontext* vg, const std::wstring& str, int x, int y, int font, int size, NVGcolor col, int alight)
{
	nvgBeginPath(vg);
	nvgFontSize(vg, size);
	nvgFontFaceId(vg, font);
	if (alight)
	{
		nvgTextAlign(vg, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
	}
	auto utf8Str = Wide2Utf8(str);
	nvgFillColor(vg, col);
	nvgText(vg, x, y, utf8Str.c_str(), utf8Str.c_str() + utf8Str.size());
}

void NanoVGHelper::nvgRect(NVGcontext* vg, float x, float y, float width, float height, NVGcolor col)
{
	nvgBeginPath(vg);
	nvgRect(vg, x, y, width, height);
	nvgFillColor(vg, col);
	nvgFill(vg);
}

std::pair<float, float> NanoVGHelper::nvgTextBoundsW(NVGcontext* vg, const std::wstring& str, int font, int size)
{
	float bounds[4] = { 0 };
	nvgFontSize(vg, size);
	nvgFontFaceId(vg, font);
	nvgTextBoundsW(vg, 0, 0, str, bounds);
	float w = bounds[2] - bounds[0];
	float h = bounds[3] - bounds[1];
	return std::make_pair(w, h);
}

void NanoVGHelper::nvgTextBoundsW(NVGcontext* vg, int x, int y, const std::wstring& str, float bounds[])
{
	auto utf8Str = Wide2Utf8(str);
	nvgTextBounds(vg, x, y, utf8Str.c_str(), utf8Str.c_str() + utf8Str.size(), bounds);
}

void NanoVGHelper::drawRoundedRect(NVGcontext* vg, float x, float y, float width, float height, int color, float radius)
{
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, width, height, radius);
	nvgFillColorEx(vg, color);
	nvgFill(vg);
}

void NanoVGHelper::drawLine(NVGcontext* vg, float x, float y, float endX, float endY, float width, int color)
{
	nvgBeginPath(vg);
	nvgMoveTo(vg, x, y);
	nvgLineTo(vg, endX, endY);
	auto nvgColor = nvgFillColorEx(vg, color);
	nvgStrokeColor(vg, nvgColor);
	nvgStrokeWidth(vg, width);
	nvgStroke(vg);
}

void NanoVGHelper::drawDropShadow(NVGcontext* vg, float x, float y, float w, float h, float blur, float spread, float cornerRadius)
{
	NVGcolor firstColor{};
	NVGcolor secondColor{};
	NVGpaint shadowPaint{};
	fillNVGColorWithRGBA(0, 0, 0, 0.5f, firstColor); // filling allocated memory
	fillNVGColorWithRGBA(0, 0, 0, 0, secondColor); // filling allocated memory

	// creating gradient and put it to shadowPaint
	shadowPaint = nvgBoxGradient(vg, x - spread, y - spread, w + 2 * spread, h + 2 * spread, cornerRadius + spread, blur, firstColor, secondColor);
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x - spread - blur, y - spread - blur, w + 2 * spread + 2 * blur, h + 2 * spread + 2 * blur, cornerRadius + spread);
	nvgRoundedRect(vg, x, y, w, h, cornerRadius);
	nvgPathWinding(vg, NVG_HOLE);
	nvgFillPaint(vg, shadowPaint);
	nvgFill(vg);
}

NVGcolor NanoVGHelper::nvgFillColorEx(NVGcontext* vg, int color) {
	auto nvgColor = nvgRGBA((byte)(color >> 16 & 0xFF), (byte)(color >> 8 & 0xFF), (byte)(color & 0xFF), (byte)(color >> 24 & 0xFF));
	nvgFillColor(vg, nvgColor);
	return nvgColor;
}

void NanoVGHelper::drawHollowEllipse(NVGcontext* vg, float x, float y, float radiusX, float radiusY, int color, float thickness)
{
	nvgBeginPath(vg);
	nvgEllipse(vg, x, y, radiusX, radiusY);
	nvgStrokeWidth(vg, thickness + 0.5f);
	nvgPathWinding(vg, NVG_HOLE);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgStrokeColor(vg, nvgColor);
	nvgStroke(vg);
}

void NanoVGHelper::drawEllipse(NVGcontext* vg, float x, float y, float radiusX, float radiusY, int color)
{
	nvgBeginPath(vg);
	nvgEllipse(vg, x, y, radiusX, radiusY);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgFill(vg);
}

void NanoVGHelper::drawCircle(NVGcontext* vg, float x, float y, float radius, int color)
{
	nvgBeginPath(vg);
	nvgCircle(vg, x, y, radius);
	NVGcolor nvgColor = nvgFillColorEx(vg, color);
	nvgFill(vg);
}

void NanoVGHelper::drawHSBBox(NVGcontext* vg, float x, float y, float width, float height, int colorTarget)
{
	drawRoundedRect(vg, x, y, width, height, colorTarget, 8.f);

	NVGpaint bg{};
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, width, height, 8.f);
	NVGcolor nvgColor = nvgFillColorEx(vg, -1);
	NVGcolor nvgColor2 = nvgFillColorEx(vg, 0);
	nvgFillPaint(vg, nvgLinearGradient(vg, x, y, x + width, y, nvgColor, nvgColor2));
	nvgFill(vg);

	nvgBeginPath(vg);
	nvgRoundedRect(vg, x, y, width, height, 8.f);
	NVGcolor nvgColor3 = nvgFillColorEx(vg, 0);
	NVGcolor nvgColor4 = nvgFillColorEx(vg, 255);
	nvgFillPaint(vg, nvgLinearGradient(vg, x, y, x, y + height, nvgColor3, nvgColor4));
	nvgFill(vg);
}

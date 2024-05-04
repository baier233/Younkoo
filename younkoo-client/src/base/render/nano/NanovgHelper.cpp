#include "NanovgHelper.hpp"

#include <GL\glew.h>

#include "nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"
//#include "nanovg_gl_utils.h"
#include <iostream>

void error_callback(int error, const char* description)
{
	std::cerr << "CALLBACK Error: " << description << std::endl;
}
#include "../resources/fonts/harmony_sc_light.h"
#include "../resources/fonts/harmony_sc_regular.h"

bool NanoVGHelper::InitContext(HWND window2Attach)
{
	if (Context) return true;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	Context = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);

	//fontHarmony = nvgCreateFont(Context, "raleway", "C:\\Users\\Baier\\AppData\\Local\\Microsoft\\Windows\\Fonts\\HarmonyOS_Sans_SC_Regular.ttf");
	fontHarmony = nvgCreateFontMem(Context, "harmony_sans_regular", harmony_sc_regular, harmony_sc_regular_size, 0);

	nvgShapeAntiAlias(Context, 1);
	return Context != nullptr;
}

bool NanoVGHelper::DeleteContext()
{
	//释放nvg 上下文时.font也会被释放。
	nvgDeleteGL3(Context);
	Context = nullptr;
	return true;
}
static std::string Wide2Utf8(const std::wstring& str) {
	int sizeRequired = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	std::string utf8Str(sizeRequired, 0);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8Str[0], sizeRequired, NULL, NULL);
	return utf8Str;
}
void NanoVGHelper::nvgTextW(NVGcontext* vg, int x, int y, const std::wstring& str)
{
	auto utf8Str = Wide2Utf8(str);
	nvgText(vg, x, y, utf8Str.c_str(), utf8Str.c_str() + utf8Str.size());
}
void NanoVGHelper::nvgTextBoundsW(NVGcontext* vg, int x, int y, const std::wstring& str, float bounds[])
{
	auto utf8Str = Wide2Utf8(str);
	nvgTextBounds(vg, x, y, utf8Str.c_str(), utf8Str.c_str() + utf8Str.size(), bounds);
}

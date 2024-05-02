#include "NanovgHelper.hpp"

#include <GL\glew.h>

#include "nanovg.h"
#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg_gl.h"
//#include "nanovg_gl_utils.h"
#include <iostream>

void error_callback(int error, const char* description)
{
	std::cerr << "CALLBACK Error: " << description << std::endl;
}

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

	Context = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

	fontHarmony = nvgCreateFont(Context, "raleway", "C:\\Users\\Baier\\AppData\\Local\\Microsoft\\Windows\\Fonts\\HarmonyOS_Sans_SC_Light.ttf");
	return Context != nullptr;
}

bool NanoVGHelper::DeleteContext()
{
	//释放nvg 上下文时.font也会被释放。
	nvgDeleteGL2(Context);
	Context = nullptr;
	return true;
}

void NanoVGHelper::nvgTextW(NVGcontext* vg, int x, int y, std::wstring str)
{
	int sizeRequired = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	std::string utf8Str(sizeRequired, 0);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8Str[0], sizeRequired, NULL, NULL);
	nvgText(vg, 0, 66, utf8Str.c_str(), utf8Str.c_str() + utf8Str.size());
}

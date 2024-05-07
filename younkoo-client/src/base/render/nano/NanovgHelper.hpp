#pragma once
#include <Windows.h>
class NVGcontext;
#include "nanovg.h"
#include <string>

namespace NanoVGHelper {
	bool InitContext(HWND window2Attach);
	bool DeleteContext();
	inline NVGcontext* Context{};
	void nvgTextW(NVGcontext* vg, const std::wstring& str, int x, int y, int font, int size, NVGcolor col);
	void nvgRect(NVGcontext* vg, float x, float y, float width, float height, NVGcolor col);
	std::pair<float, float> nvgTextBoundsW(NVGcontext* vg, const std::wstring& str, int font, int size);
	void nvgTextBoundsW(NVGcontext* vg, int x, int y, const  std::wstring& str, float bounds[]);
	inline int fontHarmony{};
}


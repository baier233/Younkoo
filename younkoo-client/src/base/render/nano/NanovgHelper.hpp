#pragma once
#include <Windows.h>
class NVGcontext;

#include <string>

namespace NanoVGHelper {
	bool InitContext(HWND window2Attach);
	bool DeleteContext();
	inline NVGcontext* Context{};
	void nvgTextW(NVGcontext* vg, int x, int y, std::wstring str);
	inline int fontHarmony{};
}


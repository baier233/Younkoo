#pragma once
#include <Windows.h>
class NVGcontext;

namespace NanoVGHelper {
	bool InitContext(HWND window2Attach);
	bool DeleteContext();
	inline NVGcontext* Context{};
}


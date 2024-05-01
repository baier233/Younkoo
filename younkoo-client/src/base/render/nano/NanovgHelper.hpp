#pragma once


#include "nanovg.h"

namespace NanoVGHelper {
	bool InitContext();
	bool DeleteContext();
	inline NVGcontext* Context{};
}


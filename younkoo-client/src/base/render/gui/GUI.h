#pragma once

#include <atomic>
namespace NanoGui {
	void Init(void* hwnd, void* hdc, void* vg);
	void draw();
	void clean();
	inline std::atomic<bool> available = false;
	inline std::atomic<bool> nanoguiwantinput = false;
}


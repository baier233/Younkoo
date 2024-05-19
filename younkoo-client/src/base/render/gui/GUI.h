#pragma once

#include <atomic>
namespace NanoGui {
	void Init(void* hwnd, void* hdc, void* vg);
	void drawGui();
	void drawContents();
	void clean();
	inline std::atomic<bool> available = false;
}


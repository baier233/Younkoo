#pragma once
#include <base/features/modules/AbstractModule.h>
#include <atomic>
namespace NanoGui {
	void Init(void* hwnd, void* hdc, void* vg);
	void layOut();
	void drawGui();
	void drawContents();
	void updateModule(AbstractModule* module);
	void updateValues();
	void clean();
	inline std::atomic<bool> available = false;
}


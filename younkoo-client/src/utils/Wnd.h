#pragma once
#include <wtypes.h>
#include <cstdint>
namespace Wnd
{
	inline float get_pixel_ratio(HWND hWnd) {
		HMONITOR monitor = nullptr;

		monitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);

		static HRESULT(WINAPI * GetDpiForMonitor_)(HMONITOR, UINT, UINT*, UINT*) = nullptr;
		static bool GetDpiForMonitor_tried = false;

		if (!GetDpiForMonitor_tried) {
			auto shcore = LoadLibrary(TEXT("shcore"));
			if (shcore)
				GetDpiForMonitor_ = (decltype(GetDpiForMonitor_))GetProcAddress(shcore, "GetDpiForMonitor");
			GetDpiForMonitor_tried = true;
		}

		if (GetDpiForMonitor_ && monitor) {
			uint32_t dpiX, dpiY;
			if (GetDpiForMonitor_(monitor, 0 /* effective DPI */, &dpiX, &dpiY) == S_OK)
				return dpiX / 96.0;
		}
		return 1.f;
	}
};


#pragma once

#include <Windows.h>
#include <atomic>

typedef LRESULT(CALLBACK* WNDPROC_T) (HWND, UINT, WPARAM, LPARAM);

namespace WndProcHook {
	bool Init(HWND window2Hook);
	bool Clean();

	inline WNDPROC_T GL_HANDLE;
	inline HWND GL_HWND;
	inline std::atomic<bool> RESIZED = false;
}
	
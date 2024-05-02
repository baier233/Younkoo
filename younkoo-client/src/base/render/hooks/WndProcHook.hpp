#pragma once

#include <Windows.h>
#include <atomic>
#include  "../../../utils/types/Maths.hpp"

struct YounkooIOContext {
	Vector2D MousePos{ 0,0 };
	bool MouseDown[5]{ false };
	bool KeysDown[512]{ false };
	float MouseWheel = 0;
	float MouseWheelH = 0;
	std::vector<char>KeyQueue;
}inline context;



typedef LRESULT(CALLBACK* WNDPROC_T) (HWND, UINT, WPARAM, LPARAM);

namespace WndProcHook {
	bool Init(HWND window2Hook);
	bool Clean();

	inline WNDPROC_T GL_HANDLE;
	inline HWND GL_HWND;
	inline std::atomic<bool> RESIZED;
}

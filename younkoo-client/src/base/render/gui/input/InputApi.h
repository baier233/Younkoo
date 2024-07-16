#pragma once
#include "../../hooks/WndProcHook.hpp"
namespace InputApi {
	LRESULT SendMessageNoEvent(_In_opt_ HWND hWnd,
		_In_ UINT Msg,
		_In_ WPARAM wParam,
		_In_ LPARAM lParam);
}
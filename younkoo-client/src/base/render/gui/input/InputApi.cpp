#include "InputApi.h"

LRESULT InputApi::SendMessageNoEvent(_In_opt_ HWND hWnd,
	_In_ UINT Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	return CallWindowProcW(WndProcHook::GL_HANDLE, hWnd, Msg, wParam, lParam);
}

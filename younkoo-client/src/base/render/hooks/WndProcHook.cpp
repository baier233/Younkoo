#include "WndProcHook.hpp"
#include <windows.h>
#include <iostream>

// 定义回调指针类型

static bool IsVkDown(int vk) {
	return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

#include "../gui/input/Context.hpp"
#include "../gui/input/IOEvents.h"
//#include "../glfw/glfw_constants.h"
//
static int getKeyMods(void)
{
	int mods = 0;

	if (GetKeyState(VK_SHIFT) & 0x8000)
		mods |= GLFW_MOD_SHIFT;
	if (GetKeyState(VK_CONTROL) & 0x8000)
		mods |= GLFW_MOD_CONTROL;
	if (GetKeyState(VK_MENU) & 0x8000)
		mods |= GLFW_MOD_ALT;
	if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & 0x8000)
		mods |= GLFW_MOD_SUPER;
	if (GetKeyState(VK_CAPITAL) & 1)
		mods |= GLFW_MOD_CAPS_LOCK;
	if (GetKeyState(VK_NUMLOCK) & 1)
		mods |= GLFW_MOD_NUM_LOCK;

	return mods;
}


CallBackcursorposfun YounkooCursorPosCallback;
CallBackmousebuttonfun YounkooMouseButtonCallback;
CallBackkeyfun YounkooKeyCallback;
CallBackcharfun YounkooCharCallback;
CallBackdropfun YounkooDropCallback;
CallBackscrollfun YounkooScrollCallback;
CallBackwindowsizefun YounkooWindowSizeCallback;
CallBackwindowsetfoucs YounkooWindowFocusCallback;
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
		if (YounkooCursorPosCallback)
		{
			int x = GET_X_LPARAM(lParam);
			int y = GET_Y_LPARAM(lParam);
			YounkooCursorPosCallback(hWnd, x, y);
		}
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
		if (YounkooMouseButtonCallback)
		{
			int button = (message == WM_LBUTTONDOWN) ? CALLBACK_MOUSE_BUTTON_LEFT :
				(message == WM_RBUTTONDOWN) ? CALLBACK_MOUSE_BUTTON_RIGHT :
				CALLBACK_MOUSE_BUTTON_MIDDLE;
			YounkooMouseButtonCallback(hWnd, button, CALLBACK_PRESS, getKeyMods());
		}
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
		if (YounkooMouseButtonCallback)
		{
			int button = (message == WM_LBUTTONUP) ? CALLBACK_MOUSE_BUTTON_LEFT :
				(message == WM_RBUTTONUP) ? CALLBACK_MOUSE_BUTTON_RIGHT :
				CALLBACK_MOUSE_BUTTON_MIDDLE;
			YounkooMouseButtonCallback(hWnd, button, CALLBACK_RELEASE, getKeyMods());
		}
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (YounkooKeyCallback)
		{
			int key = static_cast<int>(wParam);
			int scancode = (lParam >> 16) & 0x1FF;
			int action = CALLBACK_PRESS;
			YounkooKeyCallback(hWnd, key, scancode, action, getKeyMods());
		}
		break;
	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (YounkooKeyCallback)
		{
			int key = static_cast<int>(wParam);
			int scancode = (lParam >> 16) & 0x1FF;
			int action = CALLBACK_RELEASE;
			YounkooKeyCallback(hWnd, key, scancode, action, getKeyMods());
		}
		break;
	case WM_CHAR:
	case WM_UNICHAR:
		if (YounkooCharCallback)
		{
			WCHAR codepoint = static_cast<WCHAR>(wParam);
			YounkooCharCallback(hWnd, codepoint);
		}
		break;
	case WM_DROPFILES:
		if (YounkooDropCallback)
		{
			HDROP hDrop = (HDROP)wParam;
			int count = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
			LPWSTR* filenames = new LPWSTR[count];
			for (int i = 0; i < count; i++)
			{
				int length = DragQueryFile(hDrop, i, NULL, 0);
				filenames[i] = new WCHAR[length + 1];
				DragQueryFileW(hDrop, i, filenames[i], length + 1);
			}
			YounkooDropCallback(hWnd, count, (const char**)filenames);
			for (int i = 0; i < count; i++)
			{
				delete[] filenames[i];
			}
			delete[] filenames;
			DragFinish(hDrop);
		}
		break;
	case WM_MOUSEHWHEEL:
		if (YounkooScrollCallback)
		{
			double xoffset = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
			double yoffset = 0;
			YounkooScrollCallback(hWnd, xoffset, yoffset);
		}
		break;
	case WM_MOUSEWHEEL:
		if (YounkooScrollCallback)
		{
			double xoffset = 0;
			double yoffset = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
			YounkooScrollCallback(hWnd, xoffset, yoffset);
		}
		break;
	case WM_SIZE:
		if (YounkooWindowSizeCallback)
		{
			int width = LOWORD(lParam);
			int height = HIWORD(lParam);
			YounkooWindowSizeCallback(hWnd, width, height);
		}
		break;
	case WM_SETFOCUS:
		if (YounkooWindowFocusCallback)
		{
			YounkooWindowFocusCallback(hWnd, true);
		}
		break;
	case WM_KILLFOCUS:
		if (YounkooWindowFocusCallback)
		{
			YounkooWindowFocusCallback(hWnd, false);
		}
		break;
	default:
		break;
	}

	return CallWindowProc(WndProcHook::GL_HANDLE, hWnd, message, wParam, lParam);;
}

#include "../gui/input/IOEvents.h"

static WNDPROC SetCallbacks(HWND hWnd)
{
	YounkooCursorPosCallback = [](HWND window, double x, double y) {
		// 光标位置回调
		std::shared_ptr<YounkooIO::IOEvent> event = std::make_shared<YounkooIO::MousePosEvent>(window, x, y);
		YounkooIO::IOEvents.push(event);
		if (YounkooIO::IOEvents.IOEventsCursorPosCallback)
		{
			if (y < 0)
				y = 0;

			if (x < 0)
				x = 0;

			YounkooIO::IOEvents.IOEventsCursorPosCallback(window, x, y);
		}
		//context.MousePos = Vector2D(x, y);

		};

	YounkooMouseButtonCallback = [](HWND window, int button, int action, int mods) {
		// 鼠标按钮回调
		//std::cout << "Button :" << button << std::endl;
		std::shared_ptr<YounkooIO::IOEvent> event = std::make_shared<YounkooIO::MouseEvent>(window, button, action);
		YounkooIO::IOEvents.push(event);

		if (YounkooIO::IOEvents.IOEventsMouseButtonCallback)
		{
			YounkooIO::IOEvents.IOEventsMouseButtonCallback(window, button, action, mods);
		}
		/*if (action == CALLBACK_PRESS) context.MouseDown[button] = true;
		if (action == CALLBACK_RELEASE) context.MouseDown[button] = false;*/
		};

	YounkooKeyCallback = [](HWND window, int key, int scancode, int action, int mods) {
		// 键盘按键回调
		std::shared_ptr<YounkooIO::IOEvent> event = std::make_shared<YounkooIO::KeyEvent>(window, key, action);
		YounkooIO::IOEvents.push(event);
		const bool is_key_down = action == CALLBACK_PRESS || action != CALLBACK_RELEASE;

		context.KeysDown[key] = is_key_down;

		if (key == VK_SHIFT)
		{
			if (IsVkDown(VK_LSHIFT) == is_key_down) { context.KeysDown[VK_LSHIFT] = is_key_down; }
			if (IsVkDown(VK_RSHIFT) == is_key_down) { context.KeysDown[VK_RSHIFT] = is_key_down; }
		}
		else if (key == VK_CONTROL)
		{
			if (IsVkDown(VK_LCONTROL) == is_key_down) { context.KeysDown[VK_LCONTROL] = is_key_down; }
			if (IsVkDown(VK_RCONTROL) == is_key_down) { context.KeysDown[VK_RCONTROL] = is_key_down; }
		}
		else if (key == VK_MENU)
		{
			if (IsVkDown(VK_LMENU) == is_key_down) { context.KeysDown[VK_LMENU] = is_key_down; }
			if (IsVkDown(VK_RMENU) == is_key_down) { context.KeysDown[VK_RMENU] = is_key_down; }
		}
		if (YounkooIO::IOEvents.IOEventsKeyCallback)
		{
			YounkooIO::IOEvents.IOEventsKeyCallback(window, key, scancode, action, mods);
		}

		};

	YounkooCharCallback = [](HWND window, WCHAR codepoint) {
		std::shared_ptr<YounkooIO::IOEvent> event = std::make_shared<YounkooIO::CharEvent>(window, codepoint);
		YounkooIO::IOEvents.push(event);
		if (YounkooIO::IOEvents.IOEventsCharCallback)
		{
			YounkooIO::IOEvents.IOEventsCharCallback(window, codepoint);
		}
		// 字符输入回调
		//context.KeyQueue.push_back(codepoint);
		};

	YounkooDropCallback = [](HWND window, int count, const char** filenames) {

		if (YounkooIO::IOEvents.IOEventsDropCallback)
		{
			YounkooIO::IOEvents.IOEventsDropCallback(window, count, filenames);
		}
		// 文件拖放回调
		};


	YounkooScrollCallback = [](HWND window, double xoffset, double yoffset) {
		std::shared_ptr<YounkooIO::IOEvent> event = std::make_shared<YounkooIO::WheelEvent>(window, xoffset, yoffset);
		YounkooIO::IOEvents.push(event);
		if (YounkooIO::IOEvents.IOEventsScrollCallback)
		{
			YounkooIO::IOEvents.IOEventsScrollCallback(window, xoffset, yoffset);
		}
		// 滚动鼠标回调
		//context.MouseWheel += yoffset;
		//context.MouseWheelH += xoffset;
		};

	YounkooWindowSizeCallback = [](HWND window, int width, int height) {
		//std::cout << "Reshape :" << width << "," << height << std::endl;
		// 窗口大小改变回调
		context.ScreenWidth = width;
		context.ScreenHeight = height;
		WndProcHook::RESIZED = true;
		if (YounkooIO::IOEvents.IOEventsWindowSizeCallback)
		{
			YounkooIO::IOEvents.IOEventsWindowSizeCallback(window, width, height);
		}
		};

	return (WNDPROC_T)SetWindowLongPtrW(hWnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
}


bool WndProcHook::Init(HWND window2Hook)
{
	GL_HWND = window2Hook;
	GL_HANDLE = SetCallbacks(window2Hook);
	return GL_HANDLE != nullptr;
}

bool WndProcHook::Clean()
{
	auto handle = SetWindowLongPtrW(GL_HWND, GWLP_WNDPROC, (LONG_PTR)GL_HANDLE);
	return handle != 0;
}

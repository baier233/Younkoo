#include "WndProcHook.hpp"
#include <windows.h>
#include <iostream>

constexpr auto CALLBACK_MOUSE_BUTTON_1 = 0;
constexpr auto CALLBACK_MOUSE_BUTTON_2 = 1;
constexpr auto CALLBACK_MOUSE_BUTTON_3 = 2;
constexpr auto CALLBACK_MOUSE_BUTTON_4 = 3;
constexpr auto CALLBACK_MOUSE_BUTTON_5 = 4;
constexpr auto CALLBACK_MOUSE_BUTTON_6 = 5;
constexpr auto CALLBACK_MOUSE_BUTTON_7 = 6;
constexpr auto CALLBACK_MOUSE_BUTTON_8 = 7;
#define CALLBACK_MOUSE_BUTTON_LAST      CALLBACK_MOUSE_BUTTON_8
#define CALLBACK_MOUSE_BUTTON_LEFT      CALLBACK_MOUSE_BUTTON_1
#define CALLBACK_MOUSE_BUTTON_RIGHT     CALLBACK_MOUSE_BUTTON_2
#define CALLBACK_MOUSE_BUTTON_MIDDLE    CALLBACK_MOUSE_BUTTON_3

constexpr auto CALLBACK_RELEASE = 0;
constexpr auto CALLBACK_PRESS = 1;

// 定义回调指针类型
typedef void (*CallBackcursorposfun)(HWND, double, double);
typedef void (*CallBackmousebuttonfun)(HWND, int, int, int);
typedef void (*CallBackkeyfun)(HWND, int, int, int, int);
typedef void (*CallBackcharfun)(HWND, unsigned int);
typedef void (*CallBackdropfun)(HWND, int, const char**);
typedef void (*CallBackscrollfun)(HWND, double, double);
typedef void (*CallBackwindowsizefun)(HWND, int, int);

// 定义回调
CallBackcursorposfun YounkooCursorPosCallback;
CallBackmousebuttonfun YounkooMouseButtonCallback;
CallBackkeyfun YounkooKeyCallback;
CallBackcharfun YounkooCharCallback;
CallBackdropfun YounkooDropCallback;
CallBackscrollfun YounkooScrollCallback;
CallBackwindowsizefun YounkooWindowSizeCallback;

// 窗口过程
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEMOVE:
        if (YounkooCursorPosCallback)
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
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
            YounkooMouseButtonCallback(hWnd, button, CALLBACK_PRESS, 0);
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
            YounkooMouseButtonCallback(hWnd, button, CALLBACK_RELEASE, 0);
        }
        break;
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        if (YounkooKeyCallback)
        {
            int key = wParam;
            int scancode = (lParam >> 16) & 0x1FF;
            int action = CALLBACK_PRESS;
            int mods = 0;
            YounkooKeyCallback(hWnd, key, scancode, action, mods);
        }
        break;
    case WM_KEYUP:
    case WM_SYSKEYUP:
        if (YounkooKeyCallback)
        {
            int key = wParam;
            int scancode = (lParam >> 16) & 0x1FF;
            int action = CALLBACK_RELEASE;
            int mods = 0;
            YounkooKeyCallback(hWnd, key, scancode, action, mods);
        }
        break;
    case WM_CHAR:
        if (YounkooCharCallback)
        {
            unsigned int codepoint = wParam;
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
    }

    return CallWindowProc(WndProcHook::GL_HANDLE, hWnd, message, wParam, lParam);;
}

static WNDPROC SetCallbacks(HWND hWnd)
{
    YounkooCursorPosCallback = [](HWND window, double x, double y) {
        // 光标位置回调
        };

    YounkooMouseButtonCallback = [](HWND window, int button, int action, int mods) {
        // 鼠标按钮回调
        };

    YounkooKeyCallback = [](HWND window, int key, int scancode, int action, int mods) {
        // 键盘按键回调
        };

    YounkooCharCallback = [](HWND window, unsigned int codepoint) {
        // 字符输入回调
        };

    YounkooDropCallback = [](HWND window, int count, const char** filenames) {
        // 文件拖放回调
        };

    YounkooScrollCallback = [](HWND window, double xoffset, double yoffset) {
        // 滚轮滚动回调
        };

    YounkooWindowSizeCallback = [](HWND window, int width, int height) {
        std::cout << "Reshape :" << width << "," << height << std::endl;
        // 窗口大小改变回调
        };

    return (WNDPROC_T)SetWindowLongPtrW(hWnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
}


bool WndProcHook::Init(HWND window2Hook)
{
    GL_HANDLE = SetCallbacks(window2Hook);
	return GL_HANDLE != nullptr;
}

bool WndProcHook::Clean()
{
    (void)SetWindowLongPtrW(GL_HWND, GWLP_WNDPROC, (LONG)GL_HANDLE);
	return true;
}

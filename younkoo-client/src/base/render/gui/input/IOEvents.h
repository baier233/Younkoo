#pragma once
#include <queue>
#include "Context.hpp"
#include <memory>
#include <Windows.h>

typedef void (*CallBackcursorposfun)(HWND, double, double);
typedef void (*CallBackmousebuttonfun)(HWND, int, int, int);
typedef void (*CallBackkeyfun)(HWND, int, int, int, int);
typedef void (*CallBackcharfun)(HWND, unsigned int);
typedef void (*CallBackdropfun)(HWND, int, const char**);
typedef void (*CallBackscrollfun)(HWND, double, double);
typedef void (*CallBackwindowsizefun)(HWND, int, int);
typedef void (*CallBackwindowsetfoucs)(HWND, bool);

namespace YounkooIO {
	enum EventType
	{
		KEY,
		MOUSEPOS,
		MOUSE,
		WHEEL,
		TYPE,
	};

	struct IOEvent {
		EventType type;
		HWND hwnd;
		IOEvent(EventType type, HWND hwnd) : hwnd(hwnd), type(type) {}
		virtual ~IOEvent() {}
	};

	struct KeyEvent final : IOEvent
	{
		KeyEvent(HWND hwnd, int keycode = 0, int action = 0) noexcept
			: IOEvent{ EventType::KEY,hwnd }, keycode(keycode), action(action) {}
		int keycode;
		int action;
	};

	struct MousePosEvent final : IOEvent
	{
		MousePosEvent(HWND hwnd, double posX = 0, double posY = 0) noexcept
			: IOEvent{ EventType::MOUSEPOS,hwnd }, posX(posX), posY(posY) {}
		double posX;
		double posY;
	};

	struct MouseEvent final : IOEvent
	{
		MouseEvent(HWND hwnd, int button = 0, int action = 0) noexcept
			: IOEvent{ EventType::MOUSE,hwnd }, button(button), action(action) {}
		int button;
		int action;
	};

	struct WheelEvent final : IOEvent
	{
		WheelEvent(HWND hwnd, double offsetX = 0, double offsetY = 0) noexcept :
			IOEvent{ EventType::WHEEL ,hwnd }, offsetX(offsetX), offsetY(offsetY) {}
		double offsetX;
		double offsetY;
	};

	struct CharEvent final :IOEvent
	{
		CharEvent(HWND hwnd, unsigned int codepoint = 0) noexcept
			: IOEvent{ EventType::TYPE ,hwnd }, codepoint(codepoint) {}
		unsigned int codepoint;
	};

	struct EventQueque : public std::queue<std::shared_ptr<YounkooIO::IOEvent>>
	{


		inline void SetCursorPosCallback(const CallBackcursorposfun& callback) {
			IOEventsCursorPosCallback = callback;
		}

		inline void SetMouseButtonCallback(const CallBackmousebuttonfun& callback) {
			IOEventsMouseButtonCallback = callback;
		}

		inline void SetKeyCallback(const CallBackkeyfun& callback) {
			IOEventsKeyCallback = callback;
		}

		inline void SetCharCallback(const CallBackcharfun& callback) {
			IOEventsCharCallback = callback;
		}

		inline void SetDropCallback(const CallBackdropfun& callback) {
			IOEventsDropCallback = callback;
		}

		inline void SetScrollCallback(const CallBackscrollfun& callback) {
			IOEventsScrollCallback = callback;
		}

		inline void SetWindowSizeCallback(const CallBackwindowsizefun& callback) {
			IOEventsWindowSizeCallback = callback;
		}

		inline void SetWindowFoucsCallback(const CallBackwindowsetfoucs& callback) {
			IOEventsWindowSetFoucsCallback = callback;
		}



		CallBackcursorposfun IOEventsCursorPosCallback;
		CallBackmousebuttonfun IOEventsMouseButtonCallback;
		CallBackkeyfun IOEventsKeyCallback;
		CallBackcharfun IOEventsCharCallback;
		CallBackdropfun IOEventsDropCallback;
		CallBackscrollfun IOEventsScrollCallback;
		CallBackwindowsizefun IOEventsWindowSizeCallback;
		CallBackwindowsetfoucs IOEventsWindowSetFoucsCallback;

		inline void Clear() noexcept {
			EventQueque empty{};
			this->swap(empty);
		}

	private:
	};


	inline EventQueque IOEvents;

	inline void Clear() noexcept {
		IOEvents.Clear();
	}

}



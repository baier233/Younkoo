#pragma once
#include <queue>
#include "Context.hpp"


namespace YounkooIO {
	enum EventType
	{
		KEY,
		MOUSE,
		WHEEL,
		TYPE,
	};

	struct IOEvent {
		EventType Type;
	};

	struct MouseEvent : public IOEvent
	{
		MouseEvent() : IOEvent{ MOUSE } {};
		int Button{};
		int Action{};
	};

	struct KeyEvent : public IOEvent
	{
		KeyEvent() : IOEvent{ KEY } {};
		int Keycode{};
		int Action{};
	};

	struct CharEvent : public IOEvent
	{
		CharEvent() : IOEvent{ TYPE } {}
		int Codepoint{};
	};

	struct WheelEvent : public IOEvent
	{
		WheelEvent() : IOEvent{ WHEEL } {};
		int Width{};
		int Height{};
	};

	inline std::queue<IOEvent> IOEvents;

	void Clear() {
		std::queue<IOEvent> empty;
		IOEvents.swap(empty);
	}
}



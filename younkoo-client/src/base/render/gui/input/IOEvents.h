#pragma once
#include <queue>
#include "Context.hpp"
#include <memory>


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
	};

	struct KeyEvent final : IOEvent
	{
		KeyEvent(int keycode = 0, int action = 0) noexcept
			: IOEvent{ EventType::KEY }, keycode(keycode), action(action) {}
		int keycode;
		int action;
	};

	struct MousePosEvent final : IOEvent
	{
		constexpr MousePosEvent(double posX = 0, double posY = 0) noexcept
			: IOEvent{ EventType::MOUSEPOS }, posX(posX), posY(posY) {}
		double posX;
		double posY;
	};

	struct MouseEvent final : IOEvent
	{
		constexpr MouseEvent(int button = 0, int action = 0) noexcept
			: IOEvent{ EventType::MOUSE }, button(button), action(action) {}
		int button;
		int action;
	};

	struct WheelEvent final : IOEvent
	{
		constexpr WheelEvent(double offsetX = 0, double offsetY = 0) noexcept :
			IOEvent{ EventType::WHEEL }, offsetX(offsetX), offsetY(offsetY) {}
		double offsetX;
		double offsetY;
	};

	struct CharEvent final :IOEvent
	{
		constexpr CharEvent(unsigned int codepoint = 0) noexcept
			: IOEvent{ EventType::TYPE }, codepoint(codepoint) {}
		unsigned int codepoint;
	};

	inline std::queue<std::shared_ptr<YounkooIO::IOEvent>> IOEvents;

	inline void Clear() noexcept {
		std::queue<std::shared_ptr<YounkooIO::IOEvent>> empty;
		IOEvents.swap(empty);
	}
}



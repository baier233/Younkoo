#pragma once
#include <atomic>
#include  "../../../../utils/types/Maths.hpp"

struct YounkooIOContext {
	Vector2D MousePos{ 0,0 };
	bool MouseDown[5]{ false };
	bool KeysDown[512]{ false };
	bool KeysDownAlready[512]{ false };
	float MouseWheel = 0;
	float MouseWheelH = 0;
	std::vector<char>KeyQueue;
}inline context;

class YounkooInput : public YounkooIOContext {
public:
	bool IsKeyPressed(const unsigned int keyCode, const bool repeat = true) {

		if (KeysDown[keyCode])
		{
			if (!KeysDownAlready[keyCode])
			{
				KeysDownAlready[keyCode] = true;
				return true;
			}
			if (repeat)
				return true;
		}
		else
		{
			KeysDownAlready[keyCode] = false;
		}
		return false;
	}
	bool MouseInZone(const Vector2D& pos, const Vector2D& size) const
	{
		const Vector2D& cursor_pos = MousePos;

		if (cursor_pos.x > pos.x && cursor_pos.y > pos.y)
			if (cursor_pos.x < pos.x + size.x && cursor_pos.y < pos.y + size.y)
				return true;
		return false;
	}

};
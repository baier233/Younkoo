#pragma once
#include <atomic>
#define CONTEXT_MOD_SHIFT           0x0001
/*! @brief If this bit is set one or more Control keys were held down.
 *
 *  If this bit is set one or more Control keys were held down.
 */
#define CONTEXT_MOD_CONTROL         0x0002
 /*! @brief If this bit is set one or more Alt keys were held down.
  *
  *  If this bit is set one or more Alt keys were held down.
  */
#define CONTEXT_MOD_ALT             0x0004
  /*! @brief If this bit is set one or more Super keys were held down.
   *
   *  If this bit is set one or more Super keys were held down.
   */
#define CONTEXT_MOD_SUPER           0x0008
   /*! @brief If this bit is set the Caps Lock key is enabled.
	*
	*  If this bit is set the Caps Lock key is enabled and the @ref
	*  GLFW_LOCK_KEY_MODS input mode is set.
	*/
#define CONTEXT_MOD_CAPS_LOCK       0x0010
	/*! @brief If this bit is set the Num Lock key is enabled.
	 *
	 *  If this bit is set the Num Lock key is enabled and the @ref
	 *  GLFW_LOCK_KEY_MODS input mode is set.
	 */
#define CONTEXT_MOD_NUM_LOCK        0x0020

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




#include <stdio.h>
#include <time.h>


inline double glfwGetTime() {
	return (double)clock() / CLOCKS_PER_SEC;
}
#include "../../../../utils/types/Maths.hpp"
struct YounkooIOContext {
	Math::Vector2D MousePos{ 0,0 };
	bool MouseDown[5]{ false };
	bool MouseDownAready[5]{ false };
	bool KeysDown[512]{ false };
	bool KeysDownAlready[512]{ false };
	double MouseWheel = 0;
	double MouseWheelH = 0;
	bool IsDragging = false;
	std::vector<char>InputQueueCharacters;
};
class YounkooInput : public YounkooIOContext {
public:
	bool IsMousePressed(const unsigned int button, const bool repeat = true) {
		if (MouseDown[button])
		{
			if (!MouseDownAready[button])
			{
				MouseDownAready[button] = true;
				return true;
			}
			if (repeat)
				return true;
		}
		else
		{
			MouseDownAready[button] = false;
		}
		return false;
	}

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
	bool MouseInZone(const Math::Vector2D& pos, const Math::Vector2D& size) const
	{
		const Math::Vector2D& cursor_pos = MousePos;

		if (cursor_pos.x > pos.x && cursor_pos.y > pos.y)
			if (cursor_pos.x < pos.x + size.x && cursor_pos.y < pos.y + size.y)
				return true;
		return false;
	}
	void EndFrame() {
		this->MouseWheel = this->MouseWheelH = 0.0f;
		this->InputQueueCharacters.resize(0);
	}
}inline context;
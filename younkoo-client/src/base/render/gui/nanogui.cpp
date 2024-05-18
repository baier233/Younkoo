#include "nanogui.h"

#include "nanogui/Screen.h"
#include "nanogui/FormHelper.h"

#include <memory>

#include <iostream>
#include "input/IOEvents.h"
namespace NanoGui {
	nanogui::ref<nanogui::Screen> screen = nullptr;
	nanogui::ref<nanogui::Window> window = nullptr;
	nanogui::FormHelper* form = nullptr;
}


void NanoGui::Init(void* hwnd, void* hdc, void* vg)
{
	screen = new nanogui::Screen((HWND)hwnd, (HDC)hdc, (NVGcontext*)vg, "Screen");
	//screen->setSize()
	/// dvar, bar, strvar, etc. are double/bool/string/.. variables
	form = new nanogui::FormHelper(screen.get());
	auto& gui = form;
	window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
	window->setLayout(new nanogui::GroupLayout());
	static bool bvar = false;
	static std::string strvar = "Hello";
	static int ivar = 22;
	static float fvar = 1337.3367;
	static double dvar = 13337.11333367;
	gui->addGroup("Basic types");
	gui->addVariable("bool", bvar);
	gui->addVariable("string", strvar);

	gui->addGroup("Validating fields");
	gui->addVariable("int", ivar);
	gui->addVariable("float", fvar);
	gui->addVariable("double", dvar);

	gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });

	screen->setVisible(true);
	screen->performLayout();

	YounkooIO::IOEvents.SetCursorPosCallback(
		[](HWND w, double x, double y) {
			if (!screen->mProcessEvents)
				return;
			screen->cursorPosCallbackEvent(x, y);
		}
	);

	YounkooIO::IOEvents.SetMouseButtonCallback(
		[](HWND w, int button, int action, int modifiers) {
			if (!screen->mProcessEvents)
				return;
			screen->mouseButtonCallbackEvent(button, action, modifiers);
		}
	);

	YounkooIO::IOEvents.SetKeyCallback(
		[](HWND w, int key, int scancode, int action, int mods) {
			if (!screen->mProcessEvents)
				return;
			screen->keyCallbackEvent(key, scancode, action, mods);
		}
	);

	YounkooIO::IOEvents.SetCharCallback(
		[](HWND w, unsigned int codepoint) {
			if (!screen->mProcessEvents)
				return;
			screen->charCallbackEvent(codepoint);
		}
	);

	YounkooIO::IOEvents.SetDropCallback(
		[](HWND w, int count, const char** filenames) {
			if (!screen->mProcessEvents)
				return;
			screen->dropCallbackEvent(count, filenames);
		}
	);

	YounkooIO::IOEvents.SetScrollCallback(
		[](HWND w, double x, double y) {
			screen->scrollCallbackEvent(x, y);
		}
	);

	/* React to framebuffer size events -- includes window
	   size events and also catches things like dragging
	   a window from a Retina-capable screen to a normal
	   screen on Mac OS X */
	YounkooIO::IOEvents.SetWindowSizeCallback(
		[](HWND w, int width, int height) {
			screen->resizeCallbackEvent(width, height);
		}
	);

	// notify when the screen has lost focus (e.g. application switch)
	YounkooIO::IOEvents.SetWindowFoucsCallback(
		[](HWND w, bool focused) {
			// focused: 0 when false, 1 when true
			screen->focusEvent(focused);
		}
	);

}

void NanoGui::draw()
{
	window->center();
	screen->drawAll();
}

void NanoGui::clean()
{

	window->decRef();
	screen->decRef();

}

#include "GUI.h"

#include "nanogui/Screen.h"
#include "nanogui/FormHelper.h"
#include <memory>

#include <iostream>
#include "input/IOEvents.h"
#include "../../event/Events.h"
#include "../Younkoo.hpp"
#include "../features/modules/ModuleManager.h"

namespace NanoGui {
	nanogui::ref<nanogui::Screen> screen = nullptr;
	std::vector<nanogui::ref<nanogui::Window>> windows = {};
	/// \fixme @BaierOops : Notice : 因为神必原因，这个form释放不掉，因此new了之后没有delete实属迫不得已
	nanogui::FormHelper* form = nullptr;
	int xPos = 10;
}
class GUI : public nanogui::Screen {
public:
	GUI(HWND window, HDC hdc, NVGcontext* vg, const std::string& caption) : Screen(window, hdc, vg, caption) {};
	void drawContents() override {
		auto vg = this->mNVGContext;
		EventRender2D e{ vg, mSize[0], mSize[1] };
		Younkoo::get().EventBus->fire_event(e);
	}
};

void NanoGui::Init(void* hwnd, void* hdc, void* vg)
{
	screen = new GUI((HWND)hwnd, (HDC)hdc, (NVGcontext*)vg, "Screen");
	//return screen->setSize()
	/// dvar, bar, strvar, etc. are double/bool/string/.. variables
	form = new nanogui::FormHelper(screen.get());
	auto& gui = form;
	static bool bvar = false;
	static std::string strvar = "Hello";
	static int ivar = 22;
	static float fvar = 1337.3367;
	static double dvar = 13337.11333367;
	for (Category c : { Category::CLICKER, Category::COMBAT, Category::PLAYER, Category::VISUAL }) {
		switch (c) {
		case Category::CLICKER:
		{
			auto win = gui->addWindow(Eigen::Vector2i(xPos, 10), "Clicker");
			//win->setLayout(new nanogui::GroupLayout());
			win->setSize(nanogui::Vector2i(250, 700));
			windows.push_back(win);
			gui->addVariable("bool", bvar);
			gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });
			xPos += 100;
			break;
		}
		case Category::COMBAT:
		{
			auto win = gui->addWindow(Eigen::Vector2i(xPos, 10), "Combat");
			//win->setLayout(new nanogui::GroupLayout());
			win->setSize(nanogui::Vector2i(250, 700));
			windows.push_back(win);
			gui->addVariable("string", strvar);
			gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });
			xPos += 100;
			break;
		}
		case Category::PLAYER:
		{
			auto win = gui->addWindow(Eigen::Vector2i(xPos, 10), "Player");
			//win->setLayout(new nanogui::GroupLayout());
			win->setSize(nanogui::Vector2i(250, 700));
			windows.push_back(win);
			gui->addVariable("int", ivar);
			gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });
			xPos += 100;
			break;
		}
		case Category::VISUAL:
		{
			auto win = gui->addWindow(Eigen::Vector2i(xPos, 10), "Visual");
			win->setSize(nanogui::Vector2i(250, 700));
			windows.push_back(win);
			for (auto m : ModuleManager::get().getMods()) {
				AbstractModule* mod = ToBaseModule(m);
				nanogui::Button* button = new nanogui::Button(win, mod->getName());
				button->setTextColor(nanogui::Color(1.0f, 1.0f, 1.0f, 1.0f));
				button->setBackgroundColor(mod->getToggle() ? nanogui::Color(1.0f, 0.0f, 0.0f, 1.0f) : nanogui::Color(0.0f, 0.0f, 1.0f, 1.0f));
				button->setCallback([button, mod]() {
					button->setBackgroundColor(mod->getToggle() ? nanogui::Color(1.0f, 0.0f, 0.0f, 1.0f) : nanogui::Color(0.0f, 0.0f, 1.0f, 1.0f));
					});
			}

			xPos += 100;
			break;
		}
		default:
		{
			break;
		}
		}
	}

	//window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
	//window->setLayout(new nanogui::GroupLayout());

	//gui->addGroup("Basic types");
	//gui->addVariable("bool", bvar);
	//gui->addVariable("string", strvar);

	//gui->addGroup("Validating fields");
	//gui->addVariable("int", ivar);
	//gui->addVariable("float", fvar);
	//gui->addVariable("double", dvar);

	//gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });


	screen->setVisible(true);
	screen->performLayout();

	YounkooIO::IOEvents.SetCursorPosCallback(
		[](HWND w, double x, double y) {
			//std::cout << "X :" << x << " Y :" << y << std::endl;
			if (NanoGui::available)
				return screen->cursorPosCallbackEvent(x, y);
			return false;
		}
	);

	YounkooIO::IOEvents.SetMouseButtonCallback(
		[](HWND w, int button, int action, int modifiers) {
			if (NanoGui::available)
				return screen->mouseButtonCallbackEvent(button, action, modifiers);
			return false;
		}
	);

	YounkooIO::IOEvents.SetKeyCallback(
		[](HWND w, int key, int scancode, int action, int mods) {
			if (NanoGui::available)
				return screen->keyCallbackEvent(key, scancode, action, mods);
			return false;
		}
	);

	YounkooIO::IOEvents.SetCharCallback(
		[](HWND w, uint32_t codepoint) {
			if (NanoGui::available)
				return screen->charCallbackEvent(codepoint);
			return false;
		}
	);

	YounkooIO::IOEvents.SetDropCallback(
		[](HWND w, int count, const char** filenames) {
			if (NanoGui::available)
				return screen->dropCallbackEvent(count, filenames);
			return false;
		}
	);

	YounkooIO::IOEvents.SetScrollCallback(
		[](HWND w, double x, double y) {
			if (NanoGui::available)
				return screen->scrollCallbackEvent(x, y);
			return false;
		}
	);

	/* React to framebuffer size events -- includes window
	   size events and also catches things like dragging
	   a window from a Retina-capable screen to a normal
	   screen on Mac OS X */
	YounkooIO::IOEvents.SetWindowSizeCallback(
		[](HWND w, int width, int height) {
			if (NanoGui::available)
				return screen->resizeCallbackEvent(width, height);
			return false;
		}
	);

	// notify when the screen has lost focus (e.g. application switch)
	YounkooIO::IOEvents.SetWindowFoucsCallback(
		[](HWND w, bool focused) {
			if (NanoGui::available)
				return screen->focusEvent(focused);
			return false;
			// focused: 0 when false, 1 when true
		}
	);

}

void NanoGui::drawGui()
{
	if (!available)
		return;
	screen->drawAll();
}

void NanoGui::drawContents()
{
	screen->updateContext();
	screen->drawContentWrap();
}

void NanoGui::clean()
{
	for (auto win : windows) {
		win->decRef();
	}
	screen->decRef();

}

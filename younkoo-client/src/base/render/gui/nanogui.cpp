#include "nanogui.h"

#include "nanogui/Screen.h"
#include "nanogui/FormHelper.h"

#include <memory>

#include <iostream>
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

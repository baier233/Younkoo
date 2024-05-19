#include "GUI.h"

#include "nanogui/Screen.h"
#include "nanogui/FormHelper.h"
#include "nanogui/Slider.h"
#include <memory>

#include <iostream>
#include "input/IOEvents.h"
#include "../../event/Events.h"
#include "../Younkoo.hpp"
#include "../features/modules/ModuleManager.h"

namespace NanoGui {
	nanogui::ref<nanogui::Screen> screen = nullptr;
	///screen 不需要主动调用decref,在delete form的时候screen会跟着释放。
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
using namespace nanogui;
void createWindow(int xPos, const std::string& title, Category category) {
	auto win = new Window(NanoGui::screen, title);
	win->setPosition(Vector2i(xPos, 10));
	win->setLayout(new GroupLayout());

	for (auto m : ModuleManager::get().getMods()) {

		AbstractModule* mod = ToBaseModule(m);
		if (mod->getCategory() == category) {
			auto panel = new Widget(win);
			panel->setLayout(new GroupLayout());

			auto titlePanel = new Widget(panel);
			titlePanel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));
			auto label = new Label(titlePanel, mod->getName(), "sans-bold");

			auto contentPanel = new Widget(panel);
			contentPanel->setLayout(new BoxLayout(Orientation::Vertical, Alignment::Fill, 5, 5));


			auto button = new Button(contentPanel, "Toggle");
			button->setCallback([mod, button] {
				mod->toggle();
				button->setCaption(mod->getToggle() ? "Toggle" : "Disable");
				});

			for (auto& valuePair : mod->getValues()) {
				ValueType valueType = valuePair.first;
				Value* value = valuePair.second;

				switch (valueType) {
				case BoolType:
					if (auto boolValue = dynamic_cast<BoolValue*>(value)) {
						new CheckBox(contentPanel, boolValue->getName(), [boolValue](bool enabled) {
							*boolValue->getValuePtr() = enabled;
							});
					}
					break;
				case IntType:
					if (auto intValue = dynamic_cast<NumberValue*>(value)) {
						auto label = new Label(contentPanel, intValue->getName());
						auto slider = new Slider(contentPanel);
						slider->setRange(std::make_pair(intValue->getMin(), intValue->getMax()));
						slider->setValue(intValue->getValue());
						slider->setCallback([intValue](float value) {
							intValue->setValue(static_cast<int>(value));
							});
					}
					break;
				case FloatType:
					if (auto floatValue = dynamic_cast<FloatValue*>(value)) {
						auto label = new Label(contentPanel, floatValue->getName());
						auto slider = new Slider(contentPanel);
						slider->setRange(std::make_pair(floatValue->getMin(), floatValue->getMax()));
						slider->setValue(floatValue->getValue());
						slider->setCallback([floatValue](float value) {
							floatValue->setValue(value);
							});
					}
					break;
				case ListType:
					if (auto modeValue = dynamic_cast<ModeValue*>(value)) {
						auto label = new Label(contentPanel, modeValue->getName());
						std::vector<std::string> items;
						for (size_t i = 0; i < modeValue->getModes().size(); i++)
						{
							items.push_back(modeValue->getDescs()[i]);
						}
						auto comboBox = new ComboBox(contentPanel, items);
						comboBox->setSelectedIndex(modeValue->getValue());
						comboBox->setCallback([modeValue](int selectedIndex) {
							modeValue->setValue(selectedIndex);
							});
					}
					break;
				case ColorType:
					if (auto colorValue = dynamic_cast<ColorValue*>(value)) {
						auto label = new Label(contentPanel, colorValue->getName());
						auto colorPicker = new ColorPicker(contentPanel, Color(colorValue->getValue()));
						colorPicker->setCallback([colorValue](const Color& color) {
							float* colorArray = colorValue->getValuePtr();
							colorArray[0] = color.r();
							colorArray[1] = color.g();
							colorArray[2] = color.b();
							colorArray[3] = color.w();
							});
					}
					break;
				default:
					break;
				}
			}
		}
	}
}



void NanoGui::Init(void* hwnd, void* hdc, void* vg)
{
	screen = new GUI((HWND)hwnd, (HDC)hdc, (NVGcontext*)vg, "Screen");

	form = new nanogui::FormHelper(screen);

	auto& gui = form;
	int xPos = 10;

	for (Category c : { Category::CLICKER, Category::COMBAT, Category::PLAYER, Category::VISUAL }) {
		switch (c) {
		case Category::CLICKER:
			createWindow(xPos, "Clicker", Category::CLICKER);
			break;
		case Category::COMBAT:
			createWindow(xPos, "Combat", Category::COMBAT);
			break;
		case Category::PLAYER:
			createWindow(xPos, "Player", Category::PLAYER);
			break;
		case Category::VISUAL:
			createWindow(xPos, "Visual", Category::VISUAL);
			break;
		default:
			break;
		}
		xPos += 120;
	}
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
	delete form;
}

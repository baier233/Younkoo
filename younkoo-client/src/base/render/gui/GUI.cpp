#include "GUI.h"

#include "nanogui/Screen.h"
#include "nanogui/FormHelper.h"
#include "nanogui/Slider.h"
#include "nanogui/VScrollPanel.h"
#include <memory>

#include <iostream>
#include "input/IOEvents.h"
#include "../../event/Events.h"
#include "../Younkoo.hpp"
#include "../features/modules/ModuleManager.h"

#include "../Renderer.hpp"

#include <iomanip>
#include <sstream>

#include <map>
using namespace nanogui;

static std::vector<std::pair<std::pair<int, int>, std::function<void(int oWidth, int oHeight)>>> layoutLambdas;
static std::map<AbstractModule*, Button*> toggleButtons;



void NanoGui::updateModule(AbstractModule* mod)
{
	auto it = toggleButtons.find(mod);
	if (it != toggleButtons.end())
	{
		auto button = it->second;
		button->setCaption(mod->getToggle() ? "Disable" : "Toggle");
	}
}
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
static void createWindow(int xPos, const std::string& title, Category category) {
	auto win = new Window(NanoGui::screen, title);
	win->setPosition(Vector2i(xPos, 10));
	win->setLayout(new GroupLayout());

	// 添加 VScrollPanel
	auto scrollPanel = new VScrollPanel(win);

	auto panel = new Widget(scrollPanel);
	panel->setLayout(new GroupLayout());

	for (auto m : ModuleManager::get().getMods()) {
		AbstractModule* mod = ToBaseModule(m);
		if (mod->getCategory() == category) {
			auto modulePanel = new Widget(panel);
			modulePanel->setLayout(new GroupLayout());

			auto titlePanel = new Widget(modulePanel);
			titlePanel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));
			auto label = new Label(titlePanel, mod->getName(), "sans-bold");

			auto contentPanel = new Widget(modulePanel);
			contentPanel->setLayout(new BoxLayout(Orientation::Vertical, Alignment::Fill, 5, 5));

			auto button = new Button(contentPanel, mod->getToggle() ? "Disable" : "Toggle");
			button->setCallback([mod, button] {
				mod->toggle();
				button->setCaption(mod->getToggle() ? "Disable" : "Toggle");
				});

			toggleButtons[mod] = button;

			for (auto& valuePair : mod->getValues()) {
				ValueType valueType = valuePair.first;
				auto& value = valuePair.second;

				switch (valueType) {
				case BoolType:
					if (auto boolValue = dynamic_cast<BoolValue*>(value.get())) {
						auto checkBox = new CheckBox(contentPanel, boolValue->getName(), [value](bool enabled) {
							*(bool*)value->getPtr() = enabled;
							});
						checkBox->setChecked(boolValue->getValue());
					}
					break;
				case IntType:
					if (auto intValue = dynamic_cast<NumberValue*>(value.get())) {
						auto label = new Label(contentPanel, intValue->getName());

						auto sliderPanel = new Widget(contentPanel);
						sliderPanel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));

						auto slider = new Slider(sliderPanel);
						slider->setRange(std::make_pair(intValue->getMin(), intValue->getMax()));
						slider->setValue(intValue->getValue());

						auto textBox = new TextBox(sliderPanel);
						textBox->setFixedSize(Vector2i(50, 20));
						textBox->setFontSize(15);
						textBox->setValue(std::to_string(intValue->getValue()));

						slider->setCallback([value, textBox](float value_) {
							int v = static_cast<int>(value_);
							*(float*)value->getPtr() = v;
							});

						textBox->setCallback([value, slider](const std::string& text) {
							try {
								int v = std::stoi(text);
								*(int*)value->getPtr() = v;
								slider->setValue(v);
							}
							catch (...) {
								return false;
								// 处理无效输入
							}
							return true;
							});
					}
					break;
				case FloatType:
					if (auto floatValue = dynamic_cast<FloatValue*>(value.get())) {
						auto label = new Label(contentPanel, floatValue->getName());

						auto sliderPanel = new Widget(contentPanel);
						sliderPanel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));

						auto slider = new Slider(sliderPanel);
						slider->setRange(std::make_pair(floatValue->getMin(), floatValue->getMax()));
						slider->setValue(floatValue->getValue());

						auto textBox = new TextBox(sliderPanel);
						textBox->setFixedSize(Vector2i(50, 20));
						textBox->setFontSize(15);
						std::ostringstream oss;
						oss << std::fixed << std::setprecision(2) << floatValue->getValue();
						textBox->setValue(oss.str());

						slider->setCallback([value, textBox](float value_) {
							*(float*)value->getPtr() = value_;
							std::ostringstream oss;
							oss << std::fixed << std::setprecision(2) << value_;
							textBox->setValue(oss.str());
							});

						textBox->setCallback([value, slider](const std::string& text) {
							try {
								float value_ = std::stof(text);
								*(float*)value->getPtr() = value_;
								slider->setValue(value_);
							}
							catch (...) {
								return false;
								// 处理无效输入
							}
							return true;
							});
					}
					break;
				case ListType:
					if (auto modeValue = dynamic_cast<ModeValue*>(value.get())) {
						auto label = new Label(contentPanel, modeValue->getName());
						std::vector<std::string> items;
						for (size_t i = 0; i < modeValue->getModes().size(); i++) {
							items.push_back(modeValue->getDescs()[i]);
						}
						auto comboBox = new ComboBox(contentPanel, items);
						comboBox->setSelectedIndex(modeValue->getValue());
						comboBox->setCallback([value](int selectedIndex) {
							*(int*)value->getPtr() = selectedIndex;
							});
					}
					break;
				case ColorType:
					if (auto colorValue = dynamic_cast<ColorValue*>(value.get())) {
						auto label = new Label(contentPanel, colorValue->getName());
						auto colorPicker = new ColorPicker(contentPanel, Color(colorValue->getValue()));
						colorPicker->setCallback([value](const Color& color) {
							auto colorArray = (float*)value->getPtr();
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
	win->performLayout(NanoGui::screen->nvgContext());

	Vector2i size = win->preferredSize(NanoGui::screen->nvgContext());

	std::function<void(int, int)> doLayout = [win, scrollPanel](int width, int height) {

		auto [winWidth, winHeight] = Renderer::get().renderContext.winSize;
		//std::cout << "height : " << width << " " << winHeight << std::endl;
		//std::cout << "width :" << height << " " << winWidth << std::endl;
		if (width < 250)
		{
			width = 250;
		}
		if (height < 100)
		{
			height = 100;
		}
		if (height > winHeight * 0.85)
		{
			height = winHeight * 0.85;
		}
		scrollPanel->setFixedSize(Vector2i(width, height));
		};
	layoutLambdas.push_back(std::make_pair(std::make_pair(size.x(), size.y()), doLayout));

}
#include "../config/ConfigManager.h"
static void createSettingsWindow(int xPos) {
	auto win = new Window(NanoGui::screen, "Settings");
	win->setPosition(Vector2i(xPos, 10));
	win->setLayout(new GroupLayout());

	// 添加 VScrollPanel
	auto scrollPanel = new VScrollPanel(win);

	auto panel = new Widget(scrollPanel);
	panel->setLayout(new GroupLayout());
	auto Savebutton = new Button(panel, "SaveConfig");
	Savebutton->setCallback([] {
		//TODO:Set your own name
		ConfigManager::get().SaveConfig("config.json");
		});
	auto Detachbutton = new Button(panel, "Detach");
	Detachbutton->setCallback([] {
		Younkoo::get().shouldShutDown = true;
		});
	auto Loadbutton = new Button(panel, "LoadConfig");
	Loadbutton->setCallback([] {
		//TODO:Choose the config you need
		ConfigManager::get().LoadConfig("config.json");
		});
	win->performLayout(NanoGui::screen->nvgContext());

	Vector2i size = win->preferredSize(NanoGui::screen->nvgContext());

	std::function<void(int, int)> doLayout = [win, scrollPanel](int width, int height) {

		auto [winWidth, winHeight] = Renderer::get().renderContext.winSize;
		//std::cout << "height : " << width << " " << winHeight << std::endl;
		//std::cout << "width :" << height << " " << winWidth << std::endl;
		if (width < 250)
		{
			width = 250;
		}
		if (height < 100)
		{
			height = 100;
		}
		if (height > winHeight * 0.85)
		{
			height = winHeight * 0.85;
		}
		scrollPanel->setFixedSize(Vector2i(width, height));
		};
	layoutLambdas.push_back(std::make_pair(std::make_pair(size.x(), size.y()), doLayout));

}
void NanoGui::layOut()
{
	for (auto& [oWinSize, doLayout] : layoutLambdas)
	{
		auto& [width, height] = oWinSize;
		doLayout(width, height);
	}

	screen->performLayout();
}

void NanoGui::Init(void* hwnd, void* hdc, void* vg)
{
	screen = new GUI((HWND)hwnd, (HDC)hdc, (NVGcontext*)vg, "Screen");

	form = new nanogui::FormHelper(screen);

	auto& gui = form;
	int xPos = 10;

	for (Category c : { Category::COMBAT, Category::MOVEMENT, Category::PLAYER, Category::MISC, Category::VISUAL }) {
		switch (c) {
		case Category::COMBAT:
			createWindow(xPos, "Combat", c);
			break;
		case Category::MOVEMENT:
			createWindow(xPos, "Movement", c);
			break;
		case Category::PLAYER:
			createWindow(xPos, "Player", c);
			break;
		case Category::MISC:
			createWindow(xPos, "Misc", c);
			break;
		case Category::VISUAL:
			createWindow(xPos, "Visual", c);
			break;
		default:
			break;
		}
		xPos += 200;
	}
	createSettingsWindow(xPos);
	layOut();

	screen->setVisible(true);

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

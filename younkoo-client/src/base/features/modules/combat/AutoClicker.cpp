#include "AutoClicker.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <optional>
#include <random>
#include <wrapper/net/minecraft/entity/item/ItemBlock.h>


namespace Left {

	long lastClickTime = 0;
	int nextCps = 10;
	int count = 0;
	static int minAps = 10;
	static int maxAps = 10;
}

namespace Right {

	long lastClickTime = 0;
	int nextCps = 10;
	int count = 0;
	static int minAps = 10;
	static int maxAps = 10;
}


AutoClicker::AutoClicker() :AbstractModule(xorstr_("AutoClicker"), Category::COMBAT, 'U')
{
	this->setToggle(false);

	this->addValue(FloatType, leftMinCpsValue);
	this->addValue(FloatType, leftMaxCpsValue);

	this->addValue(BoolType, blockHitValue);
	this->addValue(FloatType, blockHitChanceValue);

	this->addValue(BoolType, miningValue);
	this->addValue(BoolType, inInventoryValue);

	this->addValue(ListType, clickModeValue);
	this->addValue(ListType, blockOnlyValue);
}


AutoClicker& AutoClicker::getInstance()
{
	static AutoClicker instance = AutoClicker();
	return instance;
}

void AutoClicker::onEnable()
{
}

void AutoClicker::onDisable()
{

}

void AutoClicker::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	if (Wrapper::Minecraft::getMinecraft().isInGuiState() && !inInventoryValue->getValue()) return;

	static auto getClickMode = [](ClickMode mode) -> std::optional<std::pair<bool, bool>> {
		switch (mode) {
		case BOTH:
			return std::make_pair(true, true);
		case LEFTONLY:
			return std::make_pair(true, false);
		case RIGHTONLY:
			return std::make_pair(false, true);
		default:
			return std::nullopt;
		}
		};

	auto [left, right] = getClickMode(static_cast<ClickMode>(clickModeValue->getValue())).value_or(std::make_pair(false, false));
	const auto handleWindow = Renderer::get().renderContext.HandleWindow;

	auto mc = Wrapper::Minecraft::getMinecraft();

	while (left)
	{
		long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (Left::lastClickTime == 0) Left::lastClickTime = milli;
		if ((milli - Left::lastClickTime) < (1000 / Left::nextCps)) break;

		if (!GetAsyncKeyState(VK_LBUTTON) && 1) break;

		auto mouseOver = mc.getMouseOver();

		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		static auto updateCps = [&] {

			Left::lastClickTime = milli;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(((int)leftMinCpsValue->getValue()), ((int)leftMaxCpsValue->getValue()));
			Left::nextCps = distrib(gen);
			};

		if (miningValue->getValue() && mouseOver.isTypeOfBlock()) {
			//std::cout << "Break" << std::endl;
			PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			updateCps();
			break;
		}

		//CommonData::getInstance()->isCombat = true;
		PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		PostMessageA(handleWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

		if (blockHitValue->getValue() == true && Left::count == blockHitChanceValue->getValue()) {
			PostMessageA(handleWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			PostMessageA(handleWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			Left::count = 0;
		}

		else if (blockHitValue->getValue() == true) {
			Left::count++;
		}
		updateCps();
		break;

	}

	if (right)
	{

		long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (Right::lastClickTime == 0) Right::lastClickTime = milli;
		if ((milli - Right::lastClickTime) < (1000 / Right::nextCps)) return;



		if (GetAsyncKeyState(VK_RBUTTON) && 1) {

			auto item = mc.getPlayer().getInventory().getCurrentItem();
			if (item.getObject() == NULL) return;
			if (blockOnlyValue->getValue() && !JNI::get_env()->IsInstanceOf(item.getObject(), Wrapper::ItemBlock::klass())) return;

			POINT pos_cursor;

			GetCursorPos(&pos_cursor);
			PostMessageA(handleWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			PostMessageA(handleWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

			Right::lastClickTime = milli;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(this->rightMinCpsValue->getValue(), this->rightMaxCpsValue->getValue());
			Right::nextCps = distrib(gen);
		}
	}

}
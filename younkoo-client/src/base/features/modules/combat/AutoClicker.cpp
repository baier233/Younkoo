﻿#include "AutoClicker.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <include_header.h>
#include <random>


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

	this->addValue(FloatType, leftMinCpsValue.get());
	this->addValue(FloatType, leftMaxCpsValue.get());

	this->addValue(BoolType, blockHitValue.get());
	this->addValue(FloatType, blockHitChanceValue.get());

	this->addValue(BoolType, miningValue.get());
	this->addValue(BoolType, inInventoryValue.get());

	this->addValue(ListType, clickModeValue.get());
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
	auto handleWindow = Renderer::get().renderContext.HandleWindow;

	if (left)
	{
		long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (Left::lastClickTime == 0) Left::lastClickTime = milli;
		if ((milli - Left::lastClickTime) < (1000 / Left::nextCps)) return;

		auto mc = Wrapper::Minecraft::getMinecraft();
		auto mouseOver = mc.getMouseOver();
		if (miningValue->getValue() && mouseOver.isTypeOfBlock()) {
			POINT pos_cursor;
			GetCursorPos(&pos_cursor);
			PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			return;
		}

		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
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

		Left::lastClickTime = milli;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib((*leftMinCpsValue->getValuePtr()), (*leftMaxCpsValue->getValuePtr()));
		Left::nextCps = distrib(gen);

	}

	if (right)
	{

	}

}
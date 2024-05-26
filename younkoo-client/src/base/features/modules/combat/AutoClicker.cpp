﻿#include "AutoClicker.h"
#include <chrono>
#include <random>
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

long lastClickTime = 0;
int nextCps = 10;
int count = 0;
static int minAps = 10;
static int maxAps = 10;

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
	static Minecraft minecraft{};
	long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (lastClickTime == 0) lastClickTime = milli;
	if ((milli - lastClickTime) < (1000 / nextCps)) return;

	if (GetAsyncKeyState(VK_LBUTTON) && 1) {
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		//CommonData::getInstance()->isCombat = true;
		PostMessageA(Renderer::get().renderContext.HandleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		PostMessageA(Renderer::get().renderContext.HandleWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

		lastClickTime = milli;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib((minAps), (maxAps));
		nextCps = distrib(gen);
	}

	if ((GetAsyncKeyState(VK_RBUTTON) && 1) && !minecraft.getMinecraft().thePlayer.get().isUsingItem()) {
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		PostMessageA(Renderer::get().renderContext.HandleWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		PostMessageA(Renderer::get().renderContext.HandleWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

		lastClickTime = milli;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib((minAps), (maxAps));
		nextCps = distrib(gen);
	}
}
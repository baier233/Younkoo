#include "TriggerBot.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <include_header.h>
#include <random>

long lastClickTime = 0;
int nextCps = 10;
int count = 0;
static int minAps = 10;
static int maxAps = 10;

TriggerBot::TriggerBot() :AbstractModule(xorstr_("TriggerBot"), Category::COMBAT, 'L')
{
	this->setToggle(false);

	this->addValue(FloatType, minCpsValue.get());
	this->addValue(FloatType, maxCpsValue.get());
}

TriggerBot& TriggerBot::getInstance()
{
	static TriggerBot instance = TriggerBot();
	return instance;
}

void TriggerBot::onEnable()
{

}

void TriggerBot::onDisable()
{

}

void TriggerBot::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	const auto handleWindow = Renderer::get().renderContext.HandleWindow;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto mouseOver = mc.getMouseOver();
	if (mouseOver.isTypeOfEntity()) {
		long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (lastClickTime == 0) lastClickTime = milli;
		if ((milli - lastClickTime) < (1000 / nextCps)) return;
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		//CommonData::getInstance()->isCombat = true;
		PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		PostMessageA(handleWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

		lastClickTime = milli;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib((*minCpsValue->getValuePtr()), (*maxCpsValue->getValuePtr()));
		nextCps = distrib(gen);
	}
}
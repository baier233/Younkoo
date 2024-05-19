#include "RightClicker.h"

RClick::RClick() : AbstractModule("RightClicker", Category::COMBAT)
{
	this->setToggle(false);

	this->addValue(FloatType, rightMinCpsValue);
	this->addValue(FloatType, rightMaxCpsValue);
	this->addValue(BoolType, blocksOnlyValue);
}

RClick& RClick::getInstance()
{
	static RClick instance = RClick();
	return instance;
}

void RClick::onEnable()
{

}

void RClick::onDisable()
{
}

void RClick::onUpdate()
{
}

#include "AbstractModule.h"

AbstractModule::AbstractModule(const char* ModName, Category Modcategory) :name(ModName), category(Modcategory), key(0), i_toggle(false) {}

AbstractModule::AbstractModule(const char* ModName, Category Modcategory, int k) :name(ModName), category(Modcategory), key(k), i_toggle(false) {}

AbstractModule::AbstractModule(const char* ModName, Category Modcategory, std::string describe) : name(ModName), category(Modcategory), desc(describe), key(0), i_toggle(false) {}

AbstractModule::AbstractModule(const char* ModName, Category Modcategory, std::string describe, int k) : name(ModName), category(Modcategory), desc(describe), key(k), i_toggle(false) {}

std::string AbstractModule::getName() {
	return this->name;
}

std::string AbstractModule::getDesc()
{
	return this->desc;
}

int& AbstractModule::getKey() {
	return this->key;
}

Category AbstractModule::getCategory() {
	return this->category;
}

void AbstractModule::toggle() {
	this->i_toggle = !this->i_toggle;
	this->onToggled();
}

void AbstractModule::onToggled() {
	if (this->i_toggle) {
		this->onEnable();
	}
	else {
		this->onDisable();
	}
}

bool AbstractModule::getToggle() {
	return this->i_toggle;
}

void AbstractModule::setToggle(bool _NEW) {
	if (_NEW == this->i_toggle)return;
	this->i_toggle = _NEW;
	this->onToggled();
}

void AbstractModule::enable() {
	this->setToggle(true);
}

void AbstractModule::disable() {
	this->setToggle(false);
}

void AbstractModule::setKeyCode(int keycode) {
	this->key = keycode;
}

void AbstractModule::onKeyEvent(int key) {
	if (this->getKey() == key)
		this->toggle();
}
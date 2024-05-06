#include <iostream>
#include <vector>
#include "ModuleManager.h"
ModuleManager::ModuleManager() {

}

void ModuleManager::getModule(Category c, std::vector<HMOD>* out_module) {
	out_module->clear();

	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (ToBaseModule(*iter)->getCategory() == c) {
			out_module->push_back(*iter);
		}
	}
}

AbstractModule* ModuleManager::getModule(std::string name) {
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (strcmp(ToBaseModule(*iter)->getName().c_str(), name.c_str()) == 0) {
			return ToBaseModule(*iter);
		}
	}
	std::cout << "Module not found!!!" << std::endl;
	return nullptr;
}

void ModuleManager::getModule(bool isenable, std::vector<HMOD>* out_module) {
	out_module->clear();
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (ToBaseModule(*iter)->getToggle() == isenable) {
			out_module->push_back(*iter);
		}
	}
}

void ModuleManager::ProcessKeyEvent(int key) {
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		ToBaseModule(*iter)->onKeyEvent(key);

	}
}

void ModuleManager::ProcessUpdate() {
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (ToBaseModule(*iter)->getToggle()) ToBaseModule(*iter)->onUpdate();
	}
}

std::vector<HMOD> ModuleManager::getMods()
{
	return this->modules;
}

bool ModuleManager::LoadModules()
{
	this->addModule<HUD>(&HUD::getInstance());
	return true;
}



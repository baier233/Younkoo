#include <iostream>
#include <vector>
#include "ModuleManager.h"

//Combat
#include "combat/AutoClicker.h"
#include "combat/TriggerBot.h"
#include "combat/AimAssist.h"
#include "combat/KillAura.h"

//Visual
#include "visual/HUD.h"
#include "visual/ESP.h"
#include "visual/NameTag.h"

//Player
#include "player/Eagle.h"
#include "player/Team.h"
#include "player/AutoTool.h"

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
	{/*Visual*/
		this->addModule<HUD>(&HUD::getInstance());
		this->addModule<ESP>(&ESP::getInstance());
		this->addModule<AimAssist>(&AimAssist::getInstance());
	}

	{/*Combat*/

		this->addModule<AutoClicker>(&AutoClicker::getInstance());
		this->addModule<TriggerBot>(&TriggerBot::getInstance());
		this->addModule<NameTag>(&NameTag::getInstance());
		this->addModule<KillAura>(&KillAura::getInstance());
	}

	{/*Player*/

		this->addModule<Eagle>(&Eagle::getInstance());
		this->addModule<Team>(&Team::getInstance());
		this->addModule<AutoTool>(&AutoTool::getInstance());
	}
	return true;
}



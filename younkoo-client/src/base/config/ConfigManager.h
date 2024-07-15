#pragma once
#include "../../utils/Singleton.hpp"
#include "../../ext/json.hpp"
#include <Windows.h>
#include "../features/modules/ModuleManager.h"
#include <fstream> 
class ConfigManager : public Singleton<ConfigManager>
{
public:
	void LoadConfig(std::string name);
	void SaveConfig(std::string name);
private:
	std::filesystem::path GetConfigPath();
};

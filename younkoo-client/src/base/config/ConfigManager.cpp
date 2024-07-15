#include "ConfigManager.h"

void ConfigManager::SaveConfig(std::string name)
{
	nlohmann::json jsonObject;

	for (void* mods : ModuleManager::get().getMods())
	{
		nlohmann::json config;
		AbstractModule* mod = (AbstractModule*)mods;
		config["Enabled"] = mod->getToggle();
		config["key"] = mod->getKey();
		if (!mod->getValues().empty()) {
			for (const auto& v : mod->getValues()) {
				nlohmann::json moduleSet;
				moduleSet["name"] = v.second->getName();
				auto& value = v.second;
				switch (v.first) {
				case BoolType:
					if (auto boolValue = dynamic_cast<BoolValue*>(value.get())) {
						moduleSet["value"] = boolValue->getValue();
					}
					break;
				case IntType:
					if (auto intValue = dynamic_cast<NumberValue*>(value.get())) {
						moduleSet["value"] = intValue->getValue();
					}
					break;
				case FloatType:
					if (auto floatValue = dynamic_cast<FloatValue*>(value.get())) {
						moduleSet["value"] = floatValue->getValue();
					}
					break;
				case ListType:
					if (auto listValue = dynamic_cast<ModeValue*> (value.get())) {
						moduleSet["value"] = listValue->getDescs()[listValue->getValue()];
					}
					break;
				default:
					break;
				}
				if (!moduleSet.empty() && !moduleSet.is_null())config["values"].push_back(moduleSet);
			}
		}
		jsonObject[mod->getName()] = config;
	}
	std::filesystem::path jsonFilePath = this->GetConfigPath() / name;

	try
	{
		std::ofstream jsonFile(jsonFilePath);
		jsonFile << jsonObject.dump(4); // 4 表示缩进级别
		jsonFile.close();
		std::cout << "JSON configuration file has been saved to: " << jsonFilePath << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occurred while saving the JSON configuration file: " << e.what() << std::endl;
	}

}
#include <utils/strutils.h>
void ConfigManager::LoadConfig(std::string name)
{
	std::filesystem::path jsonFilePath = this->GetConfigPath() / name;
	nlohmann::json jsonObject;
	try
	{
		std::ifstream jsonFile(jsonFilePath);
		jsonFile >> jsonObject;
		jsonFile.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occurred while reading the JSON configuration file: " << e.what() << std::endl;
		return;
	}
	try
	{
		for (const auto& [name, config] : jsonObject.items())
		{
			AbstractModule* mod = ModuleManager::get().getModule(name);
			if (mod)
			{
				mod->setToggle(config["Enabled"]);
				mod->setKeyCode(config["key"]);

				for (const auto& cv : config["values"])
				{

					for (const auto& [valueType, value] : mod->getValues())
					{
						auto jValueName = cv["name"].get<std::string>();
						auto valueName = value->getName();
						if (jValueName == valueName)
						{
							std::cout << "True :" << jValueName << " == " << valueName << std::endl;
							switch (valueType)
							{
							case BoolType:
							{
								BoolValue* pValue = dynamic_cast<BoolValue*>(value.get());
								*pValue->getValuePtr() = cv["value"].get<bool>();
								break;
							}
							case FloatType:
							{
								FloatValue* pValue = dynamic_cast<FloatValue*>(value.get());
								*pValue->getValuePtr() = cv["value"].get<float>();
								break;
							}
							case ListType:
							{
								{
									ModeValue* pValue = dynamic_cast<ModeValue*>(value.get());
									const std::string& modeDesc = cv["value"].get<std::string>();
									for (size_t i = 0; i < pValue->getModes().size(); i++)
									{
										if (pValue->getDescs()[i].find(modeDesc) != std::string::npos)
										{
											*pValue->getValuePtr() = i;
											break;
										}
									}
								}
							}
							break;
							default:
								break;
							}
						}
					}
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

std::filesystem::path ConfigManager::GetConfigPath()
{
	std::filesystem::path appDataPath = std::getenv("APPDATA");
	std::filesystem::path younkooPath = appDataPath / "younkoo";

	if (!std::filesystem::exists(younkooPath))
	{
		std::filesystem::create_directory(younkooPath);
	}
	return younkooPath;
}

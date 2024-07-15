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
				switch (v.first)
				{
				case BoolType: {
					BoolValue* pValue = static_cast<BoolValue*>(v.second.get());
					moduleSet["value"] = pValue->getValue();
					break;
				}
				case FloatType: {
					FloatValue* pValue = static_cast<FloatValue*>(v.second.get());
					moduleSet["value"] = pValue->getValue();
					break;
				}
				case ListType: {
					ModeValue* pValue = static_cast<ModeValue*>(v.second.get());
					moduleSet["value"] = pValue->getDescs()[pValue->getValue()];
					break;
				}
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
					if (value->getName().find(cv["name"]) != std::string::npos)
					{
						switch (valueType)
						{
						case BoolType:
						{
							BoolValue* pValue = static_cast<BoolValue*>(value.get());
							*pValue->getValuePtr() = cv["value"].get<bool>();
							break;
						}
						case FloatType:
						{
							FloatValue* pValue = static_cast<FloatValue*>(value.get());
							*pValue->getValuePtr() = cv["value"].get<float>();
							break;
						}
						case ListType:
						{
							{
								ModeValue* pValue = static_cast<ModeValue*>(value.get());
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

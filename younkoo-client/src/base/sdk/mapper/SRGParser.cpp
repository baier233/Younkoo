#include "SRGParser.h"



void SRGParser::Init(const unsigned char* srgBytes, size_t size, bool Reverse)
{
	std::string srgData(reinterpret_cast<const char*>(srgBytes), size);
	std::istringstream iss(srgData);
	std::string line;
	while (std::getline(iss, line)) {
		// 处理每一行数据
		std::istringstream lineStream(line);
		std::string type;
		lineStream >> type;
		if (type == "CL:") {
			std::string originalName, obfuscatedName;
			lineStream >> originalName >> obfuscatedName;
			if (Reverse) {
				classMappings[obfuscatedName] = originalName;
			}
			else {
				classMappings[originalName] = obfuscatedName;
			}
		}
		else if (type == "FD:") {
			std::string originalName, obfuscatedName;
			lineStream >> originalName >> obfuscatedName;
			if (Reverse) {
				fieldMappings[obfuscatedName] = originalName;
			}
			else {
				fieldMappings[originalName] = obfuscatedName;
			}
		}
		else if (type == "MD:") {
			std::string name, sig;
			lineStream >> name >> sig;
			if (Reverse) {
				std::string originalClass, originalDesc;
				lineStream >> originalClass >> originalDesc;
				std::string key = originalClass + "/" + originalDesc;
				methodMappings[key] = std::make_pair(name, sig);
			}
			else {
				std::string originalClass, originalDesc;
				lineStream >> originalClass >> originalDesc;
				std::string key = name + "/" + sig;
				methodMappings[key] = std::make_pair(originalClass, originalDesc);
			}
		}
	}
}
//#include "resources/maps/forge189.h"
//#include "resources/maps/vanilla189.h"
//#include "resources/maps/forge1181.h"
//#include "resources/maps/forge112.h"
//#include "resources/maps/vanilla112.h"
//TODO: Lack of Srg
void SRGParser::SetVersion(Versions ver)
{
	this->version = ver;
	//switch (ver) {
	//case Versions::FORGE_1_8_9:this->Init(forge189, forge189_size, false);
	//case Versions::VANILLA_1_8_9:this->Init(vanilla189, vanilla189_size, false);

	//case Versions::FORGE_1_18_1: this->Init(forge1181, forge1181_size, true);

	//case Versions::FORGE_1_12_2: this->Init(forge112, forge112_size, true);
	//case Versions::VANILLA_1_12_2: this->Init(vanilla112, vanilla112_size, true);

	//case Versions::BADLION_1_8_9:this->Init(vanilla189, vanilla189_size, false);
	//default:
	//	break;
	//}
}

Versions SRGParser::GetVersion() const
{
	return this->version;
}

std::string SRGParser::getObfuscatedFieldName(const std::string& originalClassName, const std::string& originalFieldName)
{
	if (version == Versions::MCP_1_8_9 or version == Versions::MCP_1_12_2 or version == Versions::MCP_1_18_1 or version == Versions::LUNAR_1_8_9 or version == Versions::LUNAR_1_12_2)return originalFieldName;
	std::string key = originalClassName + "/" + originalFieldName;
	if (fieldMappings.find(key) != fieldMappings.end()) {
		std::string obfuscatedName = fieldMappings[key];
		size_t lastSlashIndex = obfuscatedName.find_last_of("/");
		if (lastSlashIndex != std::string::npos) {
			obfuscatedName = obfuscatedName.substr(lastSlashIndex + 1);
		}
		std::cout << "WrapperField:" << originalFieldName << " Obfuscator:" << obfuscatedName << std::endl;
		return obfuscatedName;
	}
	return originalFieldName;
}

std::pair<std::string, std::string> SRGParser::getObfuscatedMethodName(const std::string& originalClassName, const std::string& originalMethodName, const std::string& methodDesc)
{
	if (version == Versions::MCP_1_8_9 or version == Versions::MCP_1_12_2 or version == Versions::MCP_1_18_1 or version == Versions::LUNAR_1_8_9 or version == Versions::LUNAR_1_12_2)	return std::make_pair(originalMethodName, methodDesc);
	std::string key = originalClassName + "/" + originalMethodName + "/" + methodDesc;
	//std::cout << key << std::endl;
	if (methodMappings.find(key) != methodMappings.end()) {
		std::pair<std::string, std::string> obfuscatedMethod = methodMappings[key];
		std::string obfuscatedClass = obfuscatedMethod.first;
		size_t lastSlashIndex = obfuscatedClass.find_last_of("/");
		if (lastSlashIndex != std::string::npos) {
			obfuscatedClass = obfuscatedClass.substr(lastSlashIndex + 1);
		}
		std::cout << "WrapperMethod:" << originalClassName << " Desc:" << methodDesc << " Obfuscator:" << obfuscatedClass << " ObfuscatorDesc:" << obfuscatedMethod.second << std::endl;
		return std::make_pair(obfuscatedClass, obfuscatedMethod.second);
	}
	return std::make_pair(originalMethodName, methodDesc);
}

std::string SRGParser::getObfuscatedClassName(const std::string& originalClassName)
{
	if (version == Versions::MCP_1_8_9 or version == Versions::MCP_1_12_2 or version == Versions::MCP_1_18_1 or version == Versions::LUNAR_1_8_9 or version == Versions::LUNAR_1_12_2)return originalClassName;
	if (classMappings.find(originalClassName) != classMappings.end()) {
		std::cout << "WrapperClass:" << originalClassName << " Obfuscator:" << classMappings[originalClassName] << std::endl;
		return classMappings[originalClassName];
	}
	return originalClassName;
}

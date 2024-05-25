#pragma once
#include <iostream>
#include <vector>
#include <array>

#include "xorstr.hpp"

enum ValueType {
	BoolType,
	IntType,
	FloatType,
	ListType,
	ColorType
};


class Value {
public:

	Value(const std::string& name) {
		m_name = name;
		m_desc = name;
		this->m_value = 0;
	}

	Value(const std::string& name, const std::string& desc) {
		m_name = name;
		m_desc = desc;
		this->m_value = 0;
	}

	std::string getName() {
		return m_name;
	}
	std::string getDesc() {
		return m_desc;
	}

	void setValue(int64_t value) {
		m_value = value;
	}

	int64_t* getPtr() {
		return (int64_t*)&m_value;
	}

	virtual ~Value() {

	}


protected:
	int64_t m_value;
	std::string m_name;
	std::string m_desc;
};

class NumberValue : public Value {
public:
	NumberValue(const std::string& name, int64_t value, int64_t min, int64_t max) : Value(name) {
		setValue(value);
		m_min = min;
		m_max = max;
	}
	NumberValue(const std::string& name, const std::string& desc, int64_t value, int64_t min, int64_t max) : Value(name, desc) {
		setValue(value);
		m_min = min;
		m_max = max;
	}

	int64_t getValue() { return m_value; }

	int64_t getMin() { return m_min; }
	int64_t getMax() { return m_max; }
private:
	int64_t m_min, m_max;
};

class BoolValue : public Value {
public:
	BoolValue(const std::string& name, bool enable) : Value(name) {
		setValue(enable);
	}

	BoolValue(const std::string& name, const std::string& desc, bool enable) : Value(name, desc) {
		setValue(enable);
	}

	bool getValue() {
		return m_value;
	}
	bool* getValuePtr()
	{
		return (bool*)getPtr();
	}
};
class FloatValue : public Value {
public:
	FloatValue(const std::string& name, float value, float min, float max) : Value(name) {

		setValue(*(int64_t*)&value); //对float的值进行特殊处理，以免被编译器视为类型转换
		m_min = min;
		m_max = max;
	}

	FloatValue(const std::string& name, const std::string& desc, float value, float min, float max) : Value(name, desc) {

		setValue(*(int64_t*)&value); //对float的值进行特殊处理，以免被编译器视为类型转换
		m_min = min;
		m_max = max;
	}

	float getValue() {
		return *(float*)&m_value; //对float的值进行特殊处理，以免被编译器视为类型转换
	}

	float* getValuePtr() {
		return (float*)getPtr();
	}

	float getMin() { return m_min; }
	float getMax() { return m_max; }

protected:
	float m_min, m_max;
};

class ModeValue : public Value {
public:
	//desc
	ModeValue(const std::string& name, std::vector<int> modes, std::vector<std::string> desc, int value) : Value(name) {
		setValue(value);
		m_modes = modes;
		m_desc = desc;
	}

	ModeValue(const std::string& name, const std::string& module_desc, std::vector<int> modes, const std::vector<std::string>& desc, int value) : Value(name, module_desc) {
		setValue(value);
		m_modes = modes;
		m_desc = desc;
	}

	int getValue() {
		return m_value;
	}

	std::vector<int> getModes() {
		return m_modes;
	};
	std::string* getDescs() {
		return m_desc.data();
	}

	int* getValuePtr()
	{
		return (int*)getPtr();
	}

private:
	std::vector<int> m_modes;
	std::vector<std::string> m_desc;
};

class ColorValue : public Value {
public:
	ColorValue(const std::string& name, float colorArray[4]) : Value(name) {
		m_colorArray = colorArray;
	}
	ColorValue(const std::string& name, const std::string& desc, float colorArray[4]) : Value(name, desc) {
		m_colorArray = colorArray;
	}

	float* getValue() {

		return m_colorArray;
	}

	float* getValuePtr() {
		return m_colorArray;
	}

private:
	float* m_colorArray;
};


#define DEFINE_FLOAT_VALUE(VAR_NAME,NAME,DESC,DEFAULT,MIN,MAX) std::unique_ptr<FloatValue> VAR_NAME = std::make_unique<FloatValue>(xorstr_(NAME), xorstr_(DESC), DEFAULT, MIN, MAX)

#define DEFINE_BOOL_VALUE(VAR_NAME,NAME,DESC,DEFAULT) std::unique_ptr<BoolValue> VAR_NAME = std::make_unique<BoolValue>(xorstr_(NAME), xorstr_(DESC), DEFAULT)
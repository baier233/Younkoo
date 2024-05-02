#pragma once
#include <iostream>
#include <vector>
#include <array>
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
	}

	std::string getName() {
		return m_name;
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
};

class NumberValue : public Value {
public:
	NumberValue(std::string name, int64_t value, int64_t min, int64_t max) : Value(name) {
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
	BoolValue(std::string name, bool enable) : Value(name) {
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
	FloatValue(std::string name, float value, float min, float max) : Value(name) {

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

private:
	float m_min, m_max;
};

class ModeValue : public Value {
public:
	//desc
	ModeValue(std::string name, std::vector<int> modes, const char** desc, int value) : Value(name) {
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
	const char** getDescs() {
		return m_desc;
	}

	int* getValuePtr()
	{
		return (int*)getPtr();
	}

private:
	std::vector<int> m_modes;
	const char** m_desc;
};

class ColorValue : public Value {
public:
	ColorValue(const std::string& name, float colorArray[4]) : Value(name) {
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
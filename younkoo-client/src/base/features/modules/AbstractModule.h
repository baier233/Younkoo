#pragma once
#include <string>
#include <windows.h>
#include "..\values\Value.h"

#define IsKeyBeingDown(KEYNONAME) ((GetAsyncKeyState(KEYNONAME)&0x8000)?1:0)

#define ToggleCheck if (!this->getToggle()) return
#define DefaultConstructor(_Class) _Class() = default
#define DefaultDeconstructor(_Class) ~_Class() = default
#define NoMoveConstructor(_Class) _Class(_Class&&) = delete
#define NoCopyConstructor(_Class) _Class(const _Class&) = delete
#define NoAssignOperator(_Class) _Class& operator=(const _Class&) = delete

enum class Category : unsigned int {
	CLICKER = 1,
	COMBAT,
	PLAYER,
	VISUAL
	//safeDestruct
};

class AbstractModule {
protected:
	std::vector<std::pair<ValueType, Value*>> values;
private:

	std::string name;
	std::string desc;
	int key = 0;
	Category category;
	bool i_toggle;
public:

	void addValue(ValueType type, Value* value)
	{
		values.push_back(std::pair<ValueType, Value*>(type, value));
	}

	std::vector<std::pair<ValueType, Value*>> getValues() {
		return values;
	}

	Value* getValueObjByName(const std::string& name) {
		for (int i = 0; i < values.size(); i++)
		{
			Value* crtObj = values[i].second;
			if (name.compare(crtObj->getName()) == 0)
			{
				return crtObj;
			}
		}
	}

	void toggle();

	void onToggled();

	std::string getName();

	std::string getDesc();

	bool getToggle();

	void setToggle(bool _NEW);

	void enable();

	void disable();

	int& getKey();

	void setKeyCode(int keycode);

	void onKeyEvent(int key);

	Category getCategory();

	virtual void onEnable() = 0;

	virtual void onDisable() = 0;

	virtual void onUpdate() = 0;

	//virtual void RenderMenu() = 0;

	AbstractModule(const char* ModName, Category Modcategory);
	AbstractModule(const char* ModName, Category Modcategory, std::string desc);
	AbstractModule(const char* ModName, Category Modcategory, int k);
	AbstractModule(const char* ModName, Category Modcategory, std::string desc, int k);

	virtual ~AbstractModule() = default;

	AbstractModule(AbstractModule&&) = delete;

	AbstractModule(const AbstractModule&) = delete;

	AbstractModule& operator=(const AbstractModule&) = delete;
};

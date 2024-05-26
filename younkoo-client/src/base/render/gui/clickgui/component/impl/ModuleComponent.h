#pragma once
#include "../Component.hpp"
#include <algorithm>
#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"
class ModuleComponent : public Component
{
public:
	ModuleComponent(AbstractModule* mod) {
		this->mod = mod;
		//TODO
		for (auto& values : mod->getValues())
		{
			switch (values.first)
			{
			default:
				break;
			}
		}
	}
	void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) override {
		//TODO

	}
	float x = 0, y = 0;
	float width = 145;
	float height, expandHeight = 0;
	bool clicking, expand;
private:
	AbstractModule* mod;
};


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

	}
private:
	AbstractModule* mod;
};


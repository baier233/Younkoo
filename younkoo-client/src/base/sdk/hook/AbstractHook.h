#pragma once
#include <vector>
#include "HookUtils.h"
struct HookManagerData
{

	std::vector<java_hotspot::method*>& methods_being_hooked;
	std::vector<java_hotspot::method*>& methods_dont_compile;
	std::vector<java_hotspot::instance_klass*>& klasses_dont_compile;
};
class AbstractHook
{
public:
	virtual void hook(const HookManagerData& container) = 0;
protected:
};


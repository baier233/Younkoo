#pragma once
#include "../AbstractHook.h"
class BedRendererHook : public AbstractHook
{
public:
	void hook(const HookManagerData& container) override;
};

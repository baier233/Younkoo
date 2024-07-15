#pragma once
#include "../AbstractHook.h"
class ClientPacketListenerHook : public AbstractHook
{
public:
	void hook(const HookManagerData& container) override;
private:
};


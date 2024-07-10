#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class Team : public AbstractModule
{
public:
	static Team& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	bool isSameTeam(const Wrapper::EntityPlayer& other);
protected:
	Team();
private:
};

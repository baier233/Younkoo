#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class KillAura : public AbstractModule
{
public:
	static KillAura& getInstance();
	void onEnable();
	void onDisable();
	void onRender2D(const EventRender2D& e);
	void onUpdate();
protected:

	DEFINE_FLOAT_VALUE(rangeValue, "Range", "Range.", 3.5f, 3.0f, 5.0f);
	DEFINE_FLOAT_VALUE(leftMinCpsValue, "Min CPS", "Min CPS", 8.0f, 1.0f, 20.0f);
	DEFINE_FLOAT_VALUE(leftMaxCpsValue, "Max CPS", "Max CPS", 14.0f, 1.0f, 20.0f);
	DEFINE_FLOAT_VALUE(fovValue, "Fov", "Fov.", 360.0f, 0.f, 360.f);

	DEFINE_BOOL_VALUE(autoBlockValue, "AutoBlock", "AutoBlock", false);
	DEFINE_BOOL_VALUE(keepSprintValue, "KeepSprint", "KeepSprint", false);
	std::shared_ptr<ModeValue> targetPriorityListMode = std::make_shared<ModeValue>("Target", std::vector<int>{ Distance, Health, Crosshair }, std::vector<std::string>{ "Distance", "Health", "Closest to Crosshair" }, Distance);
	std::shared_ptr<ModeValue> killauraMode = std::make_shared<ModeValue>("Mode", std::vector<int>{ Legit }, std::vector<std::string>{ "Legit" }, Legit);

	enum KILLAURAMODE {
		Legit,
		Normal
	};
	enum TARGETMODE {
		Distance,
		Health,
		Crosshair
	};
	KillAura();
private:

	bool pitchInfluenced = false;
	Math::Vector3D data;
	Math::Vector3D renderData;
};

#pragma once

#include "../AbstractModule.h"
#include "../../../Younkoo.hpp"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/event/Events.h>

#include <GL/glew.h>
#include <nanovg.h>
#include <memory>
class AimAssist : public AbstractModule
{
public:
	static AimAssist& getInstance();
	void onEnable();
	void onDisable();
	void onRender2D(const EventRender2D& e);
	void onUpdate();
protected:

	DEFINE_FLOAT_VALUE(fovValue, "Fov", "Fov.", 35.0f, 1, 360.f);
	DEFINE_FLOAT_VALUE(aimDistanceValue, "Aim Distance", "Aim Distance..", 4.f, 1.0f, 8.0f);
	DEFINE_FLOAT_VALUE(smoothValue, "Smooth", "Smooth..", 15.f, 1.0f, 90.0f);
	DEFINE_FLOAT_VALUE(adaptiveOffsetValue, "Adaptive Offset", "Adaptive Offset", 3, 0.1f, 15.f);
	DEFINE_FLOAT_VALUE(randomYawValue, "RandomYaw Offset", "RandomYaw Offset", 2, 0.0f, 10.0f);
	DEFINE_FLOAT_VALUE(randomPitchValue, "RandomPitch Offset", "RandomPitch Offset", .075f, 0.0f, 1.0f);
	DEFINE_BOOL_VALUE(visibilityCheckValue, "VisibilityCheck", "VisibilityCheck", true);
	DEFINE_BOOL_VALUE(aimKeyValue, "AimKey", "AimKey", true);
	DEFINE_BOOL_VALUE(adaptiveValue, "Adaptive", "Adaptive", true);
	DEFINE_BOOL_VALUE(aimAssistFeedbackValue, "AimAssistFeedback", "AimAssistFeedback", true);
	DEFINE_BOOL_VALUE(fovCircleValue, "FovCircle", "FovCircle", true);
	std::shared_ptr<ModeValue> targetPriorityValue = std::make_shared<ModeValue>("TargetPriority", std::vector<int>{ Distance, Health, Crosshair }, std::vector<std::string>{ "Distance", "Health", "Closest to Crosshair" }, Crosshair);

	enum TARGETMODE {
		Distance,
		Health,
		Crosshair
	};
	AimAssist();
private:

	bool pitchInfluenced = false;
	Math::Vector3D data;
	Math::Vector3D renderData;
};

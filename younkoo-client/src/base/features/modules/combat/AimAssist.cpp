#include "AimAssist.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>
#include <base/features/modules/player/Team.h>




AimAssist::AimAssist() :AbstractModule(xorstr_("AimAssist"), Category::COMBAT)
{
	this->addValue(FloatType, fovValue);
	this->addValue(FloatType, aimDistanceValue);
	this->addValue(FloatType, smoothValue);
	this->addValue(FloatType, adaptiveOffsetValue);
	this->addValue(FloatType, randomYawValue);
	this->addValue(FloatType, randomPitchValue);
	this->addValue(BoolType, visibilityCheckValue);
	this->addValue(BoolType, aimKeyValue);
	this->addValue(BoolType, adaptiveValue);
	this->addValue(BoolType, aimAssistFeedbackValue);
	this->addValue(BoolType, fovCircleValue);
	this->addValue(ListType, targetPriorityValue);
	REGISTER_EVENT(EventRender2D, AimAssist::onRender2D);
}


AimAssist& AimAssist::getInstance()
{
	static AimAssist instance = AimAssist();
	return instance;
}

void AimAssist::onEnable()
{
}

void AimAssist::onDisable()
{

}

void AimAssist::onRender2D(const EventRender2D& e)
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto fov = fovValue->getValue();
	auto fovCircle = fovCircleValue->getValue();

	auto vg = NanoVGHelper::Context;

	auto [screenSizeX, screenSizeY] = Renderer::get().renderContext.winSize;


	if (fovCircle) {
		float radAimbotFov = (float)(fov * PI / 180);
		float radViewFov = (float)(CommonData::get().fov * PI / 180);
		float circleRadius = tanf(radAimbotFov / 2) / tanf(radViewFov / 2) * screenSizeX / 1.7325;
		nvgBeginPath(vg);
		nvgCircle(vg, screenSizeX / 2, screenSizeY / 2, circleRadius);
		nvgStrokeColor(vg, nvgRGBA(25, 255, 255, 75));
		nvgStrokeWidth(vg, 1);
		nvgStroke(vg);
	}

	if (aimAssistFeedbackValue->getValue()) {
		if (data.x == NAN) return;

		auto renderPos = CommonData::get().renderPos;
		const auto viewport = std::array<int, 4>{0, 0, screenSizeX, screenSizeY};
		auto result = Math::W2S::world2Screen(Math::structToArray(CommonData::get().modelView), structToArray(CommonData::get().projection), data, viewport, 1);

		if (Math::Vector2 w2s{ result[0],result[1] }; result[2] > 0 && result[2] < 1) {

			// Begin drawing with NanoVG
			nvgBeginPath(vg);
			nvgMoveTo(vg, screenSizeX / 2, screenSizeY / 2);
			if (pitchInfluenced) {
				nvgLineTo(vg, w2s.x, w2s.y);
			}
			else {
				nvgLineTo(vg, w2s.x, screenSizeY / 2);
			}
			nvgStrokeColor(vg, nvgRGBA(25, 255, 255, 255));
			nvgStrokeWidth(vg, 1.5);
			nvgStroke(vg);
		}
	}
}
static auto calcRot = [](Wrapper::EntityPlayerSP& thePlayer, Wrapper::Entity& other, float renderPartialTicks) -> Math::Vector2 {
	Math::Vector3D headPos = thePlayer.getPosition() + Math::Vector3D{ 0,thePlayer.getEyeHeight(),0 };
	auto eyePos = other.getPosition(renderPartialTicks) + Math::Vector3D{ 0,other.getEyeHeight(),0 };

	double relativePosX = eyePos.x - headPos.x;
	double relativePosY = eyePos.y - headPos.y;
	double relativePosZ = eyePos.z - headPos.z;
	double distance = std::sqrt(relativePosX * relativePosX + relativePosZ * relativePosZ);
	auto targetPitchRot = Math::wrapAngleTo180((float)(-(std::atan2(relativePosY, distance) * (double)(180.f / (float)PI))));
	auto targetYawRot = Math::wrapAngleTo180((float)((std::atan2(relativePosZ, relativePosX) * (double)(180.f / (float)PI)) - 90.0));
	return { targetYawRot,targetPitchRot };
	};

void AimAssist::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	auto aimDistance = aimDistanceValue->getValue();
	auto aimKey = aimKeyValue->getValue();
	auto fov = fovValue->getValue();
	auto randomYaw = randomYawValue->getValue();
	auto randomPitch = randomPitchValue->getValue();
	auto adaptive = adaptiveValue->getValue();
	auto adaptiveOffset = adaptiveOffsetValue->getValue();
	auto smooth = smoothValue->getValue();
	auto fovCircle = fovCircleValue->getValue();

	if ((aimKey && (!GetAsyncKeyState(VK_LBUTTON) && 1))) {
		AimAssist::data = {};
		return;
	}

	float renderPartialTicks = CommonData::get().renderPartialTicks;
	auto mc = Wrapper::Minecraft::getMinecraft();

	auto level = mc.getWorld();
	auto players = level.getPlayerList();

	auto thePlayer = mc.getPlayer();
	Math::Vector3D headPos = thePlayer.getPosition() + Math::Vector3D{ 0, thePlayer.getEyeHeight(), 0 };
	auto currentLookAngles = thePlayer.getAngles();

	Wrapper::EntityPlayer target{};
	float finalDist = FLT_MAX;
	float finalDiff = 370;
	float finalHealth = FLT_MAX;


	float realAimDistance = aimDistance;

	static auto randomFloat = [](float min, float max)
		{
			float f = (float)rand() / RAND_MAX;
			return min + f * (max - min);
		};

	for (auto& player : players)
	{
		if (player.isNULL()) continue;
		if (player.isEqualTo(thePlayer)) continue;

		if (player.getDisplayName().length() < 0) return;

		float playerHeight = player.getEyeHeight();

		Math::Vector2 difference = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - Math::getAngles(headPos, player.getPosition() + Math::Vector3D(0, playerHeight, 0)).Invert());
		if (difference.x < 0) difference.x = -difference.x;
		if (difference.y < 0) difference.y = -difference.y;
		Math::Vector2 differenceFoot = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - Math::getAngles(headPos, player.getPosition()).Invert());
		if (differenceFoot.x < 0) differenceFoot.x = -differenceFoot.x;
		if (differenceFoot.y < 0) differenceFoot.y = -differenceFoot.y;

		float angleYaw = currentLookAngles.x - difference.x;

		Math::Vector3D diff = thePlayer.getPosition() - player.getPosition();
		float dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));
		if ((abs(difference.x) <= fov) && dist <= realAimDistance)
		{
			float health = player.getHealth();
			switch (this->targetPriorityValue->getValue())
			{
			case 1:
				if (finalHealth > health)
				{
					target = player;
					finalHealth = health;
				}
				break;

			case 2:
				if (finalDiff > difference.x)
				{
					target = player;
					finalDiff = difference.x;
				}
				break;
			default:
				if (finalDist > dist)
				{
					target = player;
					finalDist = (float)dist;
				}
			}
		}
	}

	if (target.isNULL()) {
		data = {};
		return;
	}

	if (Team::getInstance().isSameTeam(target))
	{
		data = {};
		return;
	}

	Math::Vector3D ePos = target.getPosition();
	Math::Vector3D eRenderPos = target.getPosition(renderPartialTicks);

	float eHeight = target.getEyeHeight();
	Math::Vector3D eHeadPos = ePos + Math::Vector3D(0, eHeight, 0);
	Math::Vector3D eRenderHeadPos = eRenderPos + Math::Vector3D(0, eHeight, 0);

	Math::Vector2 anglesFoot = Math::getAngles(headPos, ePos);
	Math::Vector2 anglesHead = Math::getAngles(headPos, eHeadPos);

	Math::Vector2 difference = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - anglesHead.Invert());
	Math::Vector2 differenceFoot = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - anglesFoot.Invert());


	float offset = randomFloat(-randomYaw, randomYaw);
	if (adaptive) {
		if ((GetAsyncKeyState('D') & 0x8000) && !(GetAsyncKeyState('A') & 0x8000)) {
			offset -= adaptiveOffset;
		}

		if ((GetAsyncKeyState('A') & 0x8000) && !(GetAsyncKeyState('D') & 0x8000)) {
			offset += adaptiveOffset;
		}
	}
	//auto rot = calcRot(thePlayer, target, renderPartialTicks);


	float targetYaw = currentLookAngles.x + ((difference.x + offset) / smooth);

	Math::Vector3D renderPos = CommonData::get().renderPos;

	if (currentLookAngles.y > anglesFoot.y || currentLookAngles.y < anglesHead.y) {
		float targetPitchFoot = currentLookAngles.y + (differenceFoot.y / smooth);
		float targetPitchHead = currentLookAngles.y + (difference.y / smooth);

		float diffFoot = currentLookAngles.y - targetPitchFoot;
		float diffHead = currentLookAngles.y - targetPitchHead;
		diffFoot = diffFoot < 0 ? -diffFoot : diffFoot;
		diffHead = diffHead < 0 ? -diffHead : diffHead;

		float targetPitch;
		if (diffFoot > diffHead)
		{
			targetPitch = targetPitchHead;
			data = renderPos - Math::Vector3D{ 0, 0.21, 0 } - eRenderHeadPos;
		}
		else
		{
			targetPitch = targetPitchFoot;
			data = renderPos - Math::Vector3D{ 0, 0.23, 0 } - eRenderPos;
		}
		pitchInfluenced = true;
		targetPitch += randomFloat(-randomPitch, randomPitch);
		//thePlayer.setAngles(rot);
		thePlayer.setAngles(Math::Vector2(targetYaw, targetPitch));
	}
	else {
		data = renderPos - ePos;
		pitchInfluenced = false;
		//thePlayer.setAngles(rot);
		thePlayer.setAngles(Math::Vector2(targetYaw, currentLookAngles.y + randomFloat(-randomPitch, randomPitch)));
	}
}


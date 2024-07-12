#include "ESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <vector>
#include <map>
#include <ranges>
#include <array>

static std::array<int, 4> viewport{};

static std::vector<EntityData> entitiesToRender[2]{ {},{} };
static int currentBufferIndex = 0;

ESP::ESP() : AbstractModule(xorstr_("ESP"), Category::VISUAL) {
	REGISTER_EVENT(EventRender3D, ESP::onRender3D);
	REGISTER_EVENT(EventRender2D, ESP::onRender);
}

ESP& ESP::getInstance() {
	static ESP instance;
	return instance;
}

void ESP::onEnable() {}

void ESP::onDisable() {}

void ESP::onUpdate() {
	ToggleCheck;
}

#include <utils/Wstr.h>

void ESP::onRender(const EventRender2D& e) {
	ToggleCheck;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	if (entitiesToRender[nextBufferIndex].empty()) return;
	currentBufferIndex = nextBufferIndex;
	for (const auto& entity : entitiesToRender[currentBufferIndex]) {
		//auto entityName = wstr::toString(entity.name);
		//auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, entityName, NanoVGHelper::fontHarmony, 30);
		//NanoVGHelper::nvgTextW(vg, entityName, entity.name_pos.x - bounds.first / 2, entity.name_pos.y - bounds.second / 2, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
		NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, 2.f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
		NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, 1.f, NanoVGHelper::rgbaToColor(255, 255, 255, 255));
	}
}

#include <format>
#include <utils/Misc.hpp>

void ESP::onRender3D(const EventRender3D& e) {
	ToggleCheck;
	if (NanoGui::available) return;

	const auto& renderContext = Renderer::get().renderContext;
	viewport = { 0, 0, renderContext.winSize.first, renderContext.winSize.second };

	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;

	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();

	std::vector<EntityData> newEntities;

	for (auto& player : players) {
		auto postion = player.getPosition(e.TICK_DELTA);
		/*RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;*/

		auto renderPos = postion - e.CAMERA_POS;
		auto entityHeight = player.getHeight() + 0.15f;
		auto entityWidth = player.getWidth();

		using namespace Math;
		std::array<Vector3D, 10> posArray = {
			renderPos,
			renderPos - Vector3D{0, -entityHeight, 0}, // Over the head
			renderPos - Vector3D{entityWidth, 0, 0}, // In the middle to the left
			renderPos - Vector3D{-entityWidth, 0, 0}, // In the middle to the right
			renderPos - Vector3D{0, 0, entityWidth}, // In the middle to the back
			renderPos - Vector3D{0, 0, -entityWidth}, // In the middle to the front
			renderPos - Vector3D{entityWidth / 1.388888, 0, entityWidth}, // Middle left
			renderPos - Vector3D{-entityWidth / 1.388888, 0, -entityWidth}, // Middle right
			renderPos - Vector3D{-entityWidth / 1.388888, 0, entityWidth}, // Middle back
			renderPos - Vector3D{entityWidth / 1.388888, 0, -entityWidth} // Middle front
		};

		bool ok = true;
		float leftPoint = FLT_MAX;
		float topPoint = FLT_MAX;
		float rightPoint = FLT_MIN;
		float bottomPoint = FLT_MIN;

		for (const auto& pos : posArray) {
			auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), pos, viewport, 1);
			Vector2 point{ result[0], result[1] };

			if (result[2] > 0 && result[2] < 1) {
				leftPoint = std::min(point.x, leftPoint);
				topPoint = std::min(point.y, topPoint);
				rightPoint = std::max(point.x, rightPoint);
				bottomPoint = std::max(point.y, bottomPoint);
			}
			else {
				ok = false;
				break;
			}
		}

		if (ok) {
			auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), Vector3D(renderPos.x, renderPos.y + entityHeight + 0.3f, renderPos.z), viewport, 1);

			newEntities.push_back(EntityData{
				.name = player.getDisplayName(),
				.name_pos = Vector2(result[0], result[1]),
				.top = topPoint,
				.bottom = bottomPoint,
				.left = leftPoint,
				.right = rightPoint
				});
		}
	}
	entitiesToRender[currentBufferIndex] = {};
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	entitiesToRender[nextBufferIndex] = std::move(newEntities);
	//currentBufferIndex = nextBufferIndex;
}

#include "ItemESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <vector>
#include <map>
#include <ranges>
#include <array>



ItemESP::ItemESP() : AbstractModule(xorstr_("ItemESP"), Category::VISUAL) {
	REGISTER_EVENT(EventRender3D, ItemESP::onRender3D);
	REGISTER_EVENT(EventRender2D, ItemESP::onRender);
	this->addValue(BoolType, displayerNameValue);
	this->addValue(ListType, modeValue);
}

ItemESP& ItemESP::getInstance() {
	static ItemESP instance;
	return instance;
}

void ItemESP::onEnable() {}

void ItemESP::onDisable() {}

void ItemESP::onUpdate() {
	ToggleCheck;
}

#include <utils/Wstr.h>

#include <format>
#include <utils/Misc.hpp>
#include <wrapper/net/minecraft/entity/item/EntityItem.h>
#include <utils/render.h>
#include "../common/CommonData.h"
#include "ESP.h"
static std::vector<std::pair<std::pair<Math::Vector2D, Math::Vector2D>, int>> linesToDraw[2]{ {},{ } };
static std::vector<std::pair<Math::Box<double>, int>> boxesToDraw[2]{ {},{ } };
static std::vector<std::pair<EntityData, int >> entites2DToDraw[2]{ {},{ } };
static int currentBufferIndex = 0;

void ItemESP::onRender(const EventRender2D& e) {
	{
		ToggleCheck;
		if (NanoGui::available) return;

		static auto& vg = NanoVGHelper::Context;

		if (modeValue->getValue() == PSEUDO3D) {

			int nextBufferIndex = (currentBufferIndex + 1) % 2;
			if (linesToDraw[nextBufferIndex].empty()) return;
			currentBufferIndex = nextBufferIndex;

			for (const auto& [pair, color] : linesToDraw[currentBufferIndex]) {
				const auto& [begin, end] = pair;
				auto rgbaColor = NanoVGHelper::colorToRGB255(color);
				rgbaColor.a = 0XFF;
				NanoVGHelper::drawLine(vg, begin.x, begin.y, end.x, end.y, 1, NanoVGHelper::rgbaToColor(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a));
			}
		}


		if (modeValue->getValue() == MODE3D) {
			int nextBufferIndex = (currentBufferIndex + 1) % 2;
			if (boxesToDraw[nextBufferIndex].empty()) return;
			currentBufferIndex = nextBufferIndex;

			glMatrixMode(GL_PROJECTION);
			glLoadMatrixf(Math::structToArray(CommonData::get().projection).data());
			glMatrixMode(GL_MODELVIEW);
			glLoadMatrixf(Math::structToArray(CommonData::get().modelView).data());

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glLineWidth(2.0f);
			glDisable(GL_TEXTURE_2D);

			glDisable(GL_DEPTH_TEST);
			glDepthMask(GL_FALSE);
			glEnable(GL_LINE_SMOOTH);
			for (auto& [box, color] : boxesToDraw[currentBufferIndex])
			{
				auto rgbaColor = NanoVGHelper::colorToRGB(color);
				rgbaColor.a = 0.15f;
				utils::render::drawFilledBox(box, rgbaColor);
			}
			glDisable(GL_LINE_SMOOTH);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);
			glDisable(GL_BLEND);
		}
		if (modeValue->getValue() == MODE2D)
		{
			int nextBufferIndex = (currentBufferIndex + 1) % 2;
			if (entites2DToDraw[nextBufferIndex].empty()) return;
			currentBufferIndex = nextBufferIndex;
			for (const auto& [entity, color] : entites2DToDraw[currentBufferIndex]) {
				auto entityName = wstr::toString(entity.name);
				auto rgbaColor = NanoVGHelper::colorToRGB255(color);
				rgbaColor.a = 0XFF;
				auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, entityName, NanoVGHelper::fontHarmony, 15);
				if (displayerNameValue->getValue()) NanoVGHelper::nvgTextW(vg, entityName, entity.name_pos.x - bounds.first / 2, entity.name_pos.y - bounds.second / 2, NanoVGHelper::fontHarmony, 15, nvgRGBA(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a));
				NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, 2.f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
				NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, 1.f, NanoVGHelper::rgbaToColor(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a));
			}

		}
		return;
	}
	// Check if the ESP feature is toggled on

}

void ItemESP::onRender3D(const EventRender3D& e) {
	{
		ToggleCheck;
		if (NanoGui::available) return;

		const auto& renderContext = Renderer::get().renderContext;
		std::array<int, 4> viewport = { 0, 0, renderContext.winSize.first, renderContext.winSize.second };

		auto mc = Wrapper::Minecraft::getMinecraft();
		if (!mc.getObject()) return;

		auto level = mc.getWorld();
		auto entites = level.getEntityList();
		auto& renderer = Renderer::get();

		std::vector < std::pair<std::pair<Math::Vector2D, Math::Vector2D>, int>> newLines;
		std::vector<std::pair<Math::Box<double>, int>> newBoxes;
		std::vector<std::pair<EntityData, int>> newEntities;

		auto mode = modeValue->getValue();
		for (auto& entity : entites) {
			if (!JNI::get_env()->IsInstanceOf(entity.getObject(), Wrapper::EntityItem::klass())) continue;
			auto postion = entity.getPosition(e.TICK_DELTA);

			auto renderPos = postion - e.CAMERA_POS;

			using namespace Math;
			auto height = entity.getHeight();
			auto width = entity.getWidth() / 2.f;
			Box<double> box{ renderPos.x - static_cast<double>(width), renderPos.y, renderPos.z - static_cast<double>(width), renderPos.x + static_cast<double>(width), renderPos.y + static_cast<double>(height), renderPos.z + static_cast<double>(width) };
			Wrapper::EntityItem itemEntity(*entity.instance.get());
			auto color = itemEntity.getItemStack().getColorBasedOnRarity();

			if (mode == MODE3D) newBoxes.push_back(std::make_pair(box, color));



			if (mode == PSEUDO3D)
			{

				auto minX = box.minX;
				auto minY = box.minY;
				auto minZ = box.minZ;
				auto maxX = box.maxX;
				auto maxY = box.maxY;
				auto maxZ = box.maxZ;

				std::vector<std::array<Math::Vector3D, 4>> faces{

					//front
					{Math::Vector3D{minX, minY, minZ}, Math::Vector3D{maxX, minY, minZ}, Math::Vector3D{maxX, maxY, minZ}, Math::Vector3D{minX, maxY, minZ}},

					//back
					{Math::Vector3D{minX, minY, maxZ}, Math::Vector3D{maxX, minY, maxZ}, Math::Vector3D{maxX, maxY, maxZ}, Math::Vector3D{minX, maxY, maxZ}},

					//left
					{Math::Vector3D{minX, minY, minZ}, Math::Vector3D{minX, maxY, minZ}, Math::Vector3D{minX, maxY, maxZ}, Math::Vector3D{minX, minY, maxZ}},

					//right
					{Math::Vector3D{maxX, minY,minZ}, Math::Vector3D{maxX, maxY, minZ}, Math::Vector3D{maxX, maxY, maxZ}, Math::Vector3D{maxX, minY, maxZ}},

					//top
					{Math::Vector3D{minX, maxY, minZ}, Math::Vector3D{maxX, maxY, minZ}, Math::Vector3D{maxX, maxY, maxZ}, Math::Vector3D{minX, maxY, maxZ}},

					//bottom
					{Math::Vector3D{minX, minY, minZ}, Math::Vector3D{maxX, minY, minZ}, Math::Vector3D{maxX, minY, maxZ}, Math::Vector3D{minX, minY, maxZ}},
				};
				for (auto& face : faces) {
					bool ok = true;
					std::vector<Math::Vector2D> projected;
					for (auto& pos : face)
					{
						auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), pos, viewport, 1);
						Vector2D point{ result[0], result[1] };
						if (result[2] > 0 && result[2] < 1) {
							projected.push_back(point);
						}
						else {
							ok = false;
							break;
						}
					}

					if (ok)
					{
						newLines.push_back(std::make_pair(std::make_pair(Math::Vector2D{ projected[0].x,projected[0].y }, Math::Vector2D{ projected[1].x,projected[1].y }), color));
						newLines.push_back(std::make_pair(std::make_pair(Math::Vector2D{ projected[1].x,projected[1].y }, Math::Vector2D{ projected[2].x,projected[2].y }), color));
						newLines.push_back(std::make_pair(std::make_pair(Math::Vector2D{ projected[2].x,projected[2].y }, Math::Vector2D{ projected[3].x,projected[3].y }), color));
						newLines.push_back(std::make_pair(std::make_pair(Math::Vector2D{ projected[3].x,projected[3].y }, Math::Vector2D{ projected[0].x,projected[0].y }), color));
					}
				}
			}
			else {
				auto entityHeight = entity.getHeight() + 0.15f;
				auto entityWidth = entity.getWidth();

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
					auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), Vector3D(renderPos.x, renderPos.y + entityHeight + 0.15f, renderPos.z), viewport, 1);

					newEntities.push_back(std::make_pair(EntityData{
						.name = entity.getDisplayName(),
						.name_pos = Vector2(result[0], result[1]),
						.top = topPoint,
						.bottom = bottomPoint,
						.left = leftPoint,
						.right = rightPoint
						}, color));
				}
			}
			//continue;

		}

		linesToDraw[currentBufferIndex] = {};
		boxesToDraw[currentBufferIndex] = {};
		entites2DToDraw[currentBufferIndex] = {};
		int nextBufferIndex = (currentBufferIndex + 1) % 2;

		linesToDraw[nextBufferIndex] = std::move(newLines);
		boxesToDraw[nextBufferIndex] = std::move(newBoxes);
		entites2DToDraw[nextBufferIndex] = std::move(newEntities);
	}
	return;

}
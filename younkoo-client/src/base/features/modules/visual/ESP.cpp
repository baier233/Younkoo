#include "ESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <vector>
#include <map>


std::array<int, 16> viewport{};
struct EntityData
{
	std::string name;
	Math::Vector2 name_pos;
	float top;
	float bottom;
	float left;
	float right;
};
static std::vector<EntityData> entitiesToRender;

ESP::ESP() :AbstractModule(xorstr_("ESP"), Category::VISUAL)
{
	REGISTER_EVENT(EventRender3D, ESP::onRender3D);
	REGISTER_EVENT(EventRender2D, ESP::onRender);
}


ESP& ESP::getInstance()
{
	static ESP instance = ESP();
	return instance;
}

void ESP::onEnable()
{
}

void ESP::onDisable()
{
}

void ESP::onUpdate()
{
	ToggleCheck;
}
#include <utils/Wstr.h>

void ESP::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;
	for (const auto& entity : entitiesToRender)
	{
		
		auto entityName = wstr::toString(entity.name);
		auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, entityName, NanoVGHelper::fontHarmony, 30);
		NanoVGHelper::nvgTextW(vg, entityName, entity.name_pos.x / renderer.renderContext.devicePixelRatio - bounds.first / 2, entity.name_pos.y / renderer.renderContext.devicePixelRatio - bounds.second / 2, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));


		NanoVGHelper::drawRect(vg, entity.left, entity.top, entity.right- entity.left, entity.bottom - entity.top, NanoVGHelper::rgbaToColor(255,255,255,255));
	}
}

#include <format>
void ESP::onRender3D(const EventRender3D& e)
{
	ToggleCheck;
	if (NanoGui::available) return;
	glGetIntegerv(GL_VIEWPORT, viewport.data());
	/*
	currentContext = (Context{
		.projection = e.PROJECTION_MATRIX ,
		.modelView = e.MODLEVIEW_MATRIX,
		.cameraPos = e.CAMERA_POS,
		.guiScale = e.GUI_SCALE,
		.renderDetla = e.TICK_DELTA,
		});*/


	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;
	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();

	decltype(entitiesToRender) entites;


	for (auto& player : players)
	{

		//if (player.isEqualTo(mc.getPlayer())) continue;

		auto postion = player.getPosition(e.TICK_DELTA);

		RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;


		auto renderPos = postion - e.CAMERA_POS;


		{

			auto entityHeight = player.getHeight() /2 + 0.2f;
			auto entityWidth = player.getWidth() /2;
			auto entityWidthHalf = player.getWidth() / 2;


			using namespace Math;
			Vector3D top{ renderPos - Vector3D{0,  - entityHeight *2, 0} }; // Over the head
			Vector3D left{ (renderPos - Vector3D{entityWidth, 0, 0}) }; // In the middle to the left
			Vector3D right{ (renderPos - Vector3D{-entityWidth, 0, 0}) }; // In the middle to the right
			Vector3D back{ (renderPos - Vector3D{0, 0, entityWidth}) }; // In the middle to the back
			Vector3D front{ (renderPos - Vector3D{0, 0, -entityWidth}) }; // And in the middle to the front

			entityWidth /= 1.388888;
			Vector3D left2{ (renderPos - Vector3D{entityWidth, 0, entityWidth}) }; // In the middle to the left
			Vector3D right2{ (renderPos - Vector3D{-entityWidth, 0, -entityWidth}) }; // In the middle to the right
			Vector3D back2{ (renderPos - Vector3D{-entityWidth, 0, entityWidth}) }; // In the middle to the back
			Vector3D front2{ (renderPos - Vector3D{entityWidth, 0, -entityWidth})  }; // And in the middle to the front



			std::array<decltype(renderPos), 10> posArray = { renderPos, top, left, right, back, front, left2, right2,back2, front2 };
			bool ok = true;

			float leftPoint = FLT_MAX;
			float topPoint = FLT_MAX;
			float rightPoint = FLT_MIN;
			float bottomPoint = FLT_MIN;

			for (int i = 0 ; i < posArray.size();i++)
			{
				auto result = Math::W2S::world2Screen(
					Math::structToArray(e.MODLEVIEW_MATRIX),
					Math::structToArray(e.PROJECTION_MATRIX),
					posArray[i],
					/*e.GUI_SCALE*/ 1
				);
				Math::Vector2D point{};
				if (result[2] > 0 && result[2] < 1)
				{

					//points.push_back(point);
					point = { result[0],result[1] };
					//std::cout << "Point(cpp) : {" << point.x << "," << point.y << "}" << std::endl;
					leftPoint = fmin(point.x, leftPoint);
					topPoint = fmin(point.y, topPoint);
					rightPoint = fmax(point.x, rightPoint);
					bottomPoint = fmax(point.y, bottomPoint);
					//entites.push_back(std::make_pair(player.getDisplayName(), point));

				}
				else {
					ok = false;
					break;
				}
			}

			if (ok)
			{
				auto result = Math::W2S::world2Screen(
					Math::structToArray(e.MODLEVIEW_MATRIX),
					Math::structToArray(e.PROJECTION_MATRIX),
					Math::Vector3D(renderPos.x,top.y + 0.3f,renderPos.z ),
					/*e.GUI_SCALE*/ 1
				);

				entites.push_back(EntityData{
					.name = player.getDisplayName(),
					.name_pos = Math::Vector2(result[0],result[1]),
					.top = topPoint,
					.bottom = bottomPoint,
					.left = leftPoint,
					.right = rightPoint
					});
			}


			
		}





		//std::cout << "Camera Pos : { " << std::format("{},{},{}", e.CAMERA_POS.x, e.CAMERA_POS.y, e.CAMERA_POS.z) << "}" << std::endl;
		//std::cout << "modelView :" << arrayToString(Math::structToVector(e.MODLEVIEW_MATRIX)) << std::endl;
		//std::cout << "projection :" << arrayToString(Math::structToVector(e.PROJECTION_MATRIX)) << std::endl;
		
	}
	entitiesToRender = entites;
}

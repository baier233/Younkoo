#include "NameTag.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <vector>
#include <map>


static std::array<int, 4> viewport{};

static std::vector < std::pair<std::string, Math::Vector2D>> entitiesToRender[2]{ {},{} };
static int currentBufferIndex = 0;
NameTag::NameTag() :AbstractModule(xorstr_("NameTag"), Category::VISUAL)
{
	REGISTER_EVENT(EventRender3D, NameTag::onRender3D);
	REGISTER_EVENT(EventRender2D, NameTag::onRender);
}


NameTag& NameTag::getInstance()
{
	static NameTag instance = NameTag();
	return instance;
}

void NameTag::onEnable()
{
}

void NameTag::onDisable()
{
}

void NameTag::onUpdate()
{
	ToggleCheck;







}
#include <utils/Wstr.h>

void NameTag::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	if (entitiesToRender[nextBufferIndex].empty()) return;
	currentBufferIndex = nextBufferIndex;
	for (const auto& entity : entitiesToRender[currentBufferIndex])
	{
		auto entityName = wstr::toString(entity.first);
		auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, entityName, NanoVGHelper::fontHarmony, 30);
		NanoVGHelper::nvgTextW(vg, entityName, entity.second.x - bounds.first / 2, entity.second.y - bounds.second / 2, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
	}
}

#include <format>
void NameTag::onRender3D(const EventRender3D& e)
{
	ToggleCheck;
	if (NanoGui::available) return;
	static auto& renderContext = Renderer::get().renderContext;
	viewport = { 0,0,renderContext.winSize.first,renderContext.winSize.second };

	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;
	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();

	std::vector<std::pair<std::string, Math::Vector2D>>entites;


	for (auto& player : players)
	{

		//if (player.isEqualTo(mc.getPlayer())) continue;

		auto postion = player.getPosition(e.TICK_DELTA);

		/*RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;*/


		auto renderPos = postion - e.CAMERA_POS;
		renderPos.y += player.getHeight() + 0.3f;
		Math::Vector2D point{};

		//std::cout << "Camera Pos : { " << std::format("{},{},{}", e.CAMERA_POS.x, e.CAMERA_POS.y, e.CAMERA_POS.z) << "}" << std::endl;
		//std::cout << "modelView :" << arrayToString(Math::structToVector(e.MODLEVIEW_MATRIX)) << std::endl;
		//std::cout << "projection :" << arrayToString(Math::structToVector(e.PROJECTION_MATRIX)) << std::endl;
		auto result = Math::W2S::world2Screen(
			Math::structToArray(e.MODLEVIEW_MATRIX),
			Math::structToArray(e.PROJECTION_MATRIX),
			renderPos,
			viewport,
			/*e.GUI_SCALE*/ 1
		);
		if (result[2] > 0 && result[2] < 1)
		{

			//points.push_back(point);
			point = { result[0],result[1] };
			//std::cout << "Point(cpp) : {" << point.x << "," << point.y << "}" << std::endl;
			entites.push_back(std::make_pair(player.getDisplayName(), point));

		}
	}
	entitiesToRender[currentBufferIndex] = {};
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	entitiesToRender[nextBufferIndex] = std::move(entites);
}

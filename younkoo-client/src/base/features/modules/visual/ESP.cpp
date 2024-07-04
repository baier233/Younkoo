#include "ESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <vector>
#include <map>

struct Context
{
	Math::Matrix projection;
	Math::Matrix modelView;
	Math::Vector3 cameraPos;
	double guiScale;
	float renderDetla;
};
static std::atomic<Context> currentContext;

std::array<int, 16> viewport{};

static std::vector<Math::Vector2> pointsToRender;

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

	pointsToRender.resize(0);

	if (NanoGui::available) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;
	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();
	std::vector<Math::Vector2> points;
	for (auto& player : players)
	{
		auto ctx = currentContext.load();
		auto postion = player.getPosition(ctx.renderDetla);

		RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		auto point = Math::W2S::world2Screen(std::vector<int>(viewport.begin(), viewport.end()),
			Math::structToVector(ctx.modelView),
			Math::structToVector(ctx.projection),
			postion.x - ctx.cameraPos.x,
			postion.y - ctx.cameraPos.y,
			postion.z - ctx.cameraPos.z,
			height,
			ctx.guiScale

		);
		if (point.size() > 2)
		{

			std::cout << "Point : {" << point[0] << "," << point[1] << "}" << std::endl;
		}
		/*if (Math::Vector2 point;  Math::W2S::WorldToScreen(postion - ctx.cameraPos, ctx.modelView, ctx.projection, width, height, point)) {

		}*/





	}
	pointsToRender = points;
}

void ESP::onRender(const EventRender2D& e)
{
	ToggleCheck;
	auto vg = NanoVGHelper::Context;
	for (const auto& point : pointsToRender)
	{
		NanoVGHelper::nvgTextW(vg, L"入", point.x, point.y, NanoVGHelper::fontHarmony, 15, nvgRGBA(255, 255, 255, 255));
	}
}

void ESP::onRender3D(const EventRender3D& e)
{
	ToggleCheck;
	glGetIntegerv(GL_VIEWPORT, viewport.data());
	currentContext = (Context{
		.projection = e.PROJECTION_MATRIX ,
		.modelView = e.MODLEVIEW_MATRIX,
		.cameraPos = e.CAMERA_POS,
		.guiScale = e.GUI_SCALE,
		.renderDetla = e.TICK_DELTA,
		});

}

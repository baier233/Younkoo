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
	Math::Vector3D cameraPos;
	double guiScale;
	float renderDetla;
};
static std::atomic<Context> currentContext;

std::array<int, 16> viewport{};

static std::vector<Math::Vector2D> pointsToRender;

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

void ESP::onRender(const EventRender2D& e)
{
	ToggleCheck;
	auto vg = NanoVGHelper::Context;
	for (const auto& point : pointsToRender)
	{

		NanoVGHelper::nvgTextW(vg, L"入", point.x, point.y, NanoVGHelper::fontHarmony, 15, nvgRGBA(255, 255, 255, 255));
	}
}
template<typename T>
static std::string arrayToString(const T* arr, size_t size) {
	std::ostringstream oss;
	oss << "[";
	for (size_t i = 0; i < size; ++i) {
		oss << arr[i];
		if (i < size - 1) {
			oss << ", ";
		}
	}
	oss << "]";
	return oss.str();
}

template<typename T>
static std::string arrayToString(const std::vector<T>& arr) {
	std::ostringstream oss;
	oss << "[";
	for (size_t i = 0; i < arr.size(); ++i) {
		oss << arr[i];
		if (i < arr.size() - 1) {
			oss << ", ";
		}
	}
	oss << "]";
	return oss.str();
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
	std::vector<Math::Vector2D> points;
	auto ctx = currentContext.load();
	for (auto& player : players)
	{

		//if (player.isEqualTo(mc.getPlayer())) continue;

		auto postion = player.getPosition(ctx.renderDetla);

		RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;


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
			e.GUI_SCALE
		);
		if (result[2] > 0 && result[2] < 1)
		{

			//points.push_back(point);
			point = { result[0],result[1] };
			std::cout << "Point(cpp) : {" << point.x << "," << point.y << "}" << std::endl;
			points.push_back(point);

		}
	}
	pointsToRender = points;
}

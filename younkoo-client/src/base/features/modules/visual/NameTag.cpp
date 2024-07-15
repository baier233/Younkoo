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
	this->addValue(FloatType, fontSizeValue);
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
#include <utils/strutils.h>
static std::map<wchar_t, NVGcolor> colorMap = {
	{'0', nvgRGBA(0, 0, 0, 255)},         // "black"
	{'1', nvgRGBA(0, 0, 139, 255)},       // "dark_blue"
	{'2', nvgRGBA(0, 139, 139, 255)},     // "dark_aqua"
	{'3', nvgRGBA(0, 206, 209, 255)},     // "dark_aqua"
	{'4', nvgRGBA(139, 0, 0, 255)},       // "dark_red"
	{'5', nvgRGBA(139, 0, 139, 255)},     // "dark_purple"
	{'6', nvgRGBA(255, 215, 0, 255)},     // "gold"
	{'7', nvgRGBA(169, 169, 169, 255)},   // "gray"
	{'8', nvgRGBA(105, 105, 105, 255)},   // "dark_gray"
	{'9', nvgRGBA(0, 0, 255, 255)},       // "blue"
	{'a', nvgRGBA(0, 255, 0, 255)},       // "green"
	{'b', nvgRGBA(0, 255, 255, 255)},     // "aqua"
	{'c', nvgRGBA(255, 0, 0, 255)},       // "red"
	{'d', nvgRGBA(255, 182, 193, 255)},   // "light_purple"
	{'e', nvgRGBA(255, 255, 0, 255)},     // "yellow"
	{'f', nvgRGBA(255, 255, 255, 255)}    // "white"
};

static std::pair<std::wstring, NVGcolor> parseName(const std::wstring& name) {
	if (strutil::starts_with(name, L"红队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(255, 69, 69, 255));
	}
	else if (strutil::starts_with(name, L"蓝队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(70, 130, 180, 255));
	}
	else if (strutil::starts_with(name, L"绿队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(144, 238, 144, 255));
	}
	else if (strutil::starts_with(name, L"黄队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(255, 255, 102, 255));
	}
	else if (strutil::starts_with(name, L"§")) {
		if (name.size() > 1 && colorMap.find(name[1]) != colorMap.end()) {
			return std::make_pair(name.substr(2), colorMap[name[1]]);
		}
	}
	return std::make_pair(name, nvgRGBA(255, 255, 255, 255));
}
void NameTag::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	if (entitiesToRender[nextBufferIndex].empty()) return;
	currentBufferIndex = nextBufferIndex;

	constexpr auto textSize = 25;
	int fontSize = fontSizeValue->getValue();
	for (const auto& entity : entitiesToRender[currentBufferIndex])
	{
		auto entityName = wstr::toString(entity.first);
		//std::wcout << entityName << std::endl;
		auto [name, color] = parseName(entityName);
		auto bounds = NanoVGHelper::nvgTextBoundsW(e.vg, name, NanoVGHelper::fontHarmony, fontSize);

		float textX = entity.second.x - bounds.first / 2;
		float textY = entity.second.y - bounds.second / 2;
		float textWidth = bounds.first;
		float textHeight = bounds.second;

		NanoVGHelper::drawRoundedRect(vg, textX - 5, textY - 20, textWidth + 10, textHeight + 10, NanoVGHelper::rgbaToColor(0, 0, 0, 128), 5.0f);
		NanoVGHelper::nvgTextW(vg, name, textX, textY - 15, NanoVGHelper::fontHarmony, fontSize, color);
		//NanoVGHelper::nvgTextW(vg, entityName, entity.second.x - bounds.first / 2, entity.second.y - bounds.second / 2, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
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
	if (level.isNULL()) return;
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
		//std::cout << "modelView :" << arrayToString(Math::structToVector(e.MODELVIEW_MATRIX)) << std::endl;
		//std::cout << "projection :" << arrayToString(Math::structToVector(e.PROJECTION_MATRIX)) << std::endl;
		auto result = Math::W2S::world2Screen(
			Math::structToArray(e.MODELVIEW_MATRIX),
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
			entites.push_back(std::make_pair(player.getDisplayName() + " HP:" + std::to_string(static_cast<int>(player.getHealth())), point));

		}
	}
	entitiesToRender[currentBufferIndex] = {};
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	entitiesToRender[nextBufferIndex] = std::move(entites);
}

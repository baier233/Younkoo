#include "HUD.h"
#include "base/render/hooks/WndProcHook.hpp"
#include "base/GitInfo.h"
#include <utils/Wstr.h>
#include "../ModuleManager.h"
#include <base/render/gui/GUI.h>


class MousePositionEstimator {
public:
	MousePositionEstimator(int screenWidth, int screenHeight, float mouseSensitivity)
		: screenWidth(screenWidth), screenHeight(screenHeight), mouseSensitivity(mouseSensitivity) {
		// 初始鼠标位置假设在屏幕中心
		mouseX = screenWidth / 2.0f;
		mouseY = screenHeight / 2.0f;
	}

	void update(float currentYaw, float currentPitch, float previousYaw, float previousPitch) {
		// 计算 yaw 和 pitch 的变化量
		float deltaYaw = currentYaw - previousYaw;
		float deltaPitch = currentPitch - previousPitch;

		// 计算鼠标的相对移动量
		float deltaMouseX = deltaYaw / mouseSensitivity;
		float deltaMouseY = deltaPitch / mouseSensitivity;

		// 更新鼠标位置
		mouseX += deltaMouseX;
		mouseY -= deltaMouseY; // 注意：屏幕坐标系通常是 y 轴向下为正

		// 确保鼠标位置在屏幕范围内
		mouseX = std::max(0.0f, std::min(static_cast<float>(screenWidth), mouseX));
		mouseY = std::max(0.0f, std::min(static_cast<float>(screenHeight), mouseY));
	}

	void printMousePosition() const {
		std::cout << "Estimated mouse position: (" << mouseX << ", " << mouseY << ")" << std::endl;
	}

private:
	int screenWidth;
	int screenHeight;
	float mouseSensitivity;
	float mouseX;
	float mouseY;
};


HUD::HUD() :AbstractModule(xorstr_("HUD"), Category::VISUAL, 'K')
{
	REGISTER_EVENT(EventRender2D, HUD::onRender);
	//ModuleManager::get().registrations.push_back(Younkoo::get().EventBus->register_handler<EventRender2D>(this, &HUD::onRender));

	this->setToggle(true);
}


HUD& HUD::getInstance()
{
	static HUD instance = HUD();
	return instance;
}

void HUD::onEnable()
{
}

void HUD::onDisable()
{
}
#include <base/render/Renderer.hpp>

#include <wrapper/net/minecraft/client/Minecraft.h>

static bool inGui = false;
static float anglesX = 0, anglesY = 0;
void HUD::onUpdate()
{
	ToggleCheck;

	if (NanoGui::available) {
		inGui = true;
		return;
	}
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.isInGuiState())
	{
		inGui = true;
		return;
	}
	inGui = false;
}
static void drawEyes(NVGcontext* vg, float x, float y, float w, float h, float mx, float my, float t)
{
	NVGpaint gloss, bg;
	float ex = w * 0.23f;
	float ey = h * 0.5f;
	float lx = x + ex;
	float ly = y + ey;
	float rx = x + w - ex;
	float ry = y + ey;
	float dx, dy, d;
	float br = (ex < ey ? ex : ey) * 0.5f;
	float blink = 1 - pow(sinf(t * 0.5f), 200) * 0.8f;

	bg = nvgLinearGradient(vg, x, y + h * 0.5f, x + w * 0.1f, y + h, nvgRGBA(0, 0, 0, 32), nvgRGBA(0, 0, 0, 16));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx + 3.0f, ly + 16.0f, ex, ey);
	nvgEllipse(vg, rx + 3.0f, ry + 16.0f, ex, ey);
	nvgFillPaint(vg, bg);
	nvgFill(vg);

	bg = nvgLinearGradient(vg, x, y + h * 0.25f, x + w * 0.1f, y + h, nvgRGBA(220, 220, 220, 255), nvgRGBA(128, 128, 128, 255));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx, ly, ex, ey);
	nvgEllipse(vg, rx, ry, ex, ey);
	nvgFillPaint(vg, bg);
	nvgFill(vg);

	dx = (mx - rx) / (ex * 10);
	dy = (my - ry) / (ey * 10);
	d = sqrtf(dx * dx + dy * dy);
	if (d > 1.0f) {
		dx /= d; dy /= d;
	}
	dx *= ex * 0.4f;
	dy *= ey * 0.5f;
	nvgBeginPath(vg);
	nvgEllipse(vg, lx + dx, ly + dy + ey * 0.25f * (1 - blink), br, br * blink);
	nvgFillColor(vg, nvgRGBA(32, 32, 32, 255));
	nvgFill(vg);

	dx = (mx - rx) / (ex * 10);
	dy = (my - ry) / (ey * 10);
	d = sqrtf(dx * dx + dy * dy);
	if (d > 1.0f) {
		dx /= d; dy /= d;
	}
	dx *= ex * 0.4f;
	dy *= ey * 0.5f;
	nvgBeginPath(vg);
	nvgEllipse(vg, rx + dx, ry + dy + ey * 0.25f * (1 - blink), br, br * blink);
	nvgFillColor(vg, nvgRGBA(32, 32, 32, 255));
	nvgFill(vg);

	gloss = nvgRadialGradient(vg, lx - ex * 0.25f, ly - ey * 0.5f, ex * 0.1f, ex * 0.75f, nvgRGBA(255, 255, 255, 128), nvgRGBA(255, 255, 255, 0));
	nvgBeginPath(vg);
	nvgEllipse(vg, lx, ly, ex, ey);
	nvgFillPaint(vg, gloss);
	nvgFill(vg);

	gloss = nvgRadialGradient(vg, rx - ex * 0.25f, ry - ey * 0.5f, ex * 0.1f, ex * 0.75f, nvgRGBA(255, 255, 255, 128), nvgRGBA(255, 255, 255, 0));
	nvgBeginPath(vg);
	nvgEllipse(vg, rx, ry, ex, ey);
	nvgFillPaint(vg, gloss);
	nvgFill(vg);
}
void HUD::onRender(const EventRender2D& e)
{
	ToggleCheck;
	static int x2 = e.winWidth / static_cast<float>(2);
	if (WndProcHook::RESIZED)
	{
		x2 = e.winWidth / static_cast<float>(2);
	}
	using namespace NanoVGHelper;

	float x = 5;
	float y = 40;
	float text_y = 5;
	static std::wstring watermark(L"Younkoo Client");
	auto bounds = nvgTextBoundsW(e.vg, watermark, NanoVGHelper::fontHarmony, 20);
	//nvgTextW(e.vg, watermark, x2 - bounds.first / static_cast<float>(2), y, NanoVGHelper::fontHarmony, 30, nvgRGBA(255, 255, 255, 255));
	
	NanoVGHelper::drawRoundedRect(e.vg, x, text_y, bounds.first + 10, bounds.second + 10, NanoVGHelper::rgbaToColor(0, 0, 0, 128), 5.0f);
	NanoVGHelper::nvgTextW(e.vg, watermark, x + 5, text_y + 5, NanoVGHelper::fontHarmony, 20, NanoVGHelper::colorToRGB(-1));

	static auto& handleWindow = Renderer::get().renderContext.HandleWindow;
	float mx = 0, my = 0;


	double t = glfwGetTime();
	if (inGui)
	{
		POINT cursorPos;
		GetCursorPos(&cursorPos);
		ScreenToClient(handleWindow, &cursorPos);
		mx = (float)cursorPos.x;
		my = (float)cursorPos.y;
		drawEyes(e.vg, e.winWidth - 150, 10, 150, 100, mx, my, t);
	}


	auto mods = ModuleManager::get().getMods();
	std::vector<std::pair<std::wstring, std::pair<float, float>>> modNamesWithBounds;

	for (auto iter = mods.cbegin(); iter < mods.cend(); iter++) {
		auto sbmod = reinterpret_cast<AbstractModule*>(*iter);
		if (sbmod && sbmod->getToggle())
		{
			auto sbname1 = sbmod->getName();
			std::wstring sbname(sbname1.begin(), sbname1.end());
			auto bounds = nvgTextBoundsW(e.vg, sbname, NanoVGHelper::fontHarmony, 20);
			modNamesWithBounds.push_back({ sbname, bounds });
		}
	}

	std::sort(modNamesWithBounds.begin(), modNamesWithBounds.end(), [](const auto& a, const auto& b) {
		return a.second.first > b.second.first;
		});

	for (const auto& mod : modNamesWithBounds) {
		const auto& sbname = mod.first;
		NanoVGHelper::drawRect(e.vg, x, y, mod.second.first + 10, mod.second.second + 8.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 100));
		nvgTextW(e.vg, sbname, x + 5, y + (8.0f / 2.0f), NanoVGHelper::fontHarmony, 20, nvgRGBA(255, 255, 255, 255));
		y += mod.second.second + 8;
	}
}

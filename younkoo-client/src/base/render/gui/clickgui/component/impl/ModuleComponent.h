#pragma once
#include "../Component.hpp"
#include <algorithm>
#include <cmath>
#include <utils/animation/Animation.hpp>
#include "../../../../../features/modules/AbstractModule.h"
#include "../../../../../features/modules/ModuleManager.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI
#include <execution>
class ModuleComponent : public Component
{
public:
	ModuleComponent(AbstractModule* mod) {
		this->mod = mod;
		//TODO


		for (auto& values : mod->getValues())
		{
			switch (values.first)
			{
			default:
				break;
			}
		}
	}

	static int interpolateInt(int start, int end, float amount) {
		return static_cast<int>(start + (end - start) * std::clamp(amount, 0.0f, 1.0f));
	}

	// 插值颜色
	static NVGcolor interpolateColorC(NVGcolor color1, NVGcolor color2, float amount) {
		amount = std::clamp(amount, 0.0f, 1.0f);
		return NVGcolor{
			interpolateInt(color1.r * 255, color2.r * 255, amount) / 255.0f,
			interpolateInt(color1.g * 255, color2.g * 255, amount) / 255.0f,
			interpolateInt(color1.b * 255, color2.b * 255, amount) / 255.0f,
			interpolateInt(color1.a * 255, color2.a * 255, amount) / 255.0f
		};
	}

	void drawScreen(NVGcontext* vg, std::pair<int, int> winSize) override {
		//TODO

		float padding = 5.f;

		this->expandHeight = 0;

		stateAnim.setState(this->mod->getToggle());
		//hoverAnim.setState(RenderUtil.isHovering(x, y, width, height, mouseX, mouseY));
		expandAnim.setState(expand);

		float output = stateAnim.getOutput();

		NVGcolor fontColor = interpolateColorC(NVGcolor{ 255, 255, 255, 255 }, NanoVGHelper::colorToRGBA(0xB20AF4), output);

		if (!this->mod->getValues().empty()) {
			auto bounds = NanoVGHelper::nvgTextBoundsW(vg, L"f", NanoVGHelper::fontClickguiIcon, 25);
			nvgFontSize(vg, 25);
			float lineh{};
			nvgTextMetrics(vg, nullptr, nullptr, &lineh);
			auto fontHeight = lineh / 2;
			float arrowX = x + width - bounds.first - padding;
			float arrowY = y + height / 2.f - fontHeight / 2;
			float centerX = arrowX + bounds.first / 2.f;
			float centerY = arrowY + fontHeight / 2.f;

			float output = expandAnim.getOutput();
			float angleInRadians = static_cast<float>(-90.0f * output * M_PI / 180.0f);
			NanoVGHelper::startRotate(vg, centerX, centerY, angleInRadians);

			NanoVGHelper::nvgTextW(vg, L"f", centerX, centerY, NanoVGHelper::fontClickguiIcon, 25, NanoVGHelper::colorToRGBA(-1));
			NanoVGHelper::stopRotate();
		}
		float offsetY = 0.f;
		if (expand || !expandAnim.isEnded()) {
			auto output = expandAnim.getOutput();
			std::vector<float> heights;
			//TODO
			/*	for (const auto& component : valueComponents) {
					if (component.getValue().getDisplayable().displayable()) {
						heights.push_back(component.getHeight() + component.getExpandHeight() + padding);
					}
				}*/
			this->expandHeight = output * std::accumulate(heights.begin(), heights.end(), 0.0f);

			NanoVGHelper::push();
			nvgIntersectScissor(vg, x, y + padding, width, height + expandHeight);
			nvgGlobalAlpha(vg, expandAnim.getOutput());

			//TODO
			/*for (auto& component : valueComponents) {
				if (!component.getValue().getDisplayable().displayable()) continue;
				component.setX(x);
				component.setY(y + getHeight() + padding + offsetY);
				component.setWidth(width);

				component.drawScreen(mouseX, mouseY, partialTicks);

				offsetY += component.getHeight() + component.getExpandHeight() + padding;
			}*/

			NanoVGHelper::pop();
		}
	}
	float x = 0, y = 0;
	float width = 145;
	float height, expandHeight = 0;
	bool clicking = false, expand = false;
private:
	Animation stateAnim = Animation(Easing::EASE_IN_BACK, 220).setState(false);
	Animation hoverAnim = Animation(Easing::EASE_IN_BACK, 220).setState(false);
	Animation expandAnim = Animation(Easing::EASE_IN_BACK, 280).setState(false);
	AbstractModule* mod;
};


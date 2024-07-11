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

void ItemESP::onRender(const EventRender2D& e) {
	ToggleCheck;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;

}

#include <format>
#include <utils/Misc.hpp>

void ItemESP::onRender3D(const EventRender3D& e) {
	ToggleCheck;
	if (NanoGui::available) return;

	const auto& renderContext = Renderer::get().renderContext;

	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;

	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();

}

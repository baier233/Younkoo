#include "BlockESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>
#include <base/features/modules/common/CommonData.h>

#include <vector>
#include <map>
#include <ranges>
#include <array>

#include <utils/Wstr.h>

#include <format>
#include <utils/Misc.hpp>
static std::vector<std::vector<std::array<Math::Vector3D, 4>> > blocksToRender;

BlockESP::BlockESP() : AbstractModule(xorstr_("BlockESP"), Category::VISUAL) {
	REGISTER_EVENT(EventRender3D, BlockESP::onRender3D);
	REGISTER_EVENT(EventRender2D, BlockESP::onRender);
}

BlockESP& BlockESP::getInstance() {
	static BlockESP instance;
	return instance;
}

void BlockESP::onEnable() {
	static std::once_flag flag{};
	std::call_once(flag, [this] {
		targets_ = { "_bed" };
		blockTracker_ = std::make_shared<BlockTracker>(targets_);
		});

	ChunkScanner::subscribe(this->blockTracker_);
}

void BlockESP::onDisable() {

	ChunkScanner::unsubscribe(this->blockTracker_);
}


void BlockESP::onRender(const EventRender2D& e) {
	ToggleCheck;
	static auto& renderer = Renderer::get();
	static auto& common = CommonData::get();
	auto vg = NanoVGHelper::Context;
	std::vector<std::pair<Math::Vector2D, Math::Vector2D> > newLines;
	for (auto& faces : blocksToRender)
	{
		for (auto& face : faces) {
			bool ok = true;
			std::vector<Math::Vector2D> projected;
			for (auto& pos : face)
			{
				auto result = Math::W2S::world2Screen(Math::structToArray(common.modelView), Math::structToArray(common.projection), pos, { 0,0,e.winWidth,e.winHeight }, 1);
				Math::Vector2D point{ result[0], result[1] };
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
				newLines.push_back(std::make_pair(Math::Vector2D{ projected[0].x,projected[0].y }, Math::Vector2D{ projected[1].x,projected[1].y }));
				newLines.push_back(std::make_pair(Math::Vector2D{ projected[1].x,projected[1].y }, Math::Vector2D{ projected[2].x,projected[2].y }));
				newLines.push_back(std::make_pair(Math::Vector2D{ projected[2].x,projected[2].y }, Math::Vector2D{ projected[3].x,projected[3].y }));
				newLines.push_back(std::make_pair(Math::Vector2D{ projected[3].x,projected[3].y }, Math::Vector2D{ projected[0].x,projected[0].y }));
			}
		}
	}
	for (auto& lines : newLines) {
		auto& begin = lines.first;
		auto& end = lines.second;
		NVGcolor rgbaColor = { 255,255,255,0.15 };
		NanoVGHelper::drawLine(vg, begin.x, begin.y, end.x, end.y, 1, NanoVGHelper::rgbaToColor(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a));
	}
}

void BlockESP::onRender3D(const EventRender3D& e) {
	ToggleCheck;
	if (NanoGui::available) return;

	const auto& renderContext = Renderer::get().renderContext;

}


void BlockESP::onUpdate() {

	ToggleCheck;




	static auto& common = CommonData::get();
	std::vector<std::vector<std::array<Math::Vector3D, 4>> > newBlocks;
	for (auto& pair : blockTracker_->trackedBlockMap)
	{
		auto& [pos, t] = pair;
		auto relativePos = Math::Vector3D{ static_cast<double>(pos.x),static_cast<double>(pos.y),static_cast<double>(pos.z) } - common.cameraPos;
		auto minX = relativePos.x;
		auto minY = relativePos.y;
		auto minZ = relativePos.z;

		auto maxX = relativePos.x + 1;
		auto maxY = relativePos.y + 1;
		auto maxZ = relativePos.z + 1;

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

		newBlocks.push_back(faces);
	}
	blocksToRender = newBlocks;
}

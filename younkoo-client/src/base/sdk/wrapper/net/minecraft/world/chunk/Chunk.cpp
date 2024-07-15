#include "Chunk.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/level/chunk/LevelChunk.h>
Math::ChunkPos Wrapper::Chunk::getPos()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LevelChunk chunk = this->getObject();
		auto chunkPos = chunk.getPos();
		return Math::ChunkPos{ chunkPos.x.get(),chunkPos.z.get() };
	}
	return Math::ChunkPos();
}

Math::ChunkPos Wrapper::Chunk::getMinPos()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LevelChunk chunk = this->getObject();
		auto chunkPos = chunk.getPos();
		return Math::ChunkPos{ chunkPos.getMinBlockX(),chunkPos.getMinBlockZ() };
	}
	return Math::ChunkPos();
}

int Wrapper::Chunk::getHeight()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LevelChunk chunk = this->getObject();
		return chunk.getHeight();
	}
	return 0;
}

int Wrapper::Chunk::getBottomY()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LevelChunk chunk = this->getObject();
		return chunk.getMinBuildHeight();
	}
	return 0;
}

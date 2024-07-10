#include "BlockPos.h"
#include <wrapper/versions/1_18_1/net/minecraft/core/BlockPos.h>

Wrapper::BlockPos::BlockPos(const Math::Vector3D pos)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		this->instance = std::make_shared<JNI::EmptyMembers>(V1_18_1::BlockPos::create(pos));
	}
}

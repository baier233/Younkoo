#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"

BEGIN_KLASS_DEF(EntityPlayerSP, if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
{
	return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer");
}
else {
	return SRGParser::get().getObfuscatedClassName("net/minecraft/client/entity/EntityPlayerSP");
})

END_KLASS_DEF();


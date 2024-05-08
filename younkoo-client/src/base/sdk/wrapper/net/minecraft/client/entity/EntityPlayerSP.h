#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"
#include "AbstractClientPlayer.h"
BEGIN_KLASS_DEF_EX(EntityPlayerSP, SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), AbstractClientPlayer)
	EMPTY_CONTENT;
END_KLASS_DEF();


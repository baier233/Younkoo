#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"
#include "../entity/player/AbstractClientPlayer.h"
BEGIN_KLASS_DEF_EX(LocalPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), AbstractClientPlayer)
EMPTY_CONTENT;
END_KLASS_DEF();


#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"
#include "Player.h"
BEGIN_KLASS_DEF_EX(AbstractClientPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), Player)
EMPTY_CONTENT;
END_KLASS_DEF();
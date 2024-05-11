#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"
#include "LivingEntity.h"
BEGIN_KLASS_DEF_EX(Player, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Player"), LivingEntity)
EMPTY_CONTENT;
END_KLASS_DEF();
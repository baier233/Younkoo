#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>


BEGIN_1_18_1
BEGIN_KLASS_DEF_EX(Player, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Player"), LivingEntity)

END_KLASS_DEF()
END_1_18_1
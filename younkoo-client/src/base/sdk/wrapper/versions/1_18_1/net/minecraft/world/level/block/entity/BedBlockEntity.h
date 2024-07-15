#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/DyeColor.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(BedBlockEntity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/block/entity/BedBlockEntity"))
JNI::Method<DyeColor, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/block/entity/BedBlockEntity", "getColor", "()Lnet/minecraft/world/item/DyeColor;").first
)> getColor{ *this };

END_KLASS_DEF()
END_1_18_1;

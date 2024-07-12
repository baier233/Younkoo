#pragma once

#include <SDK.hpp>


#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(BlockItem, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/BlockItem"))
JNI::Method<Block, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/BlockItem", "getBlock", "()Lnet/minecraft/world/level/block/Block;").first
)> getBlock{ *this };
END_KLASS_DEF()
END_1_18_1
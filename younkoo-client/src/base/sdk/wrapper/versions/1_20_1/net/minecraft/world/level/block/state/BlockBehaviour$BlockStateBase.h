#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_20_1/net/minecraft/world/level/block/Block.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF(BlockBehaviour$BlockStateBase, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/block/state/BlockBehaviour$BlockStateBase"))

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/block/state/BlockBehaviour$BlockStateBase", "isAir", "()Z").first
)> isAir{ *this };


JNI::Method<Block, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/block/state/BlockBehaviour$BlockStateBase", "getBlock", "()Lnet/minecraft/world/level/block/Block;").first
)> getBlock{ *this };
END_KLASS_DEF();

END_1_20_1
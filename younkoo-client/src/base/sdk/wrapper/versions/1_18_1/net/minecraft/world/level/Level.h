#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/chunk/LevelChunk.h>


BEGIN_1_18_1

BEGIN_KLASS_DEF(Level, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/Level"))
JNI::Method<BlockState, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/Level", "getBlockState", "(Lnet/minecraft/core/BlockPos;)Lnet/minecraft/world/level/block/state/BlockState;").first
), BlockPos> getBlockState{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/LevelWriter", "setBlock", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;II)Z").first
), BlockPos, BlockState, jint, jint> setBlock{ *this };

JNI::Method<LevelChunk, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/Level", "getChunk", "(II)Lnet/minecraft/world/level/chunk/LevelChunk;").first
), jint, jint> getChunk{ *this };


END_KLASS_DEF();


END_1_18_1
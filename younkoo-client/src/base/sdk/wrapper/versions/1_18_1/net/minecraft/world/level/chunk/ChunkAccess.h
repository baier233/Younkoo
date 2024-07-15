#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/ChunkPos.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ChunkAccess, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/chunk/ChunkAccess"))


JNI::Method<ChunkPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/chunk/ChunkAccess", "getPos", "()Lnet/minecraft/world/level/ChunkPos;").first
)> getPos{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/LevelHeightAccessor", "getHeight", "()I").first
)> getHeight{ *this };


JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/LevelHeightAccessor", "getMinBuildHeight", "()I").first
)> getMinBuildHeight{ *this };
END_KLASS_DEF();
END_1_18_1
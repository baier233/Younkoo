#pragma once
#include <SDK.hpp>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ChunkPos, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/ChunkPos"))


JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/ChunkPos"), "x")
)> x{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/ChunkPos"), "z")
)> z{ *this };/* I */


JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/ChunkPos", "getMinBlockX", "()I").first
)> getMinBlockX{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/ChunkPos", "getMinBlockZ", "()I").first
)> getMinBlockZ{ *this };

END_KLASS_DEF();
END_1_18_1
#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/core/SectionPos.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ClientboundForgetLevelChunkPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundForgetLevelChunkPacket"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundForgetLevelChunkPacket"), "x")
)> x{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundForgetLevelChunkPacket"), "z")
)> z{ *this };/* I */


END_KLASS_DEF();
END_1_18_1
#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/core/SectionPos.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ClientboundSectionBlocksUpdatePacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSectionBlocksUpdatePacket"))

JNI::Field<SectionPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundSectionBlocksUpdatePacket"), "sectionPos")
)> sectionPos{ *this };/* Lnet/minecraft/core/SectionPos; */

END_KLASS_DEF();
END_1_18_1
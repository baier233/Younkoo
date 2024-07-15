#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundLightUpdatePacketData.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundLevelChunkPacketData.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(ClientboundLevelChunkWithLightPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket"))
JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket", "getX", "()I").first
)> getX{ *this };

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket", "getZ", "()I").first
)> getZ{ *this };

JNI::Method<ClientboundLevelChunkPacketData, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket", "getChunkData", "()Lnet/minecraft/network/protocol/game/ClientboundLevelChunkPacketData;").first
)> getChunkData{ *this };

JNI::Method<ClientboundLightUpdatePacketData, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket", "getLightData", "()Lnet/minecraft/network/protocol/game/ClientboundLightUpdatePacketData;").first
)> getLightData{ *this };
END_KLASS_DEF();
END_1_18_1
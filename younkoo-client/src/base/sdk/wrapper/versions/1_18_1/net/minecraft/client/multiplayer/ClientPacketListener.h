#pragma once

#include <SDK.hpp>

#include <jdk/Classes.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundSectionBlocksUpdatePacket.h>
#include <wrapper/versions/1_18_1/net/minecraft/network/protocol/game/ClientboundForgetLevelChunkPacket.h>



BEGIN_1_18_1

BEGIN_KLASS_DEF(ClientPacketListener, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientPacketListener"))

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientGamePacketListener", "handleLevelChunkWithLight", "(Lnet/minecraft/network/protocol/game/ClientboundLevelChunkWithLightPacket;)V").first
), ClientboundLevelChunkWithLightPacket> handleLevelChunkWithLight{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientGamePacketListener", "handleChunkBlocksUpdate", "(Lnet/minecraft/network/protocol/game/ClientboundSectionBlocksUpdatePacket;)V").first
), ClientboundSectionBlocksUpdatePacket> handleChunkBlocksUpdate{ *this };


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/protocol/game/ClientGamePacketListener", "handleForgetLevelChunk", "(Lnet/minecraft/network/protocol/game/ClientboundForgetLevelChunkPacket;)V").first
), ClientboundForgetLevelChunkPacket> handleForgetLevelChunk{ *this };

END_KLASS_DEF();


END_1_18_1
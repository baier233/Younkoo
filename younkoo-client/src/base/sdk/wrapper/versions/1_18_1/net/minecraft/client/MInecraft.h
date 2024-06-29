#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/gui/screens/Screen.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))

JNI::Field < ClientLevel, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "level")
)> level{ *this };/* Lnet/minecraft/client/multiplayer/ClientLevel; */


JNI::Field < LocalPlayer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "player")
)> player{ *this };/* Lnet/minecraft/client/player/LocalPlayer; */

JNI::Field<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance")
)> instance{ *this };

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first
)>getInstance{ *this };

JNI::Field<Screen, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen")
)>screen{ *this };

JNI::Field<HitResult, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult")
)> hitResult{ *this };/* Lnet/minecraft/world/phys/HitResult; */

END_KLASS_DEF();


END_1_18_1
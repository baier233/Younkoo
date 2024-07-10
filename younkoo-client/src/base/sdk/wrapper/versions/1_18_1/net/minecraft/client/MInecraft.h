#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/client/Options.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/gui/screens/Screen.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult.h>

#include <wrapper/versions/1_18_1/com/mojang/blaze3d/platform/Window.h>

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

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTime", "()F").first
)> getFrameTime{ *this };

JNI::Method<Window, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getWindow", "()Lcom/mojang/blaze3d/platform/Window;").first
)> getWindow{ *this };

JNI::Field<Options, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "options")
)> options{ *this };/* Lnet/minecraft/client/Options; */


END_KLASS_DEF();


END_1_18_1
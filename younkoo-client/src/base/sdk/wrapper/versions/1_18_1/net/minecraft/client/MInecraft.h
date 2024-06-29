#pragma once

#include <SDK.hpp>

#include "gui/screens/Screen.h"
#include "../world/phys/HitResult.h"
#include "player/LocalPlayer.h"
BEGIN_1_18_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))
JNI::Field<Minecraft, JNI::STATIC, DECLARE_NAME(
    return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance")
)> instance{*this};

JNI::Field<LocalPlayer, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "player")
)> player{ *this };

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
    return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first
)>getInstance{*this};

JNI::Field<Screen, JNI::NOT_STATIC, DECLARE_NAME(
    return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen")
)>screen{*this };

JNI::Field<HitResult, JNI::NOT_STATIC, DECLARE_NAME(
    return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult")
)> hitResult{*this };/* Lnet/minecraft/world/phys/HitResult; */

END_KLASS_DEF();


END_1_18_1
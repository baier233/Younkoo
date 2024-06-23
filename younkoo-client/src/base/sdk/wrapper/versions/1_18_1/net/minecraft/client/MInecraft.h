#pragma once

#include <SDK.hpp>

#include "gui/screens/Screen.h"
#include "../world/phys/HitResult.h"

BEGIN_1_18_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))
JNI::Field<Minecraft, JNI::STATIC> instance{ [] {
    return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance");
    } ,*this };

JNI::Method<Minecraft, JNI::STATIC> getInstance{ [] {
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first;
} ,*this };

JNI::Field<Screen, JNI::NOT_STATIC> screen{ [] {
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen");
} ,*this };

JNI::Field<HitResult, JNI::NOT_STATIC> hitResult{ [] {
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult");
} ,*this };/* Lnet/minecraft/world/phys/HitResult; */

END_KLASS_DEF();


END_1_18_1
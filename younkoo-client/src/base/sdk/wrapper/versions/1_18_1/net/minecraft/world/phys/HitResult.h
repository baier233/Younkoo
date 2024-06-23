#pragma once
#include <SDK.hpp>
#include "Vec3.h"
#include "HitResult$Type.h"

BEGIN_1_18_1

BEGIN_KLASS_DEF(HitResult, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult"))

JNI::Field<Vec3, JNI::NOT_STATIC> location{ [] {
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult"), "location");
} ,*this };/* Lnet/minecraft/world/phys/Vec3; */
//JNI::Method<jdouble, JNI::NOT_STATIC> distanceTo{ [] {
//return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "distanceTo", "(Lnet/minecraft/world/entity/Entity;)D").first;
//} ,*this };
JNI::Method<HitResult$Type, JNI::NOT_STATIC> getType{ [] {
return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "getType", "()Lnet/minecraft/world/phys/HitResult$Type;").first;
} ,*this };
JNI::Method<Vec3, JNI::NOT_STATIC> getLocation{ [] {
return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "getLocation", "()Lnet/minecraft/world/phys/Vec3;").first;
} ,*this };
END_KLASS_DEF();

END_1_18_1
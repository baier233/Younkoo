#pragma once
#include <SDK.hpp>
#include "Vec3.h"
#include "HitResult$Type.h"

BEGIN_1_18_1

BEGIN_KLASS_DEF(HitResult, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult"))

JNI::Field<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult"), "location")
)> location{ *this };/* Lnet/minecraft/world/phys/Vec3; */
JNI::Method<HitResult$Type, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "getType", "()Lnet/minecraft/world/phys/HitResult$Type;").first
)> getType{ *this };
JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "getLocation", "()Lnet/minecraft/world/phys/Vec3;").first
)> getLocation{ *this };
END_KLASS_DEF();

END_1_18_1
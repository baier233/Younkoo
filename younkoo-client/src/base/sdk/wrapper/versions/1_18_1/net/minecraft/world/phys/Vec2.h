#pragma once
#include <SDK.hpp>

#include <utils/types/Maths.hpp>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Vec2, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec2"))
JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec2"), "x")
)> x{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec2"), "y")
)> y{ *this };/* F */

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/Vec2", "distanceToSqr", "(Lnet/minecraft/world/phys/Vec2;)F").first
), Vec2> distanceToSqr{ *this };
END_KLASS_DEF();

END_1_18_1
#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>


BEGIN_1_18_1
BEGIN_KLASS_DEF(Entity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"))
JNI::Field < Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "position")
)> position{ *this };/* Lnet/minecraft/world/phys/Vec3; */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setGlowingTag", "(Z)V").first
), jboolean> setGlowingTag{ *this };

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getPosition", "(F)Lnet/minecraft/world/phys/Vec3;").first
), jfloat> getPosition{ *this };

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "xOld")
)> xOld{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "yOld")
)> yOld{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "zOld")
)> zOld{ *this };/* D */

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getX", "()D").first
)> getX{ *this };

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getY", "()D").first
)> getY{ *this };

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getZ", "()D").first
)> getZ{ *this };

END_KLASS_DEF()
END_1_18_1
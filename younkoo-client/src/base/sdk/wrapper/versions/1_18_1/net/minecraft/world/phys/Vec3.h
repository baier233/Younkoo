#pragma once
#include <SDK.hpp>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Vec3, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"))

JNI::Field<Vec3, JNI::STATIC,DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "ZERO")
	)> ZERO{*this };/* Lnet/minecraft/world/phys/Vec3; */
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "x")
	)> x{*this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "y")
	)> y{*this };/* D */
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "z")
	)> z{*this };/* D */

END_KLASS_DEF();

END_1_18_1
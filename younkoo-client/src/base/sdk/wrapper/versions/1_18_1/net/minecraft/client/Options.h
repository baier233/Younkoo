#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/KeyMapping.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Options, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Options"))

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Options"), "fov")
)> fov{ *this };/* D */

JNI::Field<KeyMapping, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Options"), "keyShift")
)> keyShift{ *this };/* Lnet/minecraft/client/KeyMapping; */
END_KLASS_DEF();

END_1_18_1
#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Options, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Options"))

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Options"), "fov")
)> fov{ *this };/* D */

END_KLASS_DEF();

END_1_18_1
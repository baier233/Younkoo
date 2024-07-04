#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Camera, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Camera"))

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Camera", "getPosition", "()Lnet/minecraft/world/phys/Vec3;").first
)> getPosition{ *this };

END_KLASS_DEF();

END_1_18_1
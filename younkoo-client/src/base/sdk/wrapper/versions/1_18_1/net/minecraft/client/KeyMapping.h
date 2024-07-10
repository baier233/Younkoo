#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec3.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(KeyMapping, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/KeyMapping"))
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/KeyMapping", "setDown", "(Z)V").first
), jboolean> setDown{ *this };
END_KLASS_DEF();

END_1_18_1
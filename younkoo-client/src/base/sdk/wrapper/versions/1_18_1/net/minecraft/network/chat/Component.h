#pragma once
#include <SDK.hpp>
#include <wrapper/java/lang/String.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Component, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/chat/Component"))
JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/network/chat/Component", "getString", "()Ljava/lang/String;").first
)> getString{ *this };
END_KLASS_DEF();

END_1_18_1
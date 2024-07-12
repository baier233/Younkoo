#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(ChatFormatting, return SRGParser::get().getObfuscatedClassName("net/minecraft/ChatFormatting"))

JNI::Field<JDK::Integer, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/ChatFormatting"), "color")
)> color{ *this };/* Ljava/lang/Integer; */

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/ChatFormatting", "isColor", "()Z").first
)> isColor{ *this };
END_KLASS_DEF();
END_1_18_1
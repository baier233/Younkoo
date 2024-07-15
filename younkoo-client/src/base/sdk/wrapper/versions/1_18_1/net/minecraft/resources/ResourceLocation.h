#pragma once
#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ResourceLocation, return SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"))

JNI::Field<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/resources/ResourceLocation"), "path")
)> path{ *this };/* Ljava/lang/String; */

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/resources/ResourceLocation", "getPath", "()Ljava/lang/String;").first
)> getPath{ *this };

END_KLASS_DEF();
END_1_18_1
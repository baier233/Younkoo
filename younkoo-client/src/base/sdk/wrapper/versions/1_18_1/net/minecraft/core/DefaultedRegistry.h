#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/versions/1_18_1/net/minecraft/resources/ResourceLocation.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF_EX(DefaultedRegistry, return SRGParser::get().getObfuscatedClassName("net/minecraft/core/DefaultedRegistry"), JDK::java_lang::Iterable)
JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/DefaultedRegistry", "getId", "(Ljava/lang/Object;)I").first
), JDK::Object> getId{ *this };

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/DefaultedRegistry", "getKey", "(Ljava/lang/Object;)Lnet/minecraft/resources/ResourceLocation;").first
), JDK::Object> getKey{ *this };

END_KLASS_DEF();


END_1_18_1
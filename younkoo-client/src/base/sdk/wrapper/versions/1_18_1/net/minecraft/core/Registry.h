#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>

#include <wrapper/versions/1_18_1/net/minecraft/core/DefaultedRegistry.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Registry, return SRGParser::get().getObfuscatedClassName("net/minecraft/core/Registry"))

JNI::Field<DefaultedRegistry, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/Registry"), "BLOCK")
)> BLOCK{ *this };/* Lnet/minecraft/core/DefaultedRegistry; */

END_KLASS_DEF();

END_1_18_1
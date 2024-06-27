
#pragma once
#include <SDK.hpp>

BEGIN_1_18_1


BEGIN_KLASS_DEF(HitResult$Type, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult$Type"))
JNI::Field<HitResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult$Type"), "MISS")
	)> MISS{*this };/* Lnet/minecraft/world/phys/HitResult$Type; */
JNI::Field<HitResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult$Type"), "BLOCK")
	)> BLOCK{*this };/* Lnet/minecraft/world/phys/HitResult$Type; */
JNI::Field<HitResult$Type, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult$Type"), "ENTITY")
	)> ENTITY{*this };/* Lnet/minecraft/world/phys/HitResult$Type; */

END_KLASS_DEF();

END_1_18_1
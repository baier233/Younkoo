#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult$Type.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_18_1/net/minecraft/core/BlockPos.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(BlockHitResult, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/BlockHitResult"))

JNI::Field<BlockPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/BlockHitResult"), "blockPos")
)> blockPos{ *this };/* Lnet/minecraft/core/BlockPos; */

JNI::Field<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/BlockHitResult"), "miss")
)> miss{ *this };/* Z */

JNI::Method<BlockPos, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/BlockHitResult", "getBlockPos", "()Lnet/minecraft/core/BlockPos;").first
)> getBlockPos{ *this };



END_KLASS_DEF();
END_1_18_1;
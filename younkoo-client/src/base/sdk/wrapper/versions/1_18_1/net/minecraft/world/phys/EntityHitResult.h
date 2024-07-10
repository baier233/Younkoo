#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/HitResult$Type.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(EntityHitResult, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/EntityHitResult"))
JNI::Field<Entity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/EntityHitResult"), "entity")
)> entity{ *this };/* Lnet/minecraft/world/entity/Entity; */

JNI::Method<Entity, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/EntityHitResult", "getEntity", "()Lnet/minecraft/world/entity/Entity;").first
)> getEntity{ *this };

JNI::Method<HitResult$Type, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/EntityHitResult", "getType", "()Lnet/minecraft/world/phys/HitResult$Type;").first
)> getType{ *this };

END_KLASS_DEF();
END_1_18_1;
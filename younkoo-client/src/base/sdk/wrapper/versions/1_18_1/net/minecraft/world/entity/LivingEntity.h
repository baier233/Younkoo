#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF_EX(LivingEntity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/LivingEntity"), Entity)
JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getHealth", "()F").first
)> getHealth{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getMainHandItem", "()Lnet/minecraft/world/item/ItemStack;").first
)> getMainHandItem{ *this };

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "getOffhandItem", "()Lnet/minecraft/world/item/ItemStack;").first
)> getOffhandItem{ *this };
END_KLASS_DEF()
END_1_18_1
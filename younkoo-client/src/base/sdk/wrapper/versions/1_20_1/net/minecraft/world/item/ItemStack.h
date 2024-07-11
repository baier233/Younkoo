#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/Item.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/level/block/state/BlockState.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(ItemStack, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/ItemStack"))

JNI::Method<Item, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "getItem", "()Lnet/minecraft/world/item/Item;").first
)> getItem{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/ItemStack", "getDestroySpeed", "(Lnet/minecraft/world/level/block/state/BlockState;)F").first
), BlockState> getDestroySpeed{ *this };

END_KLASS_DEF();
END_1_20_1;
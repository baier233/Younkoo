#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/core/NonNullList.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/item/ItemStack.h>
BEGIN_1_18_1;
BEGIN_KLASS_DEF(Inventory, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Inventory"))

JNI::Field<NonNullList, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Inventory"), "items")
)> items{ *this };/* Lnet/minecraft/core/NonNullList; */

JNI::Field<NonNullList, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Inventory"), "armor")
)> armor{ *this };/* Lnet/minecraft/core/NonNullList; */

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/Container", "getItem", "(I)Lnet/minecraft/world/item/ItemStack;").first
), jint> getItem{ *this };


JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Inventory"), "selected")
)> selected{ *this };/* I */

JNI::Method<ItemStack, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/player/Inventory", "getSelected", "()Lnet/minecraft/world/item/ItemStack;").first
)> getSelected{ *this };

END_KLASS_DEF();
END_1_18_1;
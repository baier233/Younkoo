#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(DyeableLeatherItem, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/DyeableLeatherItem"))

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/item/DyeableLeatherItem", "getColor", "(Lnet/minecraft/world/item/ItemStack;)I").first
), ItemStack> getColor{ *this };

END_KLASS_DEF();
END_1_20_1;
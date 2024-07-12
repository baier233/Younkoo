#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/ChatFormatting.h>


BEGIN_1_18_1


BEGIN_KLASS_DEF(Rarity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"))
JNI::Field<Rarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"), "COMMON")
)> COMMON{ *this };/* Lnet/minecraft/world/item/Rarity; */

JNI::Field<Rarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"), "UNCOMMON")
)> UNCOMMON{ *this };/* Lnet/minecraft/world/item/Rarity; */

JNI::Field<Rarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"), "RARE")
)> RARE{ *this };/* Lnet/minecraft/world/item/Rarity; */

JNI::Field<Rarity, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"), "EPIC")
)> EPIC{ *this };/* Lnet/minecraft/world/item/Rarity; */

JNI::Field<ChatFormatting, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/item/Rarity"), "color")
)> color{ *this };/* Lnet/minecraft/ChatFormatting; */
END_KLASS_DEF();
END_1_18_1;
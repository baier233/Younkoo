#pragma once

#include <SDK.hpp>

BEGIN_1_18_1

BEGIN_KLASS_DEF(EntityAnchorArgument$Anchor, return SRGParser::get().getObfuscatedClassName("net/minecraft/commands/arguments/EntityAnchorArgument$Anchor"))
JNI::Field<EntityAnchorArgument$Anchor, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/commands/arguments/EntityAnchorArgument$Anchor"), "FEET")
)> FEET{ *this };/* Lnet/minecraft/commands/arguments/EntityAnchorArgument$Anchor; */

JNI::Field<EntityAnchorArgument$Anchor, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/commands/arguments/EntityAnchorArgument$Anchor"), "EYES")
)> EYES{ *this };/* Lnet/minecraft/commands/arguments/EntityAnchorArgument$Anchor; */
END_KLASS_DEF();
END_1_18_1
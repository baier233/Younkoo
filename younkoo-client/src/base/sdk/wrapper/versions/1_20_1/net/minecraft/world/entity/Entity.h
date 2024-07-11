#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_20_1/net/minecraft/world/phys/Vec3.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/phys/Vec2.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/Component.h>
#include <wrapper/versions/1_20_1/net/minecraft/commands/arguments/EntityAnchorArgument$Anchor.h>


BEGIN_1_20_1
BEGIN_KLASS_DEF(Entity, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"))
JNI::Field < Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "position")
)> position{ *this };/* Lnet/minecraft/world/phys/Vec3; */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setGlowingTag", "(Z)V").first
), jboolean> setGlowingTag{ *this };

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getPosition", "(F)Lnet/minecraft/world/phys/Vec3;").first
), jfloat> getPosition{ *this };

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "xOld")
)> xOld{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "yOld")
)> yOld{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "zOld")
)> zOld{ *this };/* D */

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getX", "()D").first
)> getX{ *this };

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getY", "()D").first
)> getY{ *this };

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getZ", "()D").first
)> getZ{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getBbHeight", "()F").first
)> getBbHeight{ *this };


JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getBbWidth", "()F").first
)> getBbWidth{ *this };

JNI::Method<Component, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/Nameable", "getDisplayName", "()Lnet/minecraft/network/chat/Component;").first
)> getDisplayName{ *this };

JNI::Method<Vec2, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getRotationVector", "()Lnet/minecraft/world/phys/Vec2;").first
)> getRotationVector{ *this };

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getEyeHeight", "()F").first
)> getEyeHeight{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setRot", "(FF)V").first
), jfloat, jfloat> setRot{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setYRot", "(F)V").first
), jfloat> setYRot{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setXRot", "(F)V").first
), jfloat> setXRot{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "isShiftKeyDown", "()Z").first
)> isShiftKeyDown{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "lookAt", "(Lnet/minecraft/commands/arguments/EntityAnchorArgument$Anchor;Lnet/minecraft/world/phys/Vec3;)V").first
), EntityAnchorArgument$Anchor, Vec3> lookAt{ *this };


JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setYHeadRot", "(F)V").first
), jfloat> setYHeadRot{ *this };

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "yRotO")
)> yRotO{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "xRotO")
)> xRotO{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "yRot")
)> yRot{ *this };/* F */

JNI::Field<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/Entity"), "xRot")
)> xRot{ *this };/* F */

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "isOnGround", "()Z").first
)> isOnGround{ *this };

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "getDeltaMovement", "()Lnet/minecraft/world/phys/Vec3;").first
)> getDeltaMovement{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setDeltaMovement", "(Lnet/minecraft/world/phys/Vec3;)V").first
), Vec3> setDeltaMovement{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/Entity", "setShiftKeyDown", "(Z)V").first
), jboolean> setShiftKeyDown{ *this };
END_KLASS_DEF()
END_1_20_1
#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_20_1/net/minecraft/world/phys/Vec3.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF(BlockPos, return SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"))

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_X_LENGTH")
)> PACKED_X_LENGTH{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_Z_LENGTH")
)> PACKED_Z_LENGTH{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_Y_LENGTH")
)> PACKED_Y_LENGTH{ *this };/* I */

JNI::Field<jlong, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_X_MASK")
)> PACKED_X_MASK{ *this };/* J */

JNI::Field<jlong, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_Y_MASK")
)> PACKED_Y_MASK{ *this };/* J */

JNI::Field<jlong, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "PACKED_Z_MASK")
)> PACKED_Z_MASK{ *this };/* J */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "Y_OFFSET")
)> Y_OFFSET{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "Z_OFFSET")
)> Z_OFFSET{ *this };/* I */

JNI::Field<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/BlockPos"), "X_OFFSET")
)> X_OFFSET{ *this };/* I */

JNI::Method<jlong, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/BlockPos", "offset", "(JIII)J").first
), jlong, jint, jint, jint> offset{ *this };

JNI::Method<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/BlockPos", "getX", "(J)I").first
), jlong> getX{ *this };

JNI::Method<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/BlockPos", "getY", "(J)I").first
), jlong> getY{ *this };

JNI::Method<jint, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/core/BlockPos", "getZ", "(J)I").first
), jlong> getZ{ *this };

JNI::ConstructorMethod<jdouble, jdouble, jdouble> consturctor1{ *this };
static inline BlockPos create(jdouble x, jdouble y, jdouble z) {
	return BlockPos::new_object(&BlockPos::consturctor1, x, y, z);
}

JNI::ConstructorMethod<Vec3> consturctor2{ *this };
static inline BlockPos create(Vec3 vec3_obj) {
	return BlockPos::new_object(&BlockPos::consturctor2, vec3_obj);
}

static inline BlockPos create(Math::Vector3D vec3) {
	return BlockPos::new_object(&BlockPos::consturctor2, Vec3::fromVector3(vec3));
}
END_KLASS_DEF();

END_1_20_1
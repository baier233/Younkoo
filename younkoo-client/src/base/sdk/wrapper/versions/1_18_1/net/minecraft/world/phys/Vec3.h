#pragma once
#include <SDK.hpp>

#include <utils/types/Maths.hpp>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Vec3, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"))

JNI::Field<Vec3, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "ZERO")
)> ZERO{ *this };/* Lnet/minecraft/world/phys/Vec3; */
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "x")
)> x{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "y")
)> y{ *this };/* D */
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/Vec3"), "z")
)> z{ *this };/* D */
JNI::ConstructorMethod<jdouble, jdouble, jdouble> constructor{ *this };

Math::Vector3D toVector3() {
	return Math::Vector3D(x.get(), y.get(), z.get());
}
static inline Vec3 fromVector3(Math::Vector3D vec) {
	return Vec3::new_object(&Vec3::constructor, (jdouble)vec.x, (jdouble)vec.y, (jdouble)vec.z);
}
END_KLASS_DEF();

END_1_18_1
//"JNI::Klass<members_type, get_class_name_lambda>::new_object [其中 members_type=V1_18_1::Vec3_members, get_class_name_lambda=lambda []()->std::string]"
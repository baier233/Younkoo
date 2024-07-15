#pragma once
#include <SDK.hpp>

#include <utils/types/Maths.hpp>

BEGIN_1_18_1

BEGIN_KLASS_DEF(Vec3i, return SRGParser::get().getObfuscatedClassName("net/minecraft/core/Vec3i"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/Vec3i"), "x")
)> x{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/Vec3i"), "y")
)> y{ *this };/* I */

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/core/Vec3i"), "z")
)> z{ *this };/* I */
END_KLASS_DEF();

END_1_18_1
//"JNI::Klass<members_type, get_class_name_lambda>::new_object [其中 members_type=V1_18_1::Vec3_members, get_class_name_lambda=lambda []()->std::string]"
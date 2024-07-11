#pragma once
#include <SDK.hpp>

#include <utils/types/Maths.hpp>

BEGIN_1_18_1
BEGIN_KLASS_DEF(AABB, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"))

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "minX")
)> minX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "minY")
)> minY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "minZ")
)> minZ{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "maxX")
)> maxX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "maxY")
)> maxY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/AABB"), "maxZ")
)> maxZ{ *this };/* D */

inline Math::Box<double> toBox() {
	return Math::Box<double>{
		this->minX.get(), this->minY.get(), this->minZ.get(),
			this->maxX.get(), this->maxY.get(), this->maxZ.get()
	};
}
END_KLASS_DEF();

END_1_18_1
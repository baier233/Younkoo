#pragma once
#include <SDK.hpp>

BEGIN_1_20_1

BEGIN_KLASS_DEF(Window, return SRGParser::get().getObfuscatedClassName("com/mojang/blaze3d/platform/Window"))

JNI::Field<jint, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("com/mojang/blaze3d/platform/Window"), "height")
)> height{ *this };/* I */

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/platform/Window", "getGuiScale", "()D").first
)> getGuiScale{ *this };
END_KLASS_DEF();

END_1_20_1
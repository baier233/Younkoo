#pragma once
#include <SDK.hpp>

#include <wrapper/versions/1_20_1/org/joml/Matrix4f.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF(PoseStack$Pose, return SRGParser::get().getObfuscatedClassName("com/mojang/blaze3d/vertex/PoseStack$Pose"))

JNI::Method<Matrix4f, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/vertex/PoseStack$Pose", "pose", "()Lcom/mojang/math/Matrix4f;").first
)> pose{ *this };
END_KLASS_DEF();

END_1_20_1
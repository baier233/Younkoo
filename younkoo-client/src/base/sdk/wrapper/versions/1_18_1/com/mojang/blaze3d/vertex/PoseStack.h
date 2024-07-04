#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/com/mojang/blaze3d/vertex/PoseStack$Pose.h>
#include <wrapper/versions/1_18_1/com/mojang/math/Matrix4f.h>

BEGIN_1_18_1

BEGIN_KLASS_DEF(PoseStack, return SRGParser::get().getObfuscatedClassName("com/mojang/blaze3d/vertex/PoseStack"))

JNI::Method<PoseStack$Pose, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/vertex/PoseStack", "last", "()Lcom/mojang/blaze3d/vertex/PoseStack$Pose;").first
)> last{ *this };

END_KLASS_DEF();

END_1_18_1
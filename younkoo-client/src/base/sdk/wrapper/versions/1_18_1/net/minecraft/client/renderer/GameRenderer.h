#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/com/mojang/blaze3d/vertex/PoseStack.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/Camera.h>
BEGIN_1_18_1

BEGIN_KLASS_DEF(GameRenderer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/GameRenderer"))
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/GameRenderer", "renderLevel", "(FJLcom/mojang/blaze3d/vertex/PoseStack;)V").first
), jfloat, jlong, PoseStack> renderLevel{ *this };

JNI::Method<Camera, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/GameRenderer", "getMainCamera", "()Lnet/minecraft/client/Camera;").first
)> getMainCamera{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/GameRenderer", "render", "(FJZ)V").first
), jfloat, jlong, jboolean> render{ *this };
END_KLASS_DEF();

END_1_18_1
#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>

#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/entity/BlockEntity.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/renderer/blockentity/BlockEntityRenderer.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(BlockEntityRenderDispatcher, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher"))
JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher", "tryRender", "(Lnet/minecraft/world/level/block/entity/BlockEntity;Ljava/lang/Runnable;)V").first
), BlockEntity, JDK::Runnable> tryRender{ *this };

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher", "setupAndRender", "(Lnet/minecraft/client/renderer/blockentity/BlockEntityRenderer;Lnet/minecraft/world/level/block/entity/BlockEntity;FLcom/mojang/blaze3d/vertex/PoseStack;Lnet/minecraft/client/renderer/MultiBufferSource;)V").first
), BlockEntityRenderer, BlockEntity, jfloat, PoseStack, MultiBufferSource> setupAndRender{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher", "render", "(Lnet/minecraft/world/level/block/entity/BlockEntity;FLcom/mojang/blaze3d/vertex/PoseStack;Lnet/minecraft/client/renderer/MultiBufferSource;)V").first
), BlockEntity, jfloat, PoseStack, MultiBufferSource> render{ *this };
END_KLASS_DEF()
END_1_18_1
#pragma once

#include <SDK.hpp>
#include <jdk/Classes.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/entity/BedBlockEntity.h>
#include <wrapper/versions/1_18_1/com/mojang/math/Matrix4f.h>
#include <wrapper/versions/1_18_1/com/mojang/blaze3d/vertex/PoseStack.h>

#include <wrapper/versions/1_18_1/net/minecraft/client/renderer/MultiBufferSource.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(BedRenderer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/renderer/blockentity/BedRenderer"))
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/renderer/blockentity/BedRenderer", "render", "(Lnet/minecraft/world/level/block/entity/BedBlockEntity;FLcom/mojang/blaze3d/vertex/PoseStack;Lnet/minecraft/client/renderer/MultiBufferSource;II)V").first
), BedBlockEntity, jfloat, PoseStack, MultiBufferSource, jint, jint> render{ *this };
END_KLASS_DEF();
END_1_18_1
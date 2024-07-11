#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/Minecraft.h>
#include <wrapper/versions/1_20_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/InteractionHand.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/ItemStack.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/Component.h>

BEGIN_1_20_1
BEGIN_KLASS_DEF(LocalPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"))

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "POSITION_REMINDER_INTERVAL")
)> POSITION_REMINDER_INTERVAL{ *this};/* I */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_MAX_TIME")
)> WATER_VISION_MAX_TIME{ *this};/* I */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_QUICK_TIME")
)> WATER_VISION_QUICK_TIME{ *this};/* I */

JNI::Field<jfloat, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "WATER_VISION_QUICK_PERCENT")
)> WATER_VISION_QUICK_PERCENT{ *this};/* F */

JNI::Field<jdouble, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "SUFFOCATING_COLLISION_CHECK_SCALE")
)> SUFFOCATING_COLLISION_CHECK_SCALE{ *this};/* D */

JNI::Field<jdouble, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "MINOR_COLLISION_ANGLE_THRESHOLD_RADIAN")
)> MINOR_COLLISION_ANGLE_THRESHOLD_RADIAN{ *this};/* D */

JNI::Field<jfloat, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "DEFAULT_SNEAKING_MOVEMENT_FACTOR")
)> DEFAULT_SNEAKING_MOVEMENT_FACTOR{ *this};/* F */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "permissionLevel")
)> permissionLevel{ *this};/* I */

JNI::Field<jdouble, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xLast")
)> xLast{ *this};/* D */

JNI::Field<jdouble, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yLast1")
)> yLast1{ *this};/* D */

JNI::Field<jdouble, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "zLast")
)> zLast{ *this};/* D */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yRotLast")
)> yRotLast{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xRotLast")
)> xRotLast{ *this};/* F */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "lastOnGround")
)> lastOnGround{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "crouching")
)> crouching{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasShiftKeyDown")
)> wasShiftKeyDown{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasSprinting")
)> wasSprinting{ *this};/* Z */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "positionReminder")
)> positionReminder{ *this};/* I */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "flashOnSetHealth")
)> flashOnSetHealth{ *this};/* Z */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "serverBrand")
)> serverBrand{ *this};/* Ljava/lang/String; */

JNI::Field<Minecraft, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "minecraft")
)> minecraft{ *this};/* Lnet/minecraft/client/Minecraft; */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "sprintTriggerTime")
)> sprintTriggerTime{ *this};/* I */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yBob")
)> yBob{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xBob")
)> xBob{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "yBobO")
)> yBobO{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "xBobO")
)> xBobO{ *this};/* F */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "jumpRidingTicks")
)> jumpRidingTicks{ *this};/* I */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "jumpRidingScale")
)> jumpRidingScale{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "spinningEffectIntensity")
)> spinningEffectIntensity{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "oSpinningEffectIntensity")
)> oSpinningEffectIntensity{ *this};/* F */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "startedUsingItem")
)> startedUsingItem{ *this};/* Z */

JNI::Field<InteractionHand, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "usingItemHand")
)> usingItemHand{ *this};/* Lnet/minecraft/world/InteractionHand; */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "handsBusy")
)> handsBusy{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "autoJumpEnabled")
)> autoJumpEnabled{ *this};/* Z */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "autoJumpTime")
)> autoJumpTime{ *this};/* I */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "wasFallFlying")
)> wasFallFlying{ *this};/* Z */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "waterVisionTime")
)> waterVisionTime{ *this};/* I */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/LocalPlayer"), "showDeathScreen")
)> showDeathScreen{ *this};/* Z */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "heal", "(F)V").first
),jfloat> heal{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "startRiding", "(Lnet/minecraft/world/entity/Entity;Z)Z").first
),Entity,jboolean> startRiding{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "removeVehicle", "()V").first
)> removeVehicle{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getViewXRot", "(F)F").first
),jfloat> getViewXRot{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getViewYRot", "(F)F").first
),jfloat> getViewYRot{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "tick", "()V").first
)> tick{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getCurrentMood", "()F").first
)> getCurrentMood{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "sendPosition", "()V").first
)> sendPosition{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "sendIsSprintingIfNeeded", "()V").first
)> sendIsSprintingIfNeeded{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "drop", "(Z)Z").first
),jboolean> drop{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "swing", "(Lnet/minecraft/world/InteractionHand;)V").first
),InteractionHand> swing{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "respawn", "()V").first
)> respawn{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "closeContainer", "()V").first
)> closeContainer{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "clientSideCloseContainer", "()V").first
)> clientSideCloseContainer{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "hurtTo", "(F)V").first
),jfloat> hurtTo{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "onUpdateAbilities", "()V").first
)> onUpdateAbilities{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isLocalPlayer", "()Z").first
)> isLocalPlayer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isSuppressingSlidingDownLadder", "()Z").first
)> isSuppressingSlidingDownLadder{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "canSpawnSprintParticle", "()Z").first
)> canSpawnSprintParticle{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "canSpawnSoulSpeedParticle", "()Z").first
)> canSpawnSoulSpeedParticle{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "sendRidingJump", "()V").first
)> sendRidingJump{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "sendOpenInventory", "()V").first
)> sendOpenInventory{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "setServerBrand", "(Ljava/lang/String;)V").first
),String> setServerBrand{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getServerBrand", "()Ljava/lang/String;").first
)> getServerBrand{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getPermissionLevel", "()I").first
)> getPermissionLevel{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "setPermissionLevel", "(I)V").first
),jint> setPermissionLevel{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "displayClientMessage", "(Lnet/minecraft/network/chat/Component;Z)V").first
),Component,jboolean> displayClientMessage{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "moveTowardsClosestSpace", "(DD)V").first
),jdouble,jdouble> moveTowardsClosestSpace{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "suffocatesAt", "(Lnet/minecraft/core/BlockPos;)Z").first
),BlockPos> suffocatesAt{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "setExperienceValues", "(FII)V").first
),jfloat,jint,jint> setExperienceValues{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "sendSystemMessage", "(Lnet/minecraft/network/chat/Component;)V").first
),Component> sendSystemMessage{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "handleEntityEvent", "(B)V").first
),jbyte> handleEntityEvent{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "setShowDeathScreen", "(Z)V").first
),jboolean> setShowDeathScreen{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "shouldShowDeathScreen", "()Z").first
)> shouldShowDeathScreen{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isEffectiveAi", "()Z").first
)> isEffectiveAi{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "startUsingItem", "(Lnet/minecraft/world/InteractionHand;)V").first
),InteractionHand> startUsingItem{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isUsingItem", "()Z").first
)> isUsingItem{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "stopUsingItem", "()V").first
)> stopUsingItem{ *this};

JNI::Method<InteractionHand, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getUsedItemHand", "()Lnet/minecraft/world/InteractionHand;").first
)> getUsedItemHand{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getJumpRidingScale", "()F").first
)> getJumpRidingScale{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isTextFilteringEnabled", "()Z").first
)> isTextFilteringEnabled{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "openItemGui", "(Lnet/minecraft/world/item/ItemStack;Lnet/minecraft/world/InteractionHand;)V").first
),ItemStack,InteractionHand> openItemGui{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "crit", "(Lnet/minecraft/world/entity/Entity;)V").first
),Entity> crit{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "magicCrit", "(Lnet/minecraft/world/entity/Entity;)V").first
),Entity> magicCrit{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isShiftKeyDown", "()Z").first
)> isShiftKeyDown{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isCrouching", "()Z").first
)> isCrouching{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isMovingSlowly", "()Z").first
)> isMovingSlowly{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "serverAiStep", "()V").first
)> serverAiStep{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isControlledCamera", "()Z").first
)> isControlledCamera{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "resetPos", "()V").first
)> resetPos{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "aiStep", "()V").first
)> aiStep{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "tickDeath", "()V").first
)> tickDeath{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "handleNetherPortalClient", "()V").first
)> handleNetherPortalClient{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "rideTick", "()V").first
)> rideTick{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isHandsBusy", "()Z").first
)> isHandsBusy{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isAutoJumpEnabled", "()Z").first
)> isAutoJumpEnabled{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "updateAutoJump", "(FF)V").first
),jfloat,jfloat> updateAutoJump{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isHorizontalCollisionMinor", "(Lnet/minecraft/world/phys/Vec3;)Z").first
),Vec3> isHorizontalCollisionMinor{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "canAutoJump", "()Z").first
)> canAutoJump{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isMoving", "()Z").first
)> isMoving{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "canStartSprinting", "()Z").first
)> canStartSprinting{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "vehicleCanSprint", "(Lnet/minecraft/world/entity/Entity;)Z").first
),Entity> vehicleCanSprint{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "hasEnoughImpulseToStartSprinting", "()Z").first
)> hasEnoughImpulseToStartSprinting{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "hasEnoughFoodToStartSprinting", "()Z").first
)> hasEnoughFoodToStartSprinting{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getWaterVision", "()F").first
)> getWaterVision{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "isUnderWater", "()Z").first
)> isUnderWater{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "updateIsUnderwater", "()Z").first
)> updateIsUnderwater{ *this};

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getRopeHoldPosition", "(F)Lnet/minecraft/world/phys/Vec3;").first
),jfloat> getRopeHoldPosition{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "updateSyncFields", "(Lnet/minecraft/client/player/LocalPlayer;)V").first
),LocalPlayer> updateSyncFields{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/LocalPlayer", "getVisualRotationYInDegrees", "()F").first
)> getVisualRotationYInDegrees{ *this};

END_KLASS_DEF();
END_1_20_1
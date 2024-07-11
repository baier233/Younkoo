#pragma once

#include <SDK.hpp>
#include <wrapper/java/lang/String.h>
#include <wrapper/versions/1_20_1/net/minecraft/resources/ResourceLocation.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/multiplayer/ClientLevel.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/phys/Vec3.h>
BEGIN_1_20_1

BEGIN_KLASS_DEF(AbstractClientPlayer, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"))
JNI::Field<String, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "SKIN_URL_TEMPLATE")
)> SKIN_URL_TEMPLATE{ *this};/* Ljava/lang/String; */

JNI::Field<Vec3, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "deltaMovementOnPreviousTick")
)> deltaMovementOnPreviousTick{ *this};/* Lnet/minecraft/world/phys/Vec3; */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "elytraRotX")
)> elytraRotX{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "elytraRotY")
)> elytraRotY{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "elytraRotZ")
)> elytraRotZ{ *this};/* F */

JNI::Field<ClientLevel, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/AbstractClientPlayer"), "clientLevel")
)> clientLevel{ *this};/* Lnet/minecraft/client/multiplayer/ClientLevel; */

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "isCreative", "()Z").first
)> isCreative{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "isCapeLoaded", "()Z").first
)> isCapeLoaded{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "tick", "()V").first
)> tick{ *this};

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getDeltaMovementLerped", "(F)Lnet/minecraft/world/phys/Vec3;").first
),jfloat> getDeltaMovementLerped{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "isSkinLoaded", "()Z").first
)> isSkinLoaded{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getSkinTextureLocation", "()Lnet/minecraft/resources/ResourceLocation;").first
)> getSkinTextureLocation{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getCloakTextureLocation", "()Lnet/minecraft/resources/ResourceLocation;").first
)> getCloakTextureLocation{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "isElytraLoaded", "()Z").first
)> isElytraLoaded{ *this};

JNI::Method<ResourceLocation, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getElytraTextureLocation", "()Lnet/minecraft/resources/ResourceLocation;").first
)> getElytraTextureLocation{ *this};

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "registerSkinTexture", "(Lnet/minecraft/resources/ResourceLocation;Ljava/lang/String;)V").first
),ResourceLocation,String> registerSkinTexture{ *this};

JNI::Method<ResourceLocation, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getSkinLocation", "(Ljava/lang/String;)Lnet/minecraft/resources/ResourceLocation;").first
),String> getSkinLocation{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getModelName", "()Ljava/lang/String;").first
)> getModelName{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/AbstractClientPlayer", "getFieldOfViewModifier", "()F").first
)> getFieldOfViewModifier{ *this};

END_KLASS_DEF();

END_1_20_1
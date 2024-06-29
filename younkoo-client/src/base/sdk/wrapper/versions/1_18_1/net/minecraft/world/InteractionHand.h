#pragma once

#include <SDK.hpp>
#include "../../../../../java/lang/String.h"

BEGIN_1_18_1

BEGIN_KLASS_DEF(InteractionHand, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/InteractionHand"))
JNI::Field<InteractionHand, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/InteractionHand"), "MAIN_HAND")
)> MAIN_HAND{ *this};/* Lnet/minecraft/world/InteractionHand; */

JNI::Field<InteractionHand, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/InteractionHand"), "OFF_HAND")
)> OFF_HAND{ *this};/* Lnet/minecraft/world/InteractionHand; */

JNI::Field<JNI::Array<InteractionHand>, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/world/InteractionHand"), "$VALUES")
)> $VALUES{ *this};/* [Lnet/minecraft/world/InteractionHand; */

JNI::Method<JNI::Array<InteractionHand>, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/InteractionHand", "values", "()[Lnet/minecraft/world/InteractionHand;").first
)> values{ *this};

JNI::Method<InteractionHand, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/InteractionHand", "valueOf", "(Ljava/lang/String;)Lnet/minecraft/world/InteractionHand;").first
),String> valueOf{ *this};

JNI::Method<JNI::Array<InteractionHand>, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/InteractionHand", "$values", "()[Lnet/minecraft/world/InteractionHand;").first
)> $values{ *this};

END_KLASS_DEF();

END_1_18_1
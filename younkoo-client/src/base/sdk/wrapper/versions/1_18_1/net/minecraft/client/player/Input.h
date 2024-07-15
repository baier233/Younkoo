#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/phys/Vec2.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF(Input, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"))
JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "leftImpulse")
)> leftImpulse{ *this};/* F */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "forwardImpulse")
)> forwardImpulse{ *this};/* F */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "up")
)> up{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "down")
)> down{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "left")
)> left{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "right")
)> right{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "jumping")
)> jumping{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/player/Input"), "shiftKeyDown")
)> shiftKeyDown{ *this};/* Z */

JNI::ConstructorMethod<> constructor_0 {*this};JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/Input", "tick", "(Z)V").first
),jboolean> tick{ *this};

JNI::Method<Vec2, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/Input", "getMoveVector", "()Lnet/minecraft/world/phys/Vec2;").first
)> getMoveVector{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/player/Input", "hasForwardImpulse", "()Z").first
)> hasForwardImpulse{ *this};

END_KLASS_DEF();

END_1_18_1
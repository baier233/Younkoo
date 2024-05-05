#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"
#include "HitResult_Type.h"

BEGIN_KLASS_DEF(HitResult, if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
{
	return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult");
}
else {
	return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult");
})

JNI::Method<HitResult_Type, JNI::NOT_STATIC> getType{ []() {
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/phys/HitResult", "getType", "()Lnet/minecraft/world/phys/HitResult$Type;").first;
	} ,*this };

END_KLASS_DEF();
#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"

BEGIN_KLASS_DEF(HitResult_Type, if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
{
	return SRGParser::get().getObfuscatedClassName("net/minecraft/world/phys/HitResult$Type");
}
else {
	return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/RayTraceResult$Type");
})

JNI::Field<HitResult_Type, JNI::STATIC> MISS{ []() {
	return "MISS";
	} ,*this };
JNI::Field<HitResult_Type, JNI::STATIC> BLOCK{ []() {
	return "BLOCK";
	} ,*this };
JNI::Field<HitResult_Type, JNI::STATIC> ENTITY{ []() {
	return "ENTITY";
	} ,*this };
END_KLASS_DEF();
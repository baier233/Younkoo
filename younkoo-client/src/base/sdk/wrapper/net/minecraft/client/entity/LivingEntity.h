#pragma once
#include <SDK.hpp>
#include "../src/base/Younkoo.hpp"

BEGIN_KLASS_DEF(LivingEntity, if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
{
	return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/LivingEntity");
}
else {
	return SRGParser::get().getObfuscatedClassName("net/minecraft/client/entity/EntityPlayerSP");
})
JNI::Method<jboolean, JNI::NOT_STATIC> isUsingItem{ []() {
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/LivingEntity", "isUsingItem", "()Z").first;
} ,*this };
END_KLASS_DEF();


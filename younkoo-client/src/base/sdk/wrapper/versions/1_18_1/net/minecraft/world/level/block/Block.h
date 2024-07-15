#pragma once

#include <SDK.hpp>
BEGIN_1_18_1
//class BlockState_members;
//using BlockState = JNI::Klass < BlockState_members, decltype([]() {return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/block/state/BlockState"); }) > ;
BEGIN_KLASS_DEF(Block, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/level/block/Block"))

//JNI::Method<jint, JNI::STATIC, DECLARE_NAME(
//	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/block/Block", "getId", "(Lnet/minecraft/world/level/block/state/BlockState;)I").first
//), BlockState> getId{ *this };
END_KLASS_DEF();

END_1_18_1
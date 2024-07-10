#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_18_1/net/minecraft/world/level/Level.h>

#include <jdk/Classes.h>



BEGIN_1_18_1

BEGIN_KLASS_DEF_EX(ClientLevel, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), Level)
JNI::Field < JDK::List, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "players")
)> players{ *this };/* Ljava/util/List; */

END_KLASS_DEF();


END_1_18_1
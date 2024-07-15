#pragma once

#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/LivingEntity.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Inventory.h>

BEGIN_1_18_1
BEGIN_KLASS_DEF_EX(Player, return SRGParser::get().getObfuscatedClassName("net/minecraft/world/entity/player/Player"), LivingEntity)
JNI::Method<Inventory, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/player/Player", "getInventory", "()Lnet/minecraft/world/entity/player/Inventory;").first
)> getInventory{ *this };

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/player/Player", "canHarmPlayer", "(Lnet/minecraft/world/entity/player/Player;)Z").first
), Player> canHarmPlayer{ *this };

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/world/entity/player/Player", "attack", "(Lnet/minecraft/world/entity/Entity;)V").first
), Entity> attack{ *this };

END_KLASS_DEF()
END_1_18_1
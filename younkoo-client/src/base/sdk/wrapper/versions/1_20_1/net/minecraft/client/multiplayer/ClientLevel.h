#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_20_1/net/minecraft/client/Minecraft.h>
#include <wrapper/versions/1_20_1/net/minecraft/core/BlockPos.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/level/block/state/BlockState.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/InteractionHand.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/entity/Entity.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/level/Level.h>
#include <jdk/Classes.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF_EX(ClientLevel, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), Level)

JNI::Field<jdouble, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "FLUID_PARTICLE_SPAWN_OFFSET")
)> FLUID_PARTICLE_SPAWN_OFFSET{ *this};/* D */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "NORMAL_LIGHT_UPDATES_PER_FRAME")
)> NORMAL_LIGHT_UPDATES_PER_FRAME{ *this};/* I */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "LIGHT_UPDATE_QUEUE_SIZE_THRESHOLD")
)> LIGHT_UPDATE_QUEUE_SIZE_THRESHOLD{ *this};/* I */
JNI::Field<Minecraft, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "minecraft")
)> minecraft{ *this};/* Lnet/minecraft/client/Minecraft; */

JNI::Field<List, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "players")
)> players{ *this};/* Ljava/util/List; */

JNI::Field<jlong, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "CLOUD_COLOR")
)> CLOUD_COLOR{ *this};/* J */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "skyFlashTime")
)> skyFlashTime{ *this};/* I */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/multiplayer/ClientLevel"), "serverSimulationDistance")
)> serverSimulationDistance{ *this};/* I */

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "handleBlockChangedAck", "(I)V").first
),jint> handleBlockChangedAck{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setServerVerifiedBlockState", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;I)V").first
),BlockPos,BlockState,jint> setServerVerifiedBlockState{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "syncBlockState", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;Lnet/minecraft/world/phys/Vec3;)V").first
),BlockPos,BlockState,Vec3> syncBlockState{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setBlock", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;II)Z").first
),BlockPos,BlockState,jint,jint> setBlock{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "pollLightUpdates", "()V").first
)> pollLightUpdates{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "isLightUpdateQueueEmpty", "()Z").first
)> isLightUpdateQueueEmpty{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "tickTime", "()V").first
)> tickTime{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setGameTime", "(J)V").first
),jlong> setGameTime{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setDayTime", "(J)V").first
),jlong> setDayTime{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "tickEntities", "()V").first
)> tickEntities{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "shouldTickDeath", "(Lnet/minecraft/world/entity/Entity;)Z").first
),Entity> shouldTickDeath{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "tickNonPassenger", "(Lnet/minecraft/world/entity/Entity;)V").first
),Entity> tickNonPassenger{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "tickPassenger", "(Lnet/minecraft/world/entity/Entity;Lnet/minecraft/world/entity/Entity;)V").first
),Entity,Entity> tickPassenger{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "clearTintCaches", "()V").first
)> clearTintCaches{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "hasChunk", "(II)Z").first
),jint,jint> hasChunk{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getEntityCount", "()I").first
)> getEntityCount{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "addPlayer", "(ILnet/minecraft/client/player/AbstractClientPlayer;)V").first
),jint,AbstractClientPlayer> addPlayer{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "putNonPlayerEntity", "(ILnet/minecraft/world/entity/Entity;)V").first
),jint,Entity> putNonPlayerEntity{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "addEntity", "(ILnet/minecraft/world/entity/Entity;)V").first
),jint,Entity> addEntity{ *this};

JNI::Method<Entity, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getEntity", "(I)Lnet/minecraft/world/entity/Entity;").first
),jint> getEntity{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "disconnect", "()V").first
)> disconnect{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "animateTick", "(III)V").first
),jint,jint,jint> animateTick{ *this};

JNI::Method<Block, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getMarkerParticleTarget", "()Lnet/minecraft/world/level/block/Block;").first
)> getMarkerParticleTarget{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "sendBlockUpdated", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;Lnet/minecraft/world/level/block/state/BlockState;I)V").first
),BlockPos,BlockState,BlockState,jint> sendBlockUpdated{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setBlocksDirty", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;Lnet/minecraft/world/level/block/state/BlockState;)V").first
),BlockPos,BlockState,BlockState> setBlocksDirty{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setSectionDirtyWithNeighbors", "(III)V").first
),jint,jint,jint> setSectionDirtyWithNeighbors{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "destroyBlockProgress", "(ILnet/minecraft/core/BlockPos;I)V").first
),jint,BlockPos,jint> destroyBlockProgress{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "globalLevelEvent", "(ILnet/minecraft/core/BlockPos;I)V").first
),jint,BlockPos,jint> globalLevelEvent{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getSkyDarken", "(F)F").first
),jfloat> getSkyDarken{ *this};

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getSkyColor", "(Lnet/minecraft/world/phys/Vec3;F)Lnet/minecraft/world/phys/Vec3;").first
),Vec3,jfloat> getSkyColor{ *this};

JNI::Method<Vec3, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getCloudColor", "(F)Lnet/minecraft/world/phys/Vec3;").first
),jfloat> getCloudColor{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getStarBrightness", "(F)F").first
),jfloat> getStarBrightness{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getSkyFlashTime", "()I").first
)> getSkyFlashTime{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setSkyFlashTime", "(I)V").first
),jint> setSkyFlashTime{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setDefaultSpawnPos", "(Lnet/minecraft/core/BlockPos;F)V").first
),BlockPos,jfloat> setDefaultSpawnPos{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "toString", "()Ljava/lang/String;").first
)> toString{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "gatherChunkSourceStats", "()Ljava/lang/String;").first
)> gatherChunkSourceStats{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "addDestroyBlockEffect", "(Lnet/minecraft/core/BlockPos;Lnet/minecraft/world/level/block/state/BlockState;)V").first
),BlockPos,BlockState> addDestroyBlockEffect{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "setServerSimulationDistance", "(I)V").first
),jint> setServerSimulationDistance{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getServerSimulationDistance", "()I").first
)> getServerSimulationDistance{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "getShade", "(FFFZ)F").first
),jfloat,jfloat,jfloat,jboolean> getShade{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_2933", "()Ljava/lang/String;").first
)> method_2933{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_2946", "()Ljava/lang/String;").first
)> method_2946{ *this};

JNI::Method<String, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_18649", "(Lnet/minecraft/world/entity/Entity;)Ljava/lang/String;").first
),Entity> method_18649{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_32124", "(Lnet/minecraft/world/entity/Entity;)V").first
),Entity> method_32124{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_38535", "(Lnet/minecraft/core/BlockPos;)I").first
),BlockPos> method_38535{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_38537", "(Lnet/minecraft/core/BlockPos;)I").first
),BlockPos> method_38537{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/multiplayer/ClientLevel", "method_38538", "(Lnet/minecraft/core/BlockPos;)I").first
),BlockPos> method_38538{ *this};

END_KLASS_DEF();
END_1_20_1
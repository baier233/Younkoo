#pragma once

#include <SDK.hpp>

#include <wrapper/versions/1_20_1/com/mojang/blaze3d/platform/Window.h>

BEGIN_1_20_1

BEGIN_KLASS_DEF(Minecraft, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"))
JNI::Field<Minecraft, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "instance")
)> instance{ *this};/* Lnet/minecraft/client/Minecraft; */

JNI::Field<Logger, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "LOGGER")
)> LOGGER{ *this};/* Lorg/slf4j/Logger; */

JNI::Field<jboolean, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "ON_OSX")
)> ON_OSX{ *this};/* Z */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "MAX_TICKS_PER_UPDATE")
)> MAX_TICKS_PER_UPDATE{ *this};/* I */

JNI::Field<ResourceLocation, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "DEFAULT_FONT")
)> DEFAULT_FONT{ *this};/* Lnet/minecraft/resources/ResourceLocation; */

JNI::Field<ResourceLocation, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "UNIFORM_FONT")
)> UNIFORM_FONT{ *this};/* Lnet/minecraft/resources/ResourceLocation; */

JNI::Field<ResourceLocation, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "ALT_FONT")
)> ALT_FONT{ *this};/* Lnet/minecraft/resources/ResourceLocation; */

JNI::Field<ResourceLocation, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "REGIONAL_COMPLIANCIES")
)> REGIONAL_COMPLIANCIES{ *this};/* Lnet/minecraft/resources/ResourceLocation; */

JNI::Field<CompletableFuture, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "RESOURCE_RELOAD_INITIAL_TASK")
)> RESOURCE_RELOAD_INITIAL_TASK{ *this};/* Ljava/util/concurrent/CompletableFuture; */

JNI::Field<Component, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "SOCIAL_INTERACTIONS_NOT_AVAILABLE")
)> SOCIAL_INTERACTIONS_NOT_AVAILABLE{ *this};/* Lnet/minecraft/network/chat/Component; */

JNI::Field<String, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "UPDATE_DRIVERS_ADVICE")
)> UPDATE_DRIVERS_ADVICE{ *this};/* Ljava/lang/String; */

JNI::Field<Path, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "resourcePackDirectory")
)> resourcePackDirectory{ *this};/* Ljava/nio/file/Path; */

JNI::Field<PropertyMap, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "profileProperties")
)> profileProperties{ *this};/* Lcom/mojang/authlib/properties/PropertyMap; */

JNI::Field<TextureManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "textureManager")
)> textureManager{ *this};/* Lnet/minecraft/client/renderer/texture/TextureManager; */

JNI::Field<DataFixer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fixerUpper")
)> fixerUpper{ *this};/* Lcom/mojang/datafixers/DataFixer; */

JNI::Field<VirtualScreen, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "virtualScreen")
)> virtualScreen{ *this};/* Lnet/minecraft/client/renderer/VirtualScreen; */

JNI::Field<Window, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "window")
)> window{ *this};/* Lcom/mojang/blaze3d/platform/Window; */

JNI::Field<Timer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "timer")
)> timer{ *this};/* Lnet/minecraft/client/Timer; */

JNI::Field<RenderBuffers, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "renderBuffers")
)> renderBuffers{ *this};/* Lnet/minecraft/client/renderer/RenderBuffers; */

JNI::Field<LevelRenderer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "levelRenderer")
)> levelRenderer{ *this};/* Lnet/minecraft/client/renderer/LevelRenderer; */

JNI::Field<EntityRenderDispatcher, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "entityRenderDispatcher")
)> entityRenderDispatcher{ *this};/* Lnet/minecraft/client/renderer/entity/EntityRenderDispatcher; */

JNI::Field<ItemRenderer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "itemRenderer")
)> itemRenderer{ *this};/* Lnet/minecraft/client/renderer/entity/ItemRenderer; */

JNI::Field<ParticleEngine, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "particleEngine")
)> particleEngine{ *this};/* Lnet/minecraft/client/particle/ParticleEngine; */

JNI::Field<SearchRegistry, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "searchRegistry")
)> searchRegistry{ *this};/* Lnet/minecraft/client/searchtree/SearchRegistry; */

JNI::Field<User, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "user")
)> user{ *this};/* Lnet/minecraft/client/User; */

JNI::Field<Font, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "font")
)> font{ *this};/* Lnet/minecraft/client/gui/Font; */

JNI::Field<Font, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fontFilterFishy")
)> fontFilterFishy{ *this};/* Lnet/minecraft/client/gui/Font; */

JNI::Field<GameRenderer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameRenderer")
)> gameRenderer{ *this};/* Lnet/minecraft/client/renderer/GameRenderer; */

JNI::Field<DebugRenderer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "debugRenderer")
)> debugRenderer{ *this};/* Lnet/minecraft/client/renderer/debug/DebugRenderer; */

JNI::Field<AtomicReference, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "progressListener")
)> progressListener{ *this};/* Ljava/util/concurrent/atomic/AtomicReference; */

JNI::Field<Gui, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gui")
)> gui{ *this};/* Lnet/minecraft/client/gui/Gui; */

JNI::Field<Options, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "options")
)> options{ *this};/* Lnet/minecraft/client/Options; */

JNI::Field<HotbarManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hotbarManager")
)> hotbarManager{ *this};/* Lnet/minecraft/client/HotbarManager; */

JNI::Field<MouseHandler, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "mouseHandler")
)> mouseHandler{ *this};/* Lnet/minecraft/client/MouseHandler; */

JNI::Field<KeyboardHandler, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "keyboardHandler")
)> keyboardHandler{ *this};/* Lnet/minecraft/client/KeyboardHandler; */

JNI::Field<InputType, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "lastInputType")
)> lastInputType{ *this};/* Lnet/minecraft/client/InputType; */

JNI::Field<File, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameDirectory")
)> gameDirectory{ *this};/* Ljava/io/File; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "launchedVersion")
)> launchedVersion{ *this};/* Ljava/lang/String; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "versionType")
)> versionType{ *this};/* Ljava/lang/String; */

JNI::Field<Proxy, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "proxy")
)> proxy{ *this};/* Ljava/net/Proxy; */

JNI::Field<LevelStorageSource, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "levelSource")
)> levelSource{ *this};/* Lnet/minecraft/world/level/storage/LevelStorageSource; */

JNI::Field<FrameTimer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "frameTimer")
)> frameTimer{ *this};/* Lnet/minecraft/util/FrameTimer; */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "is64bit")
)> is64bit{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "demo")
)> demo{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "allowsMultiplayer")
)> allowsMultiplayer{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "allowsChat")
)> allowsChat{ *this};/* Z */

JNI::Field<ReloadableResourceManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "resourceManager")
)> resourceManager{ *this};/* Lnet/minecraft/server/packs/resources/ReloadableResourceManager; */

JNI::Field<VanillaPackResources, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "vanillaPackResources")
)> vanillaPackResources{ *this};/* Lnet/minecraft/server/packs/VanillaPackResources; */

JNI::Field<DownloadedPackSource, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "downloadedPackSource")
)> downloadedPackSource{ *this};/* Lnet/minecraft/client/resources/DownloadedPackSource; */

JNI::Field<PackRepository, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "resourcePackRepository")
)> resourcePackRepository{ *this};/* Lnet/minecraft/server/packs/repository/PackRepository; */

JNI::Field<LanguageManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "languageManager")
)> languageManager{ *this};/* Lnet/minecraft/client/resources/language/LanguageManager; */

JNI::Field<BlockColors, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "blockColors")
)> blockColors{ *this};/* Lnet/minecraft/client/color/block/BlockColors; */

JNI::Field<ItemColors, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "itemColors")
)> itemColors{ *this};/* Lnet/minecraft/client/color/item/ItemColors; */

JNI::Field<RenderTarget, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "mainRenderTarget")
)> mainRenderTarget{ *this};/* Lcom/mojang/blaze3d/pipeline/RenderTarget; */

JNI::Field<SoundManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "soundManager")
)> soundManager{ *this};/* Lnet/minecraft/client/sounds/SoundManager; */

JNI::Field<MusicManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "musicManager")
)> musicManager{ *this};/* Lnet/minecraft/client/sounds/MusicManager; */

JNI::Field<FontManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fontManager")
)> fontManager{ *this};/* Lnet/minecraft/client/gui/font/FontManager; */

JNI::Field<SplashManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "splashManager")
)> splashManager{ *this};/* Lnet/minecraft/client/resources/SplashManager; */

JNI::Field<GpuWarnlistManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gpuWarnlistManager")
)> gpuWarnlistManager{ *this};/* Lnet/minecraft/client/renderer/GpuWarnlistManager; */

JNI::Field<PeriodicNotificationManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "regionalCompliancies")
)> regionalCompliancies{ *this};/* Lnet/minecraft/client/PeriodicNotificationManager; */

JNI::Field<YggdrasilAuthenticationService, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "authenticationService")
)> authenticationService{ *this};/* Lcom/mojang/authlib/yggdrasil/YggdrasilAuthenticationService; */

JNI::Field<MinecraftSessionService, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "minecraftSessionService")
)> minecraftSessionService{ *this};/* Lcom/mojang/authlib/minecraft/MinecraftSessionService; */

JNI::Field<UserApiService, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "userApiService")
)> userApiService{ *this};/* Lcom/mojang/authlib/minecraft/UserApiService; */

JNI::Field<SkinManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "skinManager")
)> skinManager{ *this};/* Lnet/minecraft/client/resources/SkinManager; */

JNI::Field<ModelManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "modelManager")
)> modelManager{ *this};/* Lnet/minecraft/client/resources/model/ModelManager; */

JNI::Field<BlockRenderDispatcher, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "blockRenderer")
)> blockRenderer{ *this};/* Lnet/minecraft/client/renderer/block/BlockRenderDispatcher; */

JNI::Field<PaintingTextureManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "paintingTextures")
)> paintingTextures{ *this};/* Lnet/minecraft/client/resources/PaintingTextureManager; */

JNI::Field<MobEffectTextureManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "mobEffectTextures")
)> mobEffectTextures{ *this};/* Lnet/minecraft/client/resources/MobEffectTextureManager; */

JNI::Field<ToastComponent, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "toast")
)> toast{ *this};/* Lnet/minecraft/client/gui/components/toasts/ToastComponent; */

JNI::Field<Tutorial, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "tutorial")
)> tutorial{ *this};/* Lnet/minecraft/client/tutorial/Tutorial; */

JNI::Field<PlayerSocialManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "playerSocialManager")
)> playerSocialManager{ *this};/* Lnet/minecraft/client/gui/screens/social/PlayerSocialManager; */

JNI::Field<EntityModelSet, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "entityModels")
)> entityModels{ *this};/* Lnet/minecraft/client/model/geom/EntityModelSet; */

JNI::Field<BlockEntityRenderDispatcher, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "blockEntityRenderDispatcher")
)> blockEntityRenderDispatcher{ *this};/* Lnet/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher; */

JNI::Field<ClientTelemetryManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "telemetryManager")
)> telemetryManager{ *this};/* Lnet/minecraft/client/telemetry/ClientTelemetryManager; */

JNI::Field<ProfileKeyPairManager, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "profileKeyPairManager")
)> profileKeyPairManager{ *this};/* Lnet/minecraft/client/multiplayer/ProfileKeyPairManager; */

JNI::Field<RealmsDataFetcher, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "realmsDataFetcher")
)> realmsDataFetcher{ *this};/* Lcom/mojang/realmsclient/gui/RealmsDataFetcher; */

JNI::Field<QuickPlayLog, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "quickPlayLog")
)> quickPlayLog{ *this};/* Lnet/minecraft/client/quickplay/QuickPlayLog; */

JNI::Field<MultiPlayerGameMode, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameMode")
)> gameMode{ *this};/* Lnet/minecraft/client/multiplayer/MultiPlayerGameMode; */

JNI::Field<ClientLevel, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "level")
)> level{ *this};/* Lnet/minecraft/client/multiplayer/ClientLevel; */

JNI::Field<LocalPlayer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "player")
)> player{ *this};/* Lnet/minecraft/client/player/LocalPlayer; */

JNI::Field<IntegratedServer, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "singleplayerServer")
)> singleplayerServer{ *this};/* Lnet/minecraft/client/server/IntegratedServer; */

JNI::Field<Connection, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "pendingConnection")
)> pendingConnection{ *this};/* Lnet/minecraft/network/Connection; */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "isLocalServer")
)> isLocalServer{ *this};/* Z */

JNI::Field<Entity, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "cameraEntity")
)> cameraEntity{ *this};/* Lnet/minecraft/world/entity/Entity; */

JNI::Field<Entity, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "crosshairPickEntity")
)> crosshairPickEntity{ *this};/* Lnet/minecraft/world/entity/Entity; */

JNI::Field<HitResult, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "hitResult")
)> hitResult{ *this};/* Lnet/minecraft/world/phys/HitResult; */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "rightClickDelay")
)> rightClickDelay{ *this};/* I */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "missTime")
)> missTime{ *this};/* I */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "pause")
)> pause{ *this};/* Z */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "pausePartialTick")
)> pausePartialTick{ *this};/* F */

JNI::Field<jlong, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "lastNanoTime")
)> lastNanoTime{ *this};/* J */

JNI::Field<jlong, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "lastTime")
)> lastTime{ *this};/* J */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "frames")
)> frames{ *this};/* I */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "noRender")
)> noRender{ *this};/* Z */

JNI::Field<Screen, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "screen")
)> screen{ *this};/* Lnet/minecraft/client/gui/screens/Screen; */

JNI::Field<Overlay, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "overlay")
)> overlay{ *this};/* Lnet/minecraft/client/gui/screens/Overlay; */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "connectedToRealms")
)> connectedToRealms{ *this};/* Z */

JNI::Field<Thread, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gameThread")
)> gameThread{ *this};/* Ljava/lang/Thread; */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "running")
)> running{ *this};/* Z */

JNI::Field<Supplier, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "delayedCrash")
)> delayedCrash{ *this};/* Ljava/util/function/Supplier; */

JNI::Field<jint, JNI::STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fps")
)> fps{ *this};/* I */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fpsString")
)> fpsString{ *this};/* Ljava/lang/String; */

JNI::Field<jlong, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "frameTimeNs")
)> frameTimeNs{ *this};/* J */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "wireframe")
)> wireframe{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "chunkPath")
)> chunkPath{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "chunkVisibility")
)> chunkVisibility{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "smartCull")
)> smartCull{ *this};/* Z */

JNI::Field<jboolean, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "windowActive")
)> windowActive{ *this};/* Z */

JNI::Field<Queue, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "progressTasks")
)> progressTasks{ *this};/* Ljava/util/Queue; */

JNI::Field<CompletableFuture, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "pendingReload")
)> pendingReload{ *this};/* Ljava/util/concurrent/CompletableFuture; */

JNI::Field<TutorialToast, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "socialInteractionsToast")
)> socialInteractionsToast{ *this};/* Lnet/minecraft/client/gui/components/toasts/TutorialToast; */

JNI::Field<ProfilerFiller, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "profiler")
)> profiler{ *this};/* Lnet/minecraft/util/profiling/ProfilerFiller; */

JNI::Field<jint, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fpsPieRenderTicks")
)> fpsPieRenderTicks{ *this};/* I */

JNI::Field<ContinuousProfiler, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fpsPieProfiler")
)> fpsPieProfiler{ *this};/* Lnet/minecraft/util/profiling/ContinuousProfiler; */

JNI::Field<ProfileResults, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "fpsPieResults")
)> fpsPieResults{ *this};/* Lnet/minecraft/util/profiling/ProfileResults; */

JNI::Field<MetricsRecorder, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "metricsRecorder")
)> metricsRecorder{ *this};/* Lnet/minecraft/util/profiling/metrics/profiling/MetricsRecorder; */

JNI::Field<ResourceLoadStateTracker, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "reloadStateTracker")
)> reloadStateTracker{ *this};/* Lnet/minecraft/client/ResourceLoadStateTracker; */

JNI::Field<jlong, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "savedCpuDuration")
)> savedCpuDuration{ *this};/* J */

JNI::Field<jdouble, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "gpuUtilization")
)> gpuUtilization{ *this};/* D */

JNI::Field<TimerQuery$FrameProfile, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "currentFrameProfile")
)> currentFrameProfile{ *this};/* Lcom/mojang/blaze3d/systems/TimerQuery$FrameProfile; */

JNI::Field<Realms32BitWarningStatus, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "realms32BitWarningStatus")
)> realms32BitWarningStatus{ *this};/* Lnet/minecraft/client/Realms32BitWarningStatus; */

JNI::Field<GameNarrator, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "narrator")
)> narrator{ *this};/* Lnet/minecraft/client/GameNarrator; */

JNI::Field<ChatListener, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "chatListener")
)> chatListener{ *this};/* Lnet/minecraft/client/multiplayer/chat/ChatListener; */

JNI::Field<ReportingContext, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "reportingContext")
)> reportingContext{ *this};/* Lnet/minecraft/client/multiplayer/chat/report/ReportingContext; */

JNI::Field<String, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "debugPath")
)> debugPath{ *this};/* Ljava/lang/String; */

JNI::Field<jfloat, JNI::NOT_STATIC ,DECLARE_NAME(
return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"), "realPartialTick")
)> realPartialTick{ *this};/* F */

JNI::ConstructorMethod<,GameConfig> constructor_0 {*this};JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "onGameLoadFinished", "()V").first
)> onGameLoadFinished{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setInitialScreen", "(Lcom/mojang/realmsclient/client/RealmsClient;Lnet/minecraft/server/packs/resources/ReloadInstance;Lnet/minecraft/client/main/GameConfig$QuickPlayData;)V").first
),RealmsClient,ReloadInstance,GameConfig$QuickPlayData> setInitialScreen{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "countryEqualsISO3", "(Ljava/lang/Object;)Z").first
),Object> countryEqualsISO3{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "updateTitle", "()V").first
)> updateTitle{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "createTitle", "()Ljava/lang/String;").first
)> createTitle{ *this};

JNI::Method<UserApiService, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "createUserApiService", "(Lcom/mojang/authlib/yggdrasil/YggdrasilAuthenticationService;Lnet/minecraft/client/main/GameConfig;)Lcom/mojang/authlib/minecraft/UserApiService;").first
),YggdrasilAuthenticationService,GameConfig> createUserApiService{ *this};

JNI::Method<ModCheck, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "checkModStatus", "()Lnet/minecraft/util/ModCheck;").first
)> checkModStatus{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "rollbackResourcePacks", "(Ljava/lang/Throwable;)V").first
),Throwable> rollbackResourcePacks{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "clearResourcePacksOnError", "(Ljava/lang/Throwable;Lnet/minecraft/network/chat/Component;)V").first
),Throwable,Component> clearResourcePacksOnError{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "abortResourcePackRecovery", "()V").first
)> abortResourcePackRecovery{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "addResourcePackLoadFailToast", "(Lnet/minecraft/network/chat/Component;)V").first
),Component> addResourcePackLoadFailToast{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "run", "()V").first
)> run{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "selectMainFont", "(Z)V").first
),jboolean> selectMainFont{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "createSearchTrees", "()V").first
)> createSearchTrees{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "onFullscreenError", "(IJ)V").first
),jint,jlong> onFullscreenError{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "checkIs64Bit", "()Z").first
)> checkIs64Bit{ *this};

JNI::Method<RenderTarget, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMainRenderTarget", "()Lcom/mojang/blaze3d/pipeline/RenderTarget;").first
)> getMainRenderTarget{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getLaunchedVersion", "()Ljava/lang/String;").first
)> getLaunchedVersion{ *this};

JNI::Method<String, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getVersionType", "()Ljava/lang/String;").first
)> getVersionType{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "delayCrash", "(Lnet/minecraft/CrashReport;)V").first
),CrashReport> delayCrash{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "delayCrashRaw", "(Lnet/minecraft/CrashReport;)V").first
),CrashReport> delayCrashRaw{ *this};

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "crash", "(Lnet/minecraft/CrashReport;)V").first
),CrashReport> crash{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isEnforceUnicode", "()Z").first
)> isEnforceUnicode{ *this};

JNI::Method<CompletableFuture, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "reloadResourcePacks", "()Ljava/util/concurrent/CompletableFuture;").first
)> reloadResourcePacks{ *this};

JNI::Method<CompletableFuture, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "reloadResourcePacks", "(Z)Ljava/util/concurrent/CompletableFuture;").first
),jboolean> reloadResourcePacks{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "selfTest", "()V").first
)> selfTest{ *this};

JNI::Method<LevelStorageSource, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getLevelSource", "()Lnet/minecraft/world/level/storage/LevelStorageSource;").first
)> getLevelSource{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "openChatScreen", "(Ljava/lang/String;)V").first
),String> openChatScreen{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setScreen", "(Lnet/minecraft/client/gui/screens/Screen;)V").first
),Screen> setScreen{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setOverlay", "(Lnet/minecraft/client/gui/screens/Overlay;)V").first
),Overlay> setOverlay{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "destroy", "()V").first
)> destroy{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "close", "()V").first
)> close{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "runTick", "(Z)V").first
),jboolean> runTick{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "shouldRenderFpsPie", "()Z").first
)> shouldRenderFpsPie{ *this};

JNI::Method<ProfilerFiller, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "constructProfiler", "(ZLnet/minecraft/util/profiling/SingleTickProfiler;)Lnet/minecraft/util/profiling/ProfilerFiller;").first
),jboolean,SingleTickProfiler> constructProfiler{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "finishProfilers", "(ZLnet/minecraft/util/profiling/SingleTickProfiler;)V").first
),jboolean,SingleTickProfiler> finishProfilers{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/platform/WindowEventHandler", "resizeDisplay", "()V").first
)> resizeDisplay{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/platform/WindowEventHandler", "cursorEntered", "()V").first
)> cursorEntered{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFps", "()I").first
)> getFps{ *this};

JNI::Method<jlong, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTimeNs", "()J").first
)> getFrameTimeNs{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFramerateLimit", "()I").first
)> getFramerateLimit{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "emergencySave", "()V").first
)> emergencySave{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "debugClientMetricsStart", "(Ljava/util/function/Consumer;)Z").first
),Consumer> debugClientMetricsStart{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "debugClientMetricsStop", "()V").first
)> debugClientMetricsStop{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "debugClientMetricsCancel", "()V").first
)> debugClientMetricsCancel{ *this};

JNI::Method<Path, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "archiveProfilingReport", "(Lnet/minecraft/SystemReport;Ljava/util/List;)Ljava/nio/file/Path;").first
),SystemReport,List> archiveProfilingReport{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "debugFpsMeterKeyPress", "(I)V").first
),jint> debugFpsMeterKeyPress{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "renderFpsMeter", "(Lnet/minecraft/client/gui/GuiGraphics;Lnet/minecraft/util/profiling/ProfileResults;)V").first
),GuiGraphics,ProfileResults> renderFpsMeter{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "stop", "()V").first
)> stop{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isRunning", "()Z").first
)> isRunning{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "pauseGame", "(Z)V").first
),jboolean> pauseGame{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "continueAttack", "(Z)V").first
),jboolean> continueAttack{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "startAttack", "()Z").first
)> startAttack{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "startUseItem", "()V").first
)> startUseItem{ *this};

JNI::Method<MusicManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMusicManager", "()Lnet/minecraft/client/sounds/MusicManager;").first
)> getMusicManager{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "tick", "()V").first
)> tick{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isMultiplayerServer", "()Z").first
)> isMultiplayerServer{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "handleKeybinds", "()V").first
)> handleKeybinds{ *this};

JNI::Method<ClientTelemetryManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getTelemetryManager", "()Lnet/minecraft/client/telemetry/ClientTelemetryManager;").first
)> getTelemetryManager{ *this};

JNI::Method<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getGpuUtilization", "()D").first
)> getGpuUtilization{ *this};

JNI::Method<ProfileKeyPairManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProfileKeyPairManager", "()Lnet/minecraft/client/multiplayer/ProfileKeyPairManager;").first
)> getProfileKeyPairManager{ *this};

JNI::Method<WorldOpenFlows, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "createWorldOpenFlows", "()Lnet/minecraft/client/gui/screens/worldselection/WorldOpenFlows;").first
)> createWorldOpenFlows{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "doWorldLoad", "(Ljava/lang/String;Lnet/minecraft/world/level/storage/LevelStorageSource$LevelStorageAccess;Lnet/minecraft/server/packs/repository/PackRepository;Lnet/minecraft/server/WorldStem;Z)V").first
),String,LevelStorageSource$LevelStorageAccess,PackRepository,WorldStem,jboolean> doWorldLoad{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setLevel", "(Lnet/minecraft/client/multiplayer/ClientLevel;)V").first
),ClientLevel> setLevel{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "clearLevel", "()V").first
)> clearLevel{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "clearLevel", "(Lnet/minecraft/client/gui/screens/Screen;)V").first
),Screen> clearLevel{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "updateScreenAndTick", "(Lnet/minecraft/client/gui/screens/Screen;)V").first
),Screen> updateScreenAndTick{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "forceSetScreen", "(Lnet/minecraft/client/gui/screens/Screen;)V").first
),Screen> forceSetScreen{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "updateLevelInEngines", "(Lnet/minecraft/client/multiplayer/ClientLevel;)V").first
),ClientLevel> updateLevelInEngines{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "telemetryOptInExtra", "()Z").first
)> telemetryOptInExtra{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "extraTelemetryAvailable", "()Z").first
)> extraTelemetryAvailable{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "allowsTelemetry", "()Z").first
)> allowsTelemetry{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "allowsMultiplayer", "()Z").first
)> allowsMultiplayer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "allowsRealms", "()Z").first
)> allowsRealms{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "shouldShowBanNotice", "()Z").first
)> shouldShowBanNotice{ *this};

JNI::Method<BanDetails, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "multiplayerBan", "()Lcom/mojang/authlib/minecraft/BanDetails;").first
)> multiplayerBan{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isBlocked", "(Ljava/util/UUID;)Z").first
),UUID> isBlocked{ *this};

JNI::Method<Minecraft$ChatStatus, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getChatStatus", "()Lnet/minecraft/client/Minecraft$ChatStatus;").first
)> getChatStatus{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isDemo", "()Z").first
)> isDemo{ *this};

JNI::Method<ClientPacketListener, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getConnection", "()Lnet/minecraft/client/multiplayer/ClientPacketListener;").first
)> getConnection{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "renderNames", "()Z").first
)> renderNames{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "useFancyGraphics", "()Z").first
)> useFancyGraphics{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "useShaderTransparency", "()Z").first
)> useShaderTransparency{ *this};

JNI::Method<jboolean, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "useAmbientOcclusion", "()Z").first
)> useAmbientOcclusion{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "pickBlock", "()V").first
)> pickBlock{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "addCustomNbtData", "(Lnet/minecraft/world/item/ItemStack;Lnet/minecraft/world/level/block/entity/BlockEntity;)V").first
),ItemStack,BlockEntity> addCustomNbtData{ *this};

JNI::Method<CrashReport, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "fillReport", "(Lnet/minecraft/CrashReport;)Lnet/minecraft/CrashReport;").first
),CrashReport> fillReport{ *this};

JNI::Method<void, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "fillReport", "(Lnet/minecraft/client/Minecraft;Lnet/minecraft/client/resources/language/LanguageManager;Ljava/lang/String;Lnet/minecraft/client/Options;Lnet/minecraft/CrashReport;)V").first
),Minecraft,LanguageManager,String,Options,CrashReport> fillReport{ *this};

JNI::Method<SystemReport, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "fillSystemReport", "(Lnet/minecraft/SystemReport;Lnet/minecraft/client/Minecraft;Lnet/minecraft/client/resources/language/LanguageManager;Ljava/lang/String;Lnet/minecraft/client/Options;)Lnet/minecraft/SystemReport;").first
),SystemReport,Minecraft,LanguageManager,String,Options> fillSystemReport{ *this};

JNI::Method<Minecraft, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;").first
)> getInstance{ *this};

JNI::Method<CompletableFuture, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "delayTextureReload", "()Ljava/util/concurrent/CompletableFuture;").first
)> delayTextureReload{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "updateReportEnvironment", "(Lnet/minecraft/client/multiplayer/chat/report/ReportEnvironment;)V").first
),ReportEnvironment> updateReportEnvironment{ *this};

JNI::Method<ServerData, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getCurrentServer", "()Lnet/minecraft/client/multiplayer/ServerData;").first
)> getCurrentServer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isLocalServer", "()Z").first
)> isLocalServer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "hasSingleplayerServer", "()Z").first
)> hasSingleplayerServer{ *this};

JNI::Method<IntegratedServer, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSingleplayerServer", "()Lnet/minecraft/client/server/IntegratedServer;").first
)> getSingleplayerServer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isSingleplayer", "()Z").first
)> isSingleplayer{ *this};

JNI::Method<User, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getUser", "()Lnet/minecraft/client/User;").first
)> getUser{ *this};

JNI::Method<PropertyMap, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProfileProperties", "()Lcom/mojang/authlib/properties/PropertyMap;").first
)> getProfileProperties{ *this};

JNI::Method<Proxy, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProxy", "()Ljava/net/Proxy;").first
)> getProxy{ *this};

JNI::Method<TextureManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getTextureManager", "()Lnet/minecraft/client/renderer/texture/TextureManager;").first
)> getTextureManager{ *this};

JNI::Method<ResourceManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getResourceManager", "()Lnet/minecraft/server/packs/resources/ResourceManager;").first
)> getResourceManager{ *this};

JNI::Method<PackRepository, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getResourcePackRepository", "()Lnet/minecraft/server/packs/repository/PackRepository;").first
)> getResourcePackRepository{ *this};

JNI::Method<VanillaPackResources, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getVanillaPackResources", "()Lnet/minecraft/server/packs/VanillaPackResources;").first
)> getVanillaPackResources{ *this};

JNI::Method<DownloadedPackSource, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getDownloadedPackSource", "()Lnet/minecraft/client/resources/DownloadedPackSource;").first
)> getDownloadedPackSource{ *this};

JNI::Method<Path, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getResourcePackDirectory", "()Ljava/nio/file/Path;").first
)> getResourcePackDirectory{ *this};

JNI::Method<LanguageManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getLanguageManager", "()Lnet/minecraft/client/resources/language/LanguageManager;").first
)> getLanguageManager{ *this};

JNI::Method<Function, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getTextureAtlas", "(Lnet/minecraft/resources/ResourceLocation;)Ljava/util/function/Function;").first
),ResourceLocation> getTextureAtlas{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "is64Bit", "()Z").first
)> is64Bit{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isPaused", "()Z").first
)> isPaused{ *this};

JNI::Method<GpuWarnlistManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getGpuWarnlistManager", "()Lnet/minecraft/client/renderer/GpuWarnlistManager;").first
)> getGpuWarnlistManager{ *this};

JNI::Method<SoundManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSoundManager", "()Lnet/minecraft/client/sounds/SoundManager;").first
)> getSoundManager{ *this};

JNI::Method<Music, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSituationalMusic", "()Lnet/minecraft/sounds/Music;").first
)> getSituationalMusic{ *this};

JNI::Method<MinecraftSessionService, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMinecraftSessionService", "()Lcom/mojang/authlib/minecraft/MinecraftSessionService;").first
)> getMinecraftSessionService{ *this};

JNI::Method<SkinManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSkinManager", "()Lnet/minecraft/client/resources/SkinManager;").first
)> getSkinManager{ *this};

JNI::Method<Entity, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getCameraEntity", "()Lnet/minecraft/world/entity/Entity;").first
)> getCameraEntity{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setCameraEntity", "(Lnet/minecraft/world/entity/Entity;)V").first
),Entity> setCameraEntity{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "shouldEntityAppearGlowing", "(Lnet/minecraft/world/entity/Entity;)Z").first
),Entity> shouldEntityAppearGlowing{ *this};

JNI::Method<Thread, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getRunningThread", "()Ljava/lang/Thread;").first
)> getRunningThread{ *this};

JNI::Method<Runnable, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "wrapRunnable", "(Ljava/lang/Runnable;)Ljava/lang/Runnable;").first
),Runnable> wrapRunnable{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "shouldRun", "(Ljava/lang/Runnable;)Z").first
),Runnable> shouldRun{ *this};

JNI::Method<BlockRenderDispatcher, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getBlockRenderer", "()Lnet/minecraft/client/renderer/block/BlockRenderDispatcher;").first
)> getBlockRenderer{ *this};

JNI::Method<EntityRenderDispatcher, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getEntityRenderDispatcher", "()Lnet/minecraft/client/renderer/entity/EntityRenderDispatcher;").first
)> getEntityRenderDispatcher{ *this};

JNI::Method<BlockEntityRenderDispatcher, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getBlockEntityRenderDispatcher", "()Lnet/minecraft/client/renderer/blockentity/BlockEntityRenderDispatcher;").first
)> getBlockEntityRenderDispatcher{ *this};

JNI::Method<ItemRenderer, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getItemRenderer", "()Lnet/minecraft/client/renderer/entity/ItemRenderer;").first
)> getItemRenderer{ *this};

JNI::Method<SearchTree, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSearchTree", "(Lnet/minecraft/client/searchtree/SearchRegistry$Key;)Lnet/minecraft/client/searchtree/SearchTree;").first
),SearchRegistry$Key> getSearchTree{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "populateSearchTree", "(Lnet/minecraft/client/searchtree/SearchRegistry$Key;Ljava/util/List;)V").first
),SearchRegistry$Key,List> populateSearchTree{ *this};

JNI::Method<FrameTimer, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTimer", "()Lnet/minecraft/util/FrameTimer;").first
)> getFrameTimer{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isConnectedToRealms", "()Z").first
)> isConnectedToRealms{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setConnectedToRealms", "(Z)V").first
),jboolean> setConnectedToRealms{ *this};

JNI::Method<DataFixer, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFixerUpper", "()Lcom/mojang/datafixers/DataFixer;").first
)> getFixerUpper{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getFrameTime", "()F").first
)> getFrameTime{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getDeltaFrameTime", "()F").first
)> getDeltaFrameTime{ *this};

JNI::Method<BlockColors, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getBlockColors", "()Lnet/minecraft/client/color/block/BlockColors;").first
)> getBlockColors{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "showOnlyReducedInfo", "()Z").first
)> showOnlyReducedInfo{ *this};

JNI::Method<ToastComponent, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getToasts", "()Lnet/minecraft/client/gui/components/toasts/ToastComponent;").first
)> getToasts{ *this};

JNI::Method<Tutorial, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getTutorial", "()Lnet/minecraft/client/tutorial/Tutorial;").first
)> getTutorial{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isWindowActive", "()Z").first
)> isWindowActive{ *this};

JNI::Method<HotbarManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getHotbarManager", "()Lnet/minecraft/client/HotbarManager;").first
)> getHotbarManager{ *this};

JNI::Method<ModelManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getModelManager", "()Lnet/minecraft/client/resources/model/ModelManager;").first
)> getModelManager{ *this};

JNI::Method<PaintingTextureManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getPaintingTextures", "()Lnet/minecraft/client/resources/PaintingTextureManager;").first
)> getPaintingTextures{ *this};

JNI::Method<MobEffectTextureManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMobEffectTextures", "()Lnet/minecraft/client/resources/MobEffectTextureManager;").first
)> getMobEffectTextures{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("com/mojang/blaze3d/platform/WindowEventHandler", "setWindowActive", "(Z)V").first
),jboolean> setWindowActive{ *this};

JNI::Method<Component, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "grabPanoramixScreenshot", "(Ljava/io/File;II)Lnet/minecraft/network/chat/Component;").first
),File,jint,jint> grabPanoramixScreenshot{ *this};

JNI::Method<Component, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "grabHugeScreenshot", "(Ljava/io/File;IIII)Lnet/minecraft/network/chat/Component;").first
),File,jint,jint,jint,jint> grabHugeScreenshot{ *this};

JNI::Method<ProfilerFiller, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProfiler", "()Lnet/minecraft/util/profiling/ProfilerFiller;").first
)> getProfiler{ *this};

JNI::Method<StoringChunkProgressListener, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProgressListener", "()Lnet/minecraft/server/level/progress/StoringChunkProgressListener;").first
)> getProgressListener{ *this};

JNI::Method<SplashManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSplashManager", "()Lnet/minecraft/client/resources/SplashManager;").first
)> getSplashManager{ *this};

JNI::Method<Overlay, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getOverlay", "()Lnet/minecraft/client/gui/screens/Overlay;").first
)> getOverlay{ *this};

JNI::Method<PlayerSocialManager, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getPlayerSocialManager", "()Lnet/minecraft/client/gui/screens/social/PlayerSocialManager;").first
)> getPlayerSocialManager{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "renderOnThread", "()Z").first
)> renderOnThread{ *this};

JNI::Method<Window, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getWindow", "()Lcom/mojang/blaze3d/platform/Window;").first
)> getWindow{ *this};

JNI::Method<RenderBuffers, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "renderBuffers", "()Lnet/minecraft/client/renderer/RenderBuffers;").first
)> renderBuffers{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "updateMaxMipLevel", "(I)V").first
),jint> updateMaxMipLevel{ *this};

JNI::Method<ItemColors, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getItemColors", "()Lnet/minecraft/client/color/item/ItemColors;").first
)> getItemColors{ *this};

JNI::Method<SearchRegistry, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getSearchTreeManager", "()Lnet/minecraft/client/searchtree/SearchRegistry;").first
)> getSearchTreeManager{ *this};

JNI::Method<jfloat, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getPartialTick", "()F").first
)> getPartialTick{ *this};

JNI::Method<EntityModelSet, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getEntityModels", "()Lnet/minecraft/client/model/geom/EntityModelSet;").first
)> getEntityModels{ *this};

JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "isTextFilteringEnabled", "()Z").first
)> isTextFilteringEnabled{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "prepareForMultiplayer", "()V").first
)> prepareForMultiplayer{ *this};

JNI::Method<Realms32BitWarningStatus, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getRealms32BitWarningStatus", "()Lnet/minecraft/client/Realms32BitWarningStatus;").first
)> getRealms32BitWarningStatus{ *this};

JNI::Method<SignatureValidator, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getProfileKeySignatureValidator", "()Lnet/minecraft/util/SignatureValidator;").first
)> getProfileKeySignatureValidator{ *this};

JNI::Method<InputType, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getLastInputType", "()Lnet/minecraft/client/InputType;").first
)> getLastInputType{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "setLastInputType", "(Lnet/minecraft/client/InputType;)V").first
),InputType> setLastInputType{ *this};

JNI::Method<GameNarrator, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getNarrator", "()Lnet/minecraft/client/GameNarrator;").first
)> getNarrator{ *this};

JNI::Method<ChatListener, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getChatListener", "()Lnet/minecraft/client/multiplayer/chat/ChatListener;").first
)> getChatListener{ *this};

JNI::Method<ReportingContext, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getReportingContext", "()Lnet/minecraft/client/multiplayer/chat/report/ReportingContext;").first
)> getReportingContext{ *this};

JNI::Method<RealmsDataFetcher, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "realmsDataFetcher", "()Lcom/mojang/realmsclient/gui/RealmsDataFetcher;").first
)> realmsDataFetcher{ *this};

JNI::Method<QuickPlayLog, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "quickPlayLog", "()Lnet/minecraft/client/quickplay/QuickPlayLog;").first
)> quickPlayLog{ *this};

JNI::Method<Stream, JNI::STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "method_1525", "(Lnet/minecraft/world/item/ItemStack;)Ljava/util/stream/Stream;").first
),ItemStack> method_1525{ *this};

JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "method_51252", "(Lcom/mojang/realmsclient/client/RealmsClient;Lnet/minecraft/server/packs/resources/ReloadInstance;Lnet/minecraft/client/main/GameConfig;Z)V").first
),RealmsClient,ReloadInstance,GameConfig,jboolean> method_51252{ *this};

JNI::Method<jint, JNI::NOT_STATIC, DECLARE_NAME(
return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "method_16010", "()I").first
)> method_16010{ *this};

END_KLASS_DEF();

END_1_20_1
#include "Minecraft.h"

#include "wrapper/versions/1_18_1/net/minecraft/client/MInecraft.h"
#include <memory>

Wrapper::Minecraft Wrapper::Minecraft::getMinecraft()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		return Minecraft(V1_18_1::Minecraft::static_obj().getInstance());
	}
	assert("unimplemented version");
	return Minecraft();
}

Wrapper::Minecraft Wrapper::Minecraft::static_obj()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		return Minecraft(V1_18_1::Minecraft::static_obj());
	}
	assert("unimplemented version");
	return Minecraft();
}

bool Wrapper::Minecraft::isInGuiState()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Minecraft mc = this->instance->object_instance;
		return !JNI::get_env()->IsSameObject(mc.screen.get().object_instance, NULL);
	}

	assert("unimplemented version");
	return false;
}

Wrapper::World Wrapper::Minecraft::getWorld()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Minecraft mc = this->instance->object_instance;
		return World(mc.level.get());
	}
	return World();
}

Wrapper::EntityPlayerSP Wrapper::Minecraft::getPlayer()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Minecraft mc = this->instance->object_instance;
		return EntityPlayerSP(mc.player.get());
	}
	return EntityPlayerSP();
}

Wrapper::MovingObjectPosition Wrapper::Minecraft::getMouseOver()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Minecraft mc = this->instance->object_instance;
		return mc.hitResult.get();
	}
	assert("unimplemented version");
	return MovingObjectPosition();
}

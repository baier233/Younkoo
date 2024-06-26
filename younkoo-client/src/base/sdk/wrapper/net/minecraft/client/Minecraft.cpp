#include "Minecraft.h"

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

Wrapper::Minecraft Wrapper::Minecraft::get()
{
	return Minecraft(V1_18_1::Minecraft::static_obj());
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

Wrapper::MovingObjectPosition Wrapper::Minecraft::getMouseOver()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Minecraft mc;
		mc.object_instance = this->instance->object_instance;
		return mc.hitResult.get();
	}
	assert("unimplemented version");
	return MovingObjectPosition();
}

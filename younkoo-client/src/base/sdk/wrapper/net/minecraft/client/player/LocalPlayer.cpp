#include "LocalPlayer.h"

bool Wrapper::LocalPlayer::isHnadBusy() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LocalPlayer instance = this->instance->object_instance;
		return instance.isHandsBusy();
	}
	assert("unimplemented version");
	return false;
}
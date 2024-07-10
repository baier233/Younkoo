#include "GameSettings.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/Options.h>
float Wrapper::GameSettings::getFov()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.fov.get();
	}
	assert("unimplemented version");
	return 0.0f;
}

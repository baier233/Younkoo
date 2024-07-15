#include "EntityPlayerSP.h"
#include "wrapper/net/minecraft/util/MovementInput.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/player/LocalPlayer.h>

Wrapper::MovementInput Wrapper::EntityPlayerSP::getMovementInput()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::LocalPlayer player = this->getObject();
		return player.input.get();
	}
	assert("unimplemented version");
	return MovementInput();
}
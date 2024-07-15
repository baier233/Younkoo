#include "MovementInput.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/player/Input.h>

float Wrapper::MovementInput::getMoveForward()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Input input = this->getObject();
		return input.forwardImpulse.get();
	}
}
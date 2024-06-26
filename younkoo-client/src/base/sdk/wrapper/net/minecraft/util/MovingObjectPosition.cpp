#include "MovingObjectPosition.h"

bool Wrapper::MovingObjectPosition::isTypeOfBlock()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::HitResult mouseOver = this->instance->object_instance;
		return mouseOver.getType() == V1_18_1::HitResult$Type::static_obj().BLOCK.get();
	}
	return false;
}

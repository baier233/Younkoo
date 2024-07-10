#include "MovingObjectPosition.h"

std::string Wrapper::MovingObjectPosition::getType()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::HitResult mouseOver = this->getObject();
		auto type = mouseOver.getType();
		if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().BLOCK.get()))
		{
			return "BLOCK";
		}
		else if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().MISS.get())) {
			return "MISS";
		}
		else if (type.is_same_object(V1_18_1::HitResult$Type::static_obj().ENTITY.get())) {
			return "ENTITY";
		}
		return "NULL";
	}
	return "";
}

bool Wrapper::MovingObjectPosition::isTypeOfBlock()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_18_1::HitResult$Type::static_obj().BLOCK.get());
	}
	return false;
}

bool Wrapper::MovingObjectPosition::isTypeOfEntity()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::HitResult mouseOver = this->getObject();
		return mouseOver.getType().is_same_object(V1_18_1::HitResult$Type::static_obj().ENTITY.get());
	}
	return false;
}

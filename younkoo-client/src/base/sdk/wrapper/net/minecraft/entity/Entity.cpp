#include "Entity.h"

#include "wrapper/versions/1_18_1/net/minecraft/world/entity/Entity.h"
void Wrapper::Entity::setGlowing(bool value)
{

	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::Entity entity = this->instance->object_instance;
		entity.setGlowingTag(value);
		return;
	}
	return;
}

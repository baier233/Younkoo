#include "../../../../../../../features/values/Value.h"
#include "../ValueComponent.h"
#pragma once
class BooleanValueComponent : public ValueComponent<BoolValue>
{
	BooleanValueComponent(ModuleComponent* parent, BoolValue* value) : ValueComponent<BoolValue>(parent, value) {}

};


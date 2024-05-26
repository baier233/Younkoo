#pragma once

#include "../../Component.hpp"
#include "../ModuleComponent.h"
template<class value_type>
class ValueComponent : public Component
{
public:
	ValueComponent(ModuleComponent* parent, value_type* value) {
		this->parent = parent;
		this->value = value;
	}


	template<class type> static ValueComponent<type> create(ModuleComponent* parent, std::pair<ValueType, Value*> valuePair) {
		switch (valuePair.first) {
		case BoolType:
			break;
		case IntType:
			break;
		case FloatType:
			break;
		case ListType:
			break;
		case ColorType:
			break;
		default:
			break;
		}
	}
protected:
	const ModuleComponent* parent;
	value_type* value;
};


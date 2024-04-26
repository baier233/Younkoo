#include "Younkoo.hpp"
#include <iostream>

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

bool Younkoo::setup()
{
	std::cout << "Setting Up" << std::endl;
	return true;
}

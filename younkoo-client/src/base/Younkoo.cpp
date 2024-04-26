#include "Younkoo.hpp"
#include <iostream>

#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

bool Younkoo::setup()
{ 
	JVM::get().setup();
	std::cout << "Setting Up" << std::endl;
	return true;
}

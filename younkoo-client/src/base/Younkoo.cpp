#include "Younkoo.hpp"
#include <iostream>

#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

#include "sdk/mappings.hpp"

bool Younkoo::setup()
{ 
	JVM::get().setup();
	

	maps::Main Main{};
	maps::SubClass SubClass{};

	Main.print();
	Main.field_0.print();
	

	auto instanceSub = SubClass.getInstance();

	SubClass.print();
	SubClass.getInstance.print();
	std::cout << "SubClass.instance :\n{"  << "\n   Sign:" << SubClass.getInstance.get_signature() << "\n   Value :" << instanceSub.object_instance << "\n}" << std::endl;
	instanceSub.field_1.print();


	std::cout << "Setting Up" << std::endl;
	return true;
}

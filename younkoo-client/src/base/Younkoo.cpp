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
	std::cout << maps::Main::get_signature() << std::endl;
	std::cout << maps::Main::get_name() << std::endl;
	std::cout << Main.owner_klass << std::endl;
	std::cout << Main.field_0.get_name() << std::endl;
	std::cout << Main.field_0.get_signature() << std::endl;
	std::cout << Main.field_0.get() << std::endl;
	std::cout << SubClass.get_name() << std::endl;
	std::cout << SubClass.owner_klass << std::endl;
	std::cout << SubClass.get_class_name() << std::endl;
	std::cout << SubClass.get_signature() << std::endl;
	std::cout << SubClass.getInstance.get_signature() << std::endl;
	std::cout << SubClass.getInstance.get_name() << std::endl;
	auto instanceSub = SubClass.getInstance();
	std::cout << instanceSub.object_instance << std::endl;
	std::cout << instanceSub.field_1.get() << std::endl;
	

	std::cout << "Setting Up" << std::endl;
	return true;
}

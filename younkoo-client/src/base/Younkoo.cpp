#include "Younkoo.hpp"
#include <iostream>

#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

#include "sdk/mappings.hpp"

#include "render/Renderer.hpp"
#include "render/nano/NanovgHelper.hpp"
#ifdef TEST

void Test() {

	maps::Main Main{};
	maps::SubClass SubClass{};
	maps::Collection Collection{};

	Main.print();
	Main.field_0.print();
	Collection.toArray.print();


	//setting static field
	Main.field_0 = 1337;

	//calling method
	auto instanceSub = SubClass.getInstance();

	SubClass.print();
	SubClass.getInstance.print();
	std::cout << "SubClass.instance :\n{" << "\n   Sign:" << SubClass.getInstance.get_signature() << "\n   Value :" << instanceSub.object_instance << "\n}" << std::endl;
	instanceSub.field_1.print();

	//setting non-static field
	instanceSub.field_1 = -1337;

	//Array test
	Collection.print();
	std::cout << Collection.toArray.get_name() + Collection.toArray.get_signature() << std::endl;
}

#endif // Test

bool Younkoo::setup()
{
	auto flag = JVM::get().setup();
	flag &= Renderer::get().Init();


	std::cout << "Setting Up" << std::endl;
	return flag;
}

bool Younkoo::shutdown()
{
	auto flag = Renderer::get().Shutdown();
	return flag;
}

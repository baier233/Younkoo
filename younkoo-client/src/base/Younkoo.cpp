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

#include "render/gui/input/Context.hpp"
#include "sdk/Mapper/SRGParser.h"
bool Younkoo::setup()
{
	auto flag = JVM::get().setup();
	flag &= Renderer::get().Init();

	SRGParser::get().SetVersion(Versions::VANILLA_1_8_9);
	std::cout << SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft") << std::endl;
	std::cout << SRGParser::get().getObfuscatedFieldName("net/minecraft/client/Minecraft", "theMinecraft") << std::endl;
	auto method = SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getMinecraft", "()Lnet/minecraft/client/Minecraft;");
	std::cout << method.first << " " << method.second << std::endl;

	if (!flag) return flag;

	std::cout << "Setting Up" << std::endl;
	while (!shouldShutDown)
	{
		shouldShutDown = context.KeysDown[VK_END];
		Sleep(1);
	}

	return Younkoo::shutdown();
}
#include "../Main.hpp"
bool Younkoo::shutdown()
{
	shouldShutDown = true;
	auto flag = Renderer::get().Shutdown() && JVM::get().shutdown();
	if (!flag) return false;
	FreeLibraryAndExitThread(Main::current_module, 0);
	return true;
}

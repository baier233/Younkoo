#include "Younkoo.hpp"
#include <iostream>
#include "features/modules/ModuleManager.h"
#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

#include <SDK.hpp>

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
#include <wrapper/net/minecraft/client/Minecraft.h>
bool Younkoo::setup()
{
	auto flag = JVM::get().setup();
	flag &= Renderer::get().Init();
	flag &= ModuleManager::get().LoadModules();

	SRGParser::get().SetVersion(Versions::FORGE_1_18_1);
	std::cout << SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft") << std::endl;
	std::cout << SRGParser::get().getObfuscatedFieldName("net/minecraft/client/Minecraft", "instance") << std::endl;
	auto method = SRGParser::get().getObfuscatedMethodName("net/minecraft/client/Minecraft", "getInstance", "()Lnet/minecraft/client/Minecraft;");
	std::cout << method.first << " " << method.second << std::endl;
	auto result = SDK::SetUpForge1181ClassLoader("Render thread");
	if (!result) result = SDK::SetUpClassLoader(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"));
	flag &= result;

	if (!flag) return flag;


	if (SDK::MinecraftClassLoader)
	{
		JNI::set_class_loader(SDK::MinecraftClassLoader);
	}

	std::cout << "Setting Up" << std::endl;
	static Minecraft minecraft{};
	while (!shouldShutDown)
	{
		while (!YounkooIO::IOEvents.empty())
		{
			
			auto &event = YounkooIO::IOEvents.front();
			if (event->type == YounkooIO::EventType::KEY) {
				YounkooIO::KeyEvent key = static_cast<YounkooIO::KeyEvent&>(*event.get()).keycode;
				std::cout << "keycode: " << key.keycode << " action: " << key.action << std::endl;
				ModuleManager::get().ProcessKeyEvent(key.keycode);
			}
			YounkooIO::IOEvents.pop();
		}
		ModuleManager::get().ProcessUpdate();
		shouldShutDown = context.KeysDown[VK_END];


		auto theMinecraft = minecraft.getMinecraft();
		auto thePlayer = theMinecraft.thePlayer.get();
		auto mouseOver = theMinecraft.mouseOver.get();
		//std::cout << mouseOver.object_instance << std::endl;
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

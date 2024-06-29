#include "Younkoo.hpp"
#include <iostream>
#include "features/modules/ModuleManager.h"
#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
	std::cout << "Constructor" << std::endl;
}

#include <SDK.hpp>


#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/Minecraft.h>

#include "render/Renderer.hpp"
#include "render/nano/NanovgHelper.hpp"
#include "render/gui/input/Context.hpp"

#include "sdk/Mapper/SRGParser.h"
bool Younkoo::setup()
{
	auto flag = JVM::get().setup();
		
	flag &= ModuleManager::get().LoadModules();
	flag &= Renderer::get().Init();

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




	while (!shouldShutDown)
	{
		while (!YounkooIO::IOEvents.empty())
		{
			auto& event = YounkooIO::IOEvents.front();
			switch (event->type) {
			case YounkooIO::EventType::KEY: {
				auto keyEvent = std::dynamic_pointer_cast<YounkooIO::KeyEvent>(event);
				if (keyEvent && keyEvent->action == 0) {
					ModuleManager::get().ProcessKeyEvent(keyEvent->keycode);
				}
				break;
			}
			case YounkooIO::EventType::MOUSE: {
				auto mouseEvent = std::dynamic_pointer_cast<YounkooIO::MouseEvent>(event);
				// Handle mouseEvent here
				break;
			}
			case YounkooIO::EventType::MOUSEPOS: {
				auto mousePosEvent = std::dynamic_pointer_cast<YounkooIO::MousePosEvent>(event);
				// Handle mousePosEvent here
				break;
			}
			case YounkooIO::EventType::WHEEL: {
				auto wheelEvent = std::dynamic_pointer_cast<YounkooIO::WheelEvent>(event);

				// Handle wheelEvent here
				break;
			}
			case YounkooIO::EventType::TYPE: {
				auto charEvent = std::dynamic_pointer_cast<YounkooIO::CharEvent>(event);
				// Handle charEvent here
				break;
			}
			default:
				break;
			}
			YounkooIO::IOEvents.pop();
		}

		ModuleManager::get().ProcessUpdate();
		shouldShutDown = context.KeysDown[VK_END];
		//std::cout << mouseOver.object_instance << std::endl;
		Sleep(1);
	}

	return Younkoo::shutdown();
}



#include "../Main.hpp"

#include "cleaner/UnloadedModuleCleaner.h"
bool Younkoo::shutdown()
{
	shouldShutDown = true;
	UnloadedModuleCleaner::Clean();

	auto flag = Renderer::get().Shutdown() && JVM::get().shutdown();
	if (!flag) return false;
	FreeLibraryAndExitThread(Main::current_module, 0);
	return true;
}

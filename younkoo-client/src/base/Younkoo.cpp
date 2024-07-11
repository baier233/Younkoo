#include "Younkoo.hpp"
#include <iostream>
#include "features/modules/ModuleManager.h"
#include "jvm/JVM.hpp"

#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

#include <Psapi.h>

#include <StackWalk/StackWalker.h>
static bool __forceinline printStackTrace()
{
	auto result = false;
	HANDLE process = GetCurrentProcess();
	HANDLE thread = GetCurrentThread();
	CONTEXT context;
	STACKFRAME64 stackFrame;
	DWORD imageType;

	// Initialize context and stack frame
	RtlCaptureContext(&context);
	ZeroMemory(&stackFrame, sizeof(STACKFRAME64));

#ifdef _M_IX86
	imageType = IMAGE_FILE_MACHINE_I386;
	stackFrame.AddrPC.Offset = context.Eip;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.Ebp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.Esp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_X64
	imageType = IMAGE_FILE_MACHINE_AMD64;
	stackFrame.AddrPC.Offset = context.Rip;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.Rsp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.Rsp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_IA64
	imageType = IMAGE_FILE_MACHINE_IA64;
	stackFrame.AddrPC.Offset = context.StIIP;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.IntSp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrBStore.Offset = context.RsBSP;
	stackFrame.AddrBStore.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.IntSp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#else
#error "Unsupported platform"
#endif

	// Initialize the symbol handler
	SymInitialize(process, NULL, TRUE);

	// Loop to walk the stack
	while (StackWalk64(imageType, process, thread, &stackFrame, &context, NULL,
		SymFunctionTableAccess64, SymGetModuleBase64, NULL))
	{
		DWORD64 address = stackFrame.AddrPC.Offset;
		if (address == 0)
		{
			break;
		}
		//GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,)
		// Print address
		HMODULE hModule = 0;
		if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)address, &hModule)) {

			auto offset = (uintptr_t)address - (uintptr_t)hModule;
			char moduleName[MAX_PATH];
			K32GetModuleBaseNameA(GetCurrentProcess(), hModule, moduleName, sizeof(moduleName) / sizeof(char));
			auto module_name = std::string(moduleName);
			std::cout << "Address: " << module_name << " + 0x" << std::hex << offset << std::dec << std::endl;


			if (!result)result = module_name.find("api-ms-w") != std::string::npos;

		}
		else {

			std::cout << "Address: " << (void*)address << std::endl;
		}

		// Get symbol information
		DWORD64 displacementSym = 0;
		char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
		PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol->MaxNameLen = MAX_SYM_NAME;

		if (SymFromAddr(process, address, &displacementSym, symbol))
		{
			std::cout << "Function: " << symbol->Name << std::endl;
		}

		// Get line information
		DWORD displacementLine = 0;
		IMAGEHLP_LINE64 line;
		line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

		if (SymGetLineFromAddr64(process, address, &displacementLine, &line))
		{
			std::cout << "File: " << line.FileName << " Line: " << line.LineNumber << std::endl;
		}
	}

	// Cleanup
	SymCleanup(process);
	return result;
}

class MyStackWalker : public StackWalker
{
public:
	MyStackWalker() : StackWalker() {}
protected:
	virtual void OnOutput(LPCSTR szText) {
		printf(szText); StackWalker::OnOutput(szText);
	}
	virtual void OnLoadModule(LPCSTR    img,
		LPCSTR    mod,
		DWORD64   baseAddr,
		DWORD     size,
		DWORD     result,
		LPCSTR    symType,
		LPCSTR    pdbName,
		ULONGLONG fileVersion) {
		return;
	}

};

static __forceinline void stack_walk() {
	MyStackWalker sw;

	sw.ShowCallstack(GetCurrentThread(), sw.GetCurrentExceptionContext());
}
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

#include "features/modules/common/CommonData.h"

#include "sdk/Mapper/SRGParser.h"
#include <hook/hooks/RenderSystemHook.h>
TitanHook<decltype(&ExitProcess)> ExitProcessHook;
static void My_ExitProcess(UINT code) {
	stack_walk();
	if (printStackTrace()) {
		MessageBox(0, L"On ExitProcess 1", 0, 0);
		while (!Younkoo::get().shouldShutDown.load())
		{
			Sleep(1);
		}
		return;
	}
	MessageBox(0, L"On ExitProcess 2", 0, 0);
	ExitProcessHook.GetOrignalFunc()(code);
}
bool Younkoo::setup()
{

	auto flag = JVM::get().setup();

	flag &= ModuleManager::get().LoadModules();
	flag &= Renderer::get().Init();

	{
		auto pExitProcess = LI_FN(ExitProcess).get();
		ExitProcessHook.InitHook(pExitProcess, My_ExitProcess);
		ExitProcessHook.SetHook();
	}



	SRGParser::get().SetVersion(Versions::FORGE_1_18_1);
	std::cout << SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft") << std::endl;
	std::cout << SRGParser::get().getObfuscatedFieldName("net/minecraft/client/Minecraft", "instance") << std::endl;
	auto method = SRGParser::get().getObfuscatedMethodName("net/minecraft/world/level/Level", "getBlockState", "(Lnet/minecraft/core/BlockPos;)Lnet/minecraft/world/level/block/state/BlockState;");
	std::cout << method.first << " " << method.second << std::endl;
	auto result = SDK::SetUpForge1181ClassLoader("Render thread");
	if (!result) result = SDK::SetUpClassLoader(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"));

	flag &= result;

	if (!flag) return flag;


	if (SDK::MinecraftClassLoader)
	{
		JNI::set_class_loader(SDK::MinecraftClassLoader);
	}

	{
		RenderSystemHook::applyHook();
	}

	std::cout << "Setting Up" << std::endl;

	(void)CommonData::get();

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

		(void)JNI::get_env()->PushLocalFrame(99);
		CommonData::get().onUpdate();
		ModuleManager::get().ProcessUpdate();
		(void)JNI::get_env()->PopLocalFrame(nullptr);
		shouldShutDown = context.KeysDown[VK_END];
		//std::cout << JNI::_refs_to_delete.size() << std::endl;
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
	RenderSystemHook::cleanHook();
	ExitProcessHook.RemoveHook();

	auto flag = Renderer::get().Shutdown() && JVM::get().shutdown();
	if (!flag) return false;
	FreeLibraryAndExitThread(Main::current_module, 0);
	return true;
}
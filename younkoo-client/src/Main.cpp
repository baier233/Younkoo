#include <Windows.h>

#include "Main.hpp"

#include <jni/jvmti.h>



BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, PVOID lpReserved)
{
	(void)lpReserved;
#ifndef DEBUG

	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		return Main::ProcessAttach(hModule);
	case DLL_PROCESS_DETACH:
		return Main::ProcessDetach(hModule);
	case DLL_THREAD_ATTACH:
		return Thread::ThreadAttach(hModule);
	case DLL_THREAD_DETACH:
		return Thread::ThreadDetach(hModule);
	}
#endif // !DEBUG


	return TRUE;
}
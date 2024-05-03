#include <Windows.h>

#include "Main.hpp"
#include <cstdio>
void Utils::CreateConsole_(void)
{
	FreeConsole();
	if (!AllocConsole())
	{
		char buffer[1024] = { 0 };
		sprintf_s(buffer, "Failed to AllocConsole( ), GetLastError( ) = %d", GetLastError());
		MessageBoxA(HWND_DESKTOP, buffer, "Error", MB_OK);

		return;
	}

	FILE* fp = nullptr;
	freopen_s(&fp, "CONOUT$", "w", stdout);

	*(__acrt_iob_func(1)) = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}

void Utils::CloseConsole_(void)
{
	FILE* fp = (__acrt_iob_func(1));
	if (fp != nullptr) {
		fclose(fp);
	}

	if (!FreeConsole())
	{
		char buffer[1024] = { 0 };
		sprintf_s(buffer, "Failed to FreeConsole(), GetLastError() = %d", GetLastError());
		MessageBoxA(HWND_DESKTOP, buffer, "Error", MB_OK);
		return;
	}
}

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, PVOID lpReserved)
{
	(void)lpReserved;


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
	return TRUE;
}
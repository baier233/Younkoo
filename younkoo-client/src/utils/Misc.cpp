#include "Misc.hpp"


#include <Windows.h>
#include <iostream>
void Utils::CreateConsole(void)
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

void Utils::CloseConsole(void)
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

#include "Misc.h"


#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
void Utils::CreateConsole()
{
	FreeConsole();
	if (!AllocConsole())
	{
		char buffer[1024] = { 0 };
		sprintf_s(buffer, "Failed to AllocConsole( ), GetLastError( ) = %d", GetLastError());
		MessageBoxA(HWND_DESKTOP, buffer, "Error", MB_OK);

		return;
	}

	auto lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	auto hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	auto fp = _fdopen(hConHandle, "w");
	freopen_s(&fp, "CONOUT$", "w", stdout);

	*(__acrt_iob_func(1)) = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}

void Utils::CloseConsole()
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

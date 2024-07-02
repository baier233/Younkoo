#pragma once
#include <Windows.h>

#include <cstdio>

namespace Utils {
	//创建调试窗口
	inline void CreateConsole_(void)
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

	inline void CloseConsole_(void)
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


};

namespace Main {
	inline HMODULE current_module{};
	BOOL ProcessAttach(HMODULE hDll);
	BOOL ProcessDetach(HMODULE hDll);
}
namespace Thread {

	inline LONG s_nTlsIndent = -1;
	inline LONG s_nTlsThread = -1;
	inline LONG s_nThreadCnt = 0;


	BOOL ThreadAttach(HMODULE hDll);
	BOOL ThreadDetach(HMODULE hDll);
}

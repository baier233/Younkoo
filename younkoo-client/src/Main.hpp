#pragma once
#include <Windows.h>
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

#pragma once
#include <Windows.h>

namespace Utils {
	//创建调试窗口
	void CreateConsole_();
	//销毁调试窗口
	void CloseConsole_();
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

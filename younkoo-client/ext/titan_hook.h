#pragma once
#include <Windows.h>
#include "detours/include/detours.h"
#include "lazy_importer.hpp"
#pragma comment(lib, "detours.lib")
template <typename T>
class TitanHook {
public:
	void InitHook(void* targetFunc, void* myFunc) {
		targetFunc_ = targetFunc;
		myFunc_ = myFunc;
	}

	void SetHook() {
		if (targetFunc_ && myFunc_)
		{
			DetourTransactionBegin();
			DetourUpdateThread(LI_FN(GetCurrentThread)());
			DetourAttach(&(LPVOID&)targetFunc_, myFunc_);
			DetourTransactionCommit();

		}
	}

	T GetOrignalFunc() {
		return (T)targetFunc_;
	}

	void* GetTargetFunc() {
		return targetFunc_;
	}

	void* GetMyFunc() {
		return myFunc_;
	}

	void RemoveHook() {
		if (targetFunc_)
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourDetach(&(LPVOID&)targetFunc_, myFunc_);
			DetourTransactionCommit();
		}
	}

	~TitanHook() {
		RemoveHook();
	}
private:
	void* targetFunc_ = 0;
	void* myFunc_ = 0;
};
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
		DetourTransactionBegin();
		DetourUpdateThread(LI_FN(GetCurrentThread)());
		DetourAttach(&(LPVOID&)targetFunc_, myFunc_);
		DetourTransactionCommit();
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
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(LPVOID&)targetFunc_, myFunc_);
		DetourTransactionCommit();
	}

	~TitanHook() {
		RemoveHook();
	}
private:
	void* targetFunc_;
	void* myFunc_;
};
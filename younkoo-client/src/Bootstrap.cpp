#include "main.hpp"

#include <memory>
#include <stdexcept>
#include <functional>
#include <iostream>
#include <thread>

#include "base/Younkoo.hpp"
#include "utils/Misc.h"


static DWORD WINAPI BootStrapThread(LPVOID hDll)
{ 

    auto result = Younkoo::get().setup();
    if (!result) {
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hDll), 0);
    }
    
    return NULL;
}

BOOL Main::ProcessAttach(HMODULE hDll)
{
    Thread::s_nTlsIndent = TlsAlloc();
    Thread::s_nTlsThread = TlsAlloc();

    Utils::CreateConsole();

    current_module = hDll;

    auto handle = CreateThread(0, 0, BootStrapThread, hDll , 0, 0);

    if(handle) CloseHandle(handle);
    Thread::ThreadAttach(hDll);
    return TRUE;

EXIT:
    Thread::ThreadAttach(hDll);
    FreeLibraryAndExitThread(hDll, 0);
    return TRUE;
}

BOOL Main::ProcessDetach(HMODULE hDll)
{

    Thread::ThreadDetach(hDll);

    if (Thread::s_nTlsIndent >= 0) {
        TlsFree(Thread::s_nTlsIndent);
    }
    if (Thread::s_nTlsThread >= 0) {
        TlsFree(Thread::s_nTlsThread);
    }

    Utils::CloseConsole();
    return TRUE;
}


BOOL Thread::ThreadAttach(HMODULE hDll)
{
    (void)hDll;

    if (s_nTlsIndent >= 0) {
        TlsSetValue(s_nTlsIndent, (PVOID)0);
    }
    if (s_nTlsThread >= 0) {
        LONG nThread = InterlockedIncrement(&s_nThreadCnt);
        TlsSetValue(s_nTlsThread, (PVOID)(LONG_PTR)nThread);
    }
    return TRUE;
}

BOOL Thread::ThreadDetach(HMODULE hDll)
{
    (void)hDll;

    if (s_nTlsIndent >= 0) {
        TlsSetValue(s_nTlsIndent, (PVOID)0);
    }
    if (s_nTlsThread >= 0) {
        TlsSetValue(s_nTlsThread, (PVOID)0);
    }
    return TRUE;
}


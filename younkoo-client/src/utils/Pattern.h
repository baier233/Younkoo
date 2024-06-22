#pragma once

#include <Windows.h>
#include <iomanip>
#include <Psapi.h>

#define XASSERT(x) if (x) MessageBoxA(HWND_DESKTOP, _(#x), _("FATAL ERROR"), MB_ICONERROR)

struct ScopedVirtualProtect {
	ScopedVirtualProtect(void* Addr, size_t Size, DWORD NewProtect) : Addr(Addr), Size(Size) { VirtualProtect(Addr, Size, NewProtect, &OldProtect); }
	~ScopedVirtualProtect() { VirtualProtect(Addr, Size, OldProtect, &OldProtect); }

	void* Addr;
	size_t Size;
	DWORD OldProtect;
};

class CUtil_Pattern
{
public:
	static uintptr_t Find(const char* module, const char* pattern);
	static uintptr_t Find(uintptr_t module, const char* pattern);

public:
	static uintptr_t GetAbsoluteAddress(uintptr_t address, int offset, int size);
};


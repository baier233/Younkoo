#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include "../../utils/Pattern.h"
namespace UnloadedModuleCleaner
{
	inline void PrintUnloadedModule() {

		{
			typedef VOID(WINAPI* _tRtlGetUnloadEventTraceEx)(
				_Out_ PULONG* ElementSize,
				_Out_ PULONG* ElementCount,
				_Out_ PVOID* EventTrace);

			typedef struct _RTL_UNLOAD_EVENT_TRACE
			{
				PVOID BaseAddress; // Base address of dll
				SIZE_T SizeOfImage; // Size of image
				ULONG Sequence; // Sequence number for this event
				ULONG TimeDateStamp; // Time and date of image
				ULONG CheckSum; // Image checksum
				WCHAR ImageName[32]; // Image name
			} RTL_UNLOAD_EVENT_TRACE, * PRTL_UNLOAD_EVENT_TRACE;

			// collect memory addresses of unloaded modules in *client*
			auto _RtlGetUnloadEventTraceEx = (_tRtlGetUnloadEventTraceEx)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "RtlGetUnloadEventTraceEx");
			if (_RtlGetUnloadEventTraceEx)
			{
				PULONG  RtlpUnloadEventTraceExSizePtr;
				PULONG  RtlpUnloadEventTraceExNumberPtr;
				PVOID RtlpUnloadEventTraceExPtr;

				_RtlGetUnloadEventTraceEx(&RtlpUnloadEventTraceExSizePtr, &RtlpUnloadEventTraceExNumberPtr, &RtlpUnloadEventTraceExPtr);
				/*std::cout << "RtlpUnloadEventTraceExSizePtr :" << RtlpUnloadEventTraceExSizePtr << "\nRtlpUnloadEventTraceExNumberPtr :" << RtlpUnloadEventTraceExNumberPtr << "\nRtlpUnloadEventTraceExPtr :" << RtlpUnloadEventTraceExPtr << std::endl;*/

				PCHAR RtlpUnloadEventTraceEx = *(PCHAR*)RtlpUnloadEventTraceExPtr;
				ULONG RtlpUnloadEventTraceExSize = *RtlpUnloadEventTraceExSizePtr;
				ULONG RtlpUnloadEventTraceExNumber = *RtlpUnloadEventTraceExNumberPtr;

				for (ULONG idx = 0; idx < RtlpUnloadEventTraceExNumber; idx++)
				{

					RTL_UNLOAD_EVENT_TRACE* traceEntry = reinterpret_cast<RTL_UNLOAD_EVENT_TRACE*>(RtlpUnloadEventTraceEx + (idx * RtlpUnloadEventTraceExSize));
					if (!traceEntry || traceEntry->BaseAddress == 0)
					{
						continue;
					}
					std::cout << "traceEntry[" << idx << "]" << traceEntry << std::endl;
					wchar_t filename[MAX_PATH] = { 0 };
					wcscpy(filename, traceEntry->ImageName);
					std::wstring module_name(filename);
					std::wcout << "module_name :" << module_name << "\t";
					std::wcout << "BaseAddress :" << traceEntry->BaseAddress << "\t";
					std::wcout << "TimeDateStamp :" << traceEntry->TimeDateStamp << std::endl;
				}
			}
		}
	}
	inline void Clean() {
		/*Write a 'retn' instruction into the begin of LdrpRecordUnloadEvent function,for disabling the unloaded module log*/
		auto ntdll = GetModuleHandleW(L"ntdll.dll");
		// this pattern is only for win11
		auto pLdrpRecordUnloadEvent = CUtil_Pattern::Find((uintptr_t)ntdll, "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 30 8B 05 ? ? ? ?");
		if (!pLdrpRecordUnloadEvent) return;
		{

			ScopedVirtualProtect vp((PVOID)pLdrpRecordUnloadEvent, 0x1, PAGE_EXECUTE_READWRITE);
			*(BYTE*)pLdrpRecordUnloadEvent = 0xC3;//insn : RETN
		}
	}
}


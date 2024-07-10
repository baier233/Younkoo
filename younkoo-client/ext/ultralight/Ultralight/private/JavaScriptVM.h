/******************************************************************************
 *  This file is a part of Ultralight, an ultra-portable web-browser engine.  *
 *                                                                            *
 *  See <https://ultralig.ht> for licensing and more.                         *
 *                                                                            *
 *  (C) 2023 Ultralight, Inc.                                                 *
 *****************************************************************************/
#pragma once
#include <Ultralight/Defines.h>

namespace ultralight {
namespace JavaScriptVM {

size_t UExport Size(void* vm);
size_t UExport ExtraMemorySize(void* vm);
size_t UExport Capacity(void* vm);
size_t UExport ObjectCount(void* vm);
size_t UExport GlobalObjectCount(void* vm);
size_t UExport ProtectedObjectCount(void* vm);
size_t UExport ProtectGlobalObjectCount(void* vm);

void UExport ShrinkFootprintWhenIdle(void* vm);

namespace GC {
void UExport Sweep(void* vm);
void UExport Collect(void* vm, bool async = false);

} // namespace GC

} // namespace JavaScriptVM
} // namespace ultralight

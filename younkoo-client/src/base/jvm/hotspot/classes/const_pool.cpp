//
// Created by Administrator on 2024/3/15.
//

#include "const_pool.h"


auto java_hotspot::const_pool::get_base() -> void ** {
    static VMTypeEntry *ConstantPool_entry = JVMWrappers::find_type("ConstantPool").value();
    if (!ConstantPool_entry) return nullptr;
    return reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(this) + ConstantPool_entry->size);
}

auto java_hotspot::const_pool::get_tags() -> array<unsigned char> * {
    auto contatnPool = JVMWrapper::from_instance("ConstantPool", this).value();
    const auto tag = *contatnPool.get_field<void *>("_tags").value();
    return static_cast<array<unsigned char> *>(tag);
}

auto java_hotspot::const_pool::get_length() -> int {
    static VMStructEntry *length_entry = JVMWrappers::find_type_fields("ConstantPool").value().get()["_length"];
    if (!length_entry) return 0;
    return *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(this) + length_entry->offset);
}

auto java_hotspot::const_pool::get_symbol_at(const int index) -> symbol * {
    return *get_symbol_at_address(index);
}

auto java_hotspot::const_pool::get_symbol_at_address(const int index) -> symbol ** {
    return reinterpret_cast<symbol **>(&get_base()[index]);
}

auto java_hotspot::const_pool::get_pool_holder() -> void* {
    static VMStructEntry* pool_holder_entry = JVMWrappers::find_type_fields("ConstantPool").value().get()[
        "_pool_holder"];
    if (!pool_holder_entry) return nullptr;
    return *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(this) + pool_holder_entry->offset);
}

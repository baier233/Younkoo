//
// Created by Administrator on 2024/3/16.
//

#include "jvm_static.h"

#include "jvm_internal.h"

auto vm_symbols::get_symbol() -> java_hotspot::symbol ** {
    static auto reference_wrapper = JVMWrappers::find_type_fields("vmSymbols");
    if (!reference_wrapper.has_value()) {
        std::cout << "Failed to find vmSymbols" << std::endl;
    }
    return *static_cast<java_hotspot::symbol ***>(reference_wrapper.value().get()["_symbols"]->
        address);
}

auto vm_symbols::symbol_at(const int index) -> java_hotspot::symbol * {
    return get_symbol()[index];
}

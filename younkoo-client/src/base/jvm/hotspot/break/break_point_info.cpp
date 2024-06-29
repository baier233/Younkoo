//
// Created by Administrator on 2024/3/17.
//

#include "break_point_info.h"

#include "../classes/method.h"


auto jvm_internal::breakpoint_info::create(java_hotspot::method* method, int bci) -> breakpoint_info* {
    static VMTypeEntry* _constMethod_entry = JVMWrappers::find_type("BreakpointInfo").value();
    if (!_constMethod_entry)return nullptr;
    auto new_mem = malloc(_constMethod_entry->size);
    const auto info = new(new_mem) breakpoint_info();
    const auto constMethod = method->get_const_method();
    info->set_bci(bci);
    info->set_name_index(constMethod->get_name_index());
    info->set_signature_index(constMethod->get_signature_index());
    info->set_orig_bytecode(java_runtime::bytecodes::_nop);
    info->set_next(nullptr);
    return info;
}

auto jvm_internal::breakpoint_info::orig_bytecode() -> java_runtime::bytecodes {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_orig_bytecode"];
    if (!_constMethod_entry)return java_runtime::bytecodes::_nop;
    return *reinterpret_cast<java_runtime::bytecodes*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset);
}

auto jvm_internal::breakpoint_info::bci() -> int {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()["_bci"];
    if (!_constMethod_entry)return 0;
    return *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset);
}

auto jvm_internal::breakpoint_info::name_index() -> uint16_t {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_name_index"];
    if (!_constMethod_entry)return 0;
    return *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset);
}

auto jvm_internal::breakpoint_info::signature_index() -> uint16_t {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_signature_index"];
    if (!_constMethod_entry)return 0;
    return *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset);
}

auto jvm_internal::breakpoint_info::next() -> breakpoint_info* {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()["_next"];
    if (!_constMethod_entry)return nullptr;
    return *reinterpret_cast<breakpoint_info**>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset);
}

auto jvm_internal::breakpoint_info::set_orig_bytecode(const java_runtime::bytecodes value) -> void {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_orig_bytecode"];
    if (!_constMethod_entry)return;
    *reinterpret_cast<java_runtime::bytecodes*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset) =
        value;
}

auto jvm_internal::breakpoint_info::set_bci(const int value) -> void {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()["_bci"];
    if (!_constMethod_entry)return;
    *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset) = value;
}

auto jvm_internal::breakpoint_info::set_name_index(const uint16_t value) -> void {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_name_index"];
    if (!_constMethod_entry)return;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset) = value;
}

auto jvm_internal::breakpoint_info::set_signature_index(const uint16_t value) -> void {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()[
        "_signature_index"];
    if (!_constMethod_entry)return;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset) = value;
}

auto jvm_internal::breakpoint_info::set_next(breakpoint_info* value) -> void {
    static VMStructEntry* _constMethod_entry = JVMWrappers::find_type_fields("BreakpointInfo").value().get()["_next"];
    if (!_constMethod_entry)return;
    *reinterpret_cast<breakpoint_info**>(reinterpret_cast<uint8_t*>(this) + _constMethod_entry->offset) = value;
}


break_point_info::break_point_info(
    java_hotspot::method *method,
    const uintptr_t bytecode_address,
    java_hotspot::java_thread *java_thread,
    const uintptr_t parameters
) {
    this->bytecode_address = bytecode_address;
    this->bytecode = new java_runtime::bytecode(method->get_const_method()->get_bytecode_start(),
                                                reinterpret_cast<uint8_t *>(bytecode_address));
    this->java_thread = java_thread;
    this->parameters = parameters;
    this->method = method;
}

break_point_info::~break_point_info() {
    delete this->bytecode;
}

auto break_point_info::get_bytecode_address() const -> uintptr_t {
    return bytecode_address;
}

auto break_point_info::get_bytecode() const -> java_runtime::bytecode * {
    return bytecode;
}

//
// Created by Administrator on 2024/3/15.
//

#include "instance_klass.h"
#include "../utility/jvm_internal.h"

auto java_hotspot::instance_klass::get_name() -> symbol* {
	static VMStructEntry* _name_entry = JVMWrappers::find_type_fields("Klass").value().get()["_name"];
	if (!_name_entry)
		return nullptr;
	return *reinterpret_cast<symbol**>(reinterpret_cast<uint8_t*>(this) + _name_entry->offset);
}

auto java_hotspot::instance_klass::get_constants() -> const_pool* {
	static VMStructEntry* _constants_entry = JVMWrappers::find_type_fields("InstanceKlass").value().get()["_constants"];
	if (!_constants_entry) return nullptr;
	return *reinterpret_cast<const_pool**>(reinterpret_cast<uint8_t*>(this) + _constants_entry->offset);
}

auto java_hotspot::instance_klass::get_methods()->array<method*>* {
	static VMStructEntry* _methods_entry = JVMWrappers::find_type_fields("InstanceKlass").value().get()["_methods"];
	if (!_methods_entry) return nullptr;
	return *reinterpret_cast<array<method*> **>(reinterpret_cast<uint8_t*>(this) + _methods_entry->offset);
}

auto java_hotspot::instance_klass::get_fields()->array<uint16_t>* {
	static VMStructEntry* _fields_entry = JVMWrappers::find_type_fields("InstanceKlass").value().get()["_fields"];
	if (!_fields_entry) return nullptr;
	return *reinterpret_cast<array<uint16_t> **>(reinterpret_cast<uint8_t*>(this) + _fields_entry->offset);
}

auto java_hotspot::instance_klass::set_breakpoints(jvm_internal::breakpoint_info* breakpoints) -> void {
	static VMStructEntry* _breakpoints_entry = JVMWrappers::find_type_fields("InstanceKlass").value().get()[
		"_breakpoints"];
	if (!_breakpoints_entry) return;
	*reinterpret_cast<jvm_internal::breakpoint_info**>(reinterpret_cast<uint8_t*>(this) + _breakpoints_entry->offset)
		= breakpoints;
}

auto java_hotspot::instance_klass::get_breakpoints() -> jvm_internal::breakpoint_info* {
	static VMStructEntry* _breakpoints_entry = JVMWrappers::find_type_fields("InstanceKlass").value().get()[
		"_breakpoints"];
	if (!_breakpoints_entry) return nullptr;
	return *reinterpret_cast<jvm_internal::breakpoint_info**>(
		reinterpret_cast<uint8_t*>(this) + _breakpoints_entry->offset);
}
//
// Created by Administrator on 2024/3/15.
//

#include "java_thread.h"

auto java_hotspot::threads::first() -> java_thread* {
	static VMStructEntry* _thread_list_entry = JVMWrappers::find_type_fields("Threads").value().get()["_thread_list"];
	if (!_thread_list_entry) {
		return nullptr;
	}
	return *static_cast<java_thread**>(_thread_list_entry->address);
}

auto java_hotspot::java_thread::get_next() -> java_thread* {
	static VMStructEntry* _next_entry = JVMWrappers::find_type_fields("JavaThread").value().get()["_next"];
	if (!_next_entry) {
		return nullptr;
	}
	return *reinterpret_cast<java_thread**>(reinterpret_cast<uint8_t*>(this) + _next_entry->offset);
}

auto java_hotspot::java_thread::get_jni_environment() -> JNIEnv* {
	static VMStructEntry* _anchor_entry = JVMWrappers::find_type_fields("JavaThread").value().get()["_anchor"];
	static VMTypeEntry* _java_thread_type = JVMWrappers::find_type("JavaFrameAnchor").value();
	if (!_anchor_entry) {
		return {};
	}
	constexpr uint8_t thread_function_size = 8;
	return reinterpret_cast<JNIEnv*>(reinterpret_cast<uint8_t*>(this) + _anchor_entry->offset + _java_thread_type->
		size + thread_function_size);
}

auto java_hotspot::java_thread::get_thread_object() -> oop {
	static VMStructEntry* _thread_object_entry = JVMWrappers::find_type_fields("JavaThread").value().get()[
		"_threadObj"];
	if (!_thread_object_entry) {
		return {};
	}
	return *reinterpret_cast<oop*>(reinterpret_cast<uint8_t*>(this) + _thread_object_entry->offset);
}

auto java_hotspot::java_thread::set_thread_object(oop obj) -> void {
	static VMStructEntry* _thread_object_entry = JVMWrappers::find_type_fields("JavaThread").value().get()[
		"_threadObj"];
	if (!_thread_object_entry) {
		return;
	}
	*reinterpret_cast<oop*>(reinterpret_cast<uint8_t*>(this) + _thread_object_entry->offset) = obj;
}

auto java_hotspot::java_thread::get_thread_state() -> int {
	static VMStructEntry* _thread_state_entry = JVMWrappers::find_type_fields("JavaThread").value().get()[
		"_thread_state"];
	if (!_thread_state_entry) {
		return {};
	}
	return *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _thread_state_entry->offset);
}

auto java_hotspot::java_thread::set_thread_state(const int state) -> void {
	static VMStructEntry* _thread_state_entry = JVMWrappers::find_type_fields("JavaThread").value().get()[
		"_thread_state"];
	if (!_thread_state_entry) {
		return;
	}
	*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _thread_state_entry->offset) = state;
}

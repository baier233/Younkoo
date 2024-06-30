#include "compile_task.h"

auto java_hotspot::compile_task::get_method() -> method*
{
	static VMStructEntry* _method_entry = JVMWrappers::find_type_fields("CompileTask").value().get()[
		"_method"];
	if (!_method_entry) {
		return {};
	}
	return *reinterpret_cast<method**>(reinterpret_cast<uint8_t*>(this) + _method_entry->offset);
}

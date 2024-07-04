//
// Created by Administrator on 2024/3/15.
//

#include "jvm_internal.h"


JVMWrappers::struct_entries_t JVMWrappers::struct_entries;
JVMWrappers::type_entries_t JVMWrappers::type_entries;
JVMWrappers::int_entries_t JVMWrappers::int_entries;
JVMWrappers::long_entries_t JVMWrappers::long_entries;

//#define DEBUGGER

void JVMWrappers::init(VMStructEntry* vmstructs, VMTypeEntry* vmtypes, VMIntConstantEntry* vmints,
	VMLongConstantEntry* vmlongs) {
	for (int i = 0; vmstructs[i].fieldName != nullptr; ++i) {
		const auto s = &vmstructs[i];
#ifdef DEBUGGER
		std::cout << "VMStructEntry: \n"
			"type: " << s->typeName << "\n"
			"field: " << s->fieldName << "\n"
			"static: " << (s->isStatic ? "true" : "false") << "\n";
		if (s->isStatic)
			std::cout <<
			"address: " << s->address << "\n";
		std::cout << "offset: " << s->offset << "\n\n";
#endif // DEBUGGER
		struct_entries[s->typeName][s->fieldName] = s;
	}

	for (int i = 0; vmtypes[i].typeName != nullptr; ++i) {
		const auto t = &vmtypes[i];
#ifdef DEBUGGER
		std::cout << "VMType :" << t->typeName << "\nSize :" << t->size << "\n\n";
#endif // DEBUGGER

		type_entries[t->typeName] = t;
	}


	for (int i = 0; vmints[i].name != nullptr; ++i) {
		const auto v = &vmints[i];
#ifdef DEBUGGER
		std::cout << "VMInt :" << v->name << "\nValue :" << v->value << "\n\n";
#endif // DEBUGGER
		int_entries[v->name] = v;
	}

	for (int i = 0; vmlongs[i].name != nullptr; ++i) {
		const auto l = &vmlongs[i];
#ifdef DEBUGGER
		std::cout << "VMLong :" << l->name << "\nValue :" << l->value << "\n\n";
#endif // DEBUGGER
		long_entries[l->name] = l;
	}
}

std::optional<std::reference_wrapper<JVMWrappers::struct_entry_t> >
JVMWrappers::find_type_fields(const char* typeName) {
	for (auto& [name, second] : struct_entries) {

		if (name == typeName)
			return second;
	}

	return std::nullopt;
}



std::optional<VMTypeEntry*> JVMWrappers::find_type(const char* typeName) {
	const auto pair = type_entries.find(typeName);
	if (pair == type_entries.end())
		return std::nullopt;

	return pair->second;
}

/* VMType */
std::optional<JVMWrapper> JVMWrapper::from_instance(const char* typeName, void* instance) {
	const auto type = JVMWrappers::find_type(typeName);
	if (!type.has_value())
		return std::nullopt;

	const auto fields = JVMWrappers::find_type_fields(typeName);
	if (!fields.has_value())
		return std::nullopt;

	JVMWrapper vmtype;
	vmtype.instance = instance;
	vmtype.type_entry = type.value();
	vmtype.fields = fields;

	return vmtype;
}
auto jvm_internal::access_flags::get_flags() -> jint {
	static VMStructEntry* _flags_entry = JVMWrappers::find_type_fields("AccessFlags").value().get()["_flags"];
	if (!_flags_entry)
		return 0;
	return *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _flags_entry->offset);
}

auto jvm_internal::access_flags::set_flags(const jint flags) -> void {
	static VMStructEntry* _flags_entry = JVMWrappers::find_type_fields("AccessFlags").value().get()["_flags"];
	if (!_flags_entry)
		return;
	*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(this) + _flags_entry->offset) = flags;
}
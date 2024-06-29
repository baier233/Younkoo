#include "java_hook.h"



/* JVM exports some symbols that we need to use */
extern "C" JNIIMPORT VMStructEntry * gHotSpotVMStructs;
extern "C" JNIIMPORT VMTypeEntry * gHotSpotVMTypes;
extern "C" JNIIMPORT VMIntConstantEntry * gHotSpotVMIntConstants;
extern "C" JNIIMPORT VMLongConstantEntry * gHotSpotVMLongConstants;


static auto InitGlobalOffsets() -> void {
	/* .\hotspot\src\share\vm\classfile\javaClasses.hpp -> class java_lang_Class : AllStatic */
	const auto java_lang_Class = JVMWrappers::find_type_fields("java_lang_Class");
	if (!java_lang_Class.has_value()) {
		std::cout << "Failed to find java_lang_Class" << std::endl;
	}

	/* java_lang_Class -> _klass_offset */
	global_offsets::klass_offset = *static_cast<jint*>(java_lang_Class.value().get()["_klass_offset"]->address);
}



/* Scan bytecode offset */
static auto ScanByteCodeOffset(JNIEnv* env) -> void {
	/* Any class */
	const auto integer_klass = env->FindClass("java/lang/Integer");

	if (!integer_klass) {
		std::cout << "Failed to find java/lang/Integer" << std::endl;
	}
	/* Any method */
	const auto integer_hash_code = env->GetMethodID(integer_klass, "shortValue", "()S");
	if (!integer_hash_code) {
		std::cout << "Failed to find java/lang/Integer::shortValue" << std::endl;
	}
	/* Get method */
	const auto hash_method = *reinterpret_cast<java_hotspot::method**>(integer_hash_code);
	if (!hash_method) {
		std::cout << "Failed to find java/lang/Integer::shortValue" << std::endl;
	}
	java_hotspot::bytecode_start_offset = java_hotspot::const_method::get_const_method_length();
	std::cout << "Bytecode start offset: " << java_hotspot::bytecode_start_offset << std::endl;

	/* Interception address */
	java_hotspot::interpreter_entry* interpreter_entry = hash_method->get_i2i_entry();
	if (const auto interception_address = interpreter_entry->get_interception_address(); !interception_address) {
		std::cout << "Failed to find interception address" << std::endl;
	}
	std::cout << "Interception address: " << reinterpret_cast<void*>(interpreter_entry->get_interception_address()) <<
		std::endl;

	/* Get dispatch table */
	const uintptr_t dispatch_table = *reinterpret_cast<uintptr_t*>(interpreter_entry->get_interception_address() + 2);
	if (!dispatch_table) {
		std::cout << "Failed to find dispatch table" << std::endl;
	}
	std::cout << "Dispatch table: " << reinterpret_cast<void*>(dispatch_table) << std::endl;

	/* Get breakpoint method */
	const uintptr_t breakpoint_method = *reinterpret_cast<uintptr_t*>(dispatch_table + static_cast<uint8_t>(java_runtime::bytecodes::_breakpoint) * 8);
	if (!breakpoint_method) {
		std::cout << "Failed to find breakpoint method" << std::endl;
	}
	std::cout << "Breakpoint method: " << reinterpret_cast<void*>(breakpoint_method) << std::endl;

	/* Get VM calls */
	const std::vector<void*> vm_calls = vm_helper::find_vm_calls(reinterpret_cast<PVOID>(breakpoint_method));
	if (vm_calls.size() < 2) {
		std::cout << "Failed to find VM calls" << std::endl;
	}
	std::cout << "VM calls: " << vm_calls.size() << std::endl;

	// Hook the runtime methods
	void* runtime_get_original_bytecode = vm_calls[0];
	void* runtime_breakpoint_method = vm_calls[1];
	std::cout << "Runtime get original bytecode: " << runtime_get_original_bytecode << std::endl;
	std::cout << "Runtime breakpoint method: " << runtime_breakpoint_method << std::endl;
	jvm_break_points::breakpoint_hook.InitHook(runtime_breakpoint_method, jvm_break_points::breakpoint_callback);
	jvm_break_points::original_bytecode_hook.InitHook(runtime_get_original_bytecode,
		jvm_break_points::original_bytecode_handler);
	jvm_break_points::breakpoint_hook.SetHook();
	jvm_break_points::original_bytecode_hook.SetHook();
}




bool JavaHook::JVM::Init(JNIEnv* env)
{
	//const auto interop = std::make_unique<java_interop>(env);
	JVMWrappers::init(gHotSpotVMStructs, gHotSpotVMTypes, gHotSpotVMIntConstants, gHotSpotVMLongConstants);
	InitGlobalOffsets();
	ScanByteCodeOffset(env);
	return false;
}

bool JavaHook::JVM::clean()
{
	jvm_break_points::breakpoint_hook.RemoveHook();
	jvm_break_points::original_bytecode_hook.RemoveHook();
	return true;
}

JavaHook::MethodHook::MethodHook()
{
	this->target_method = 0;
	this->detour = 0;
	this->isHooked = false;
}

JavaHook::MethodHook::MethodHook(const jmethodID method, hook_callback_t detour) : MethodHook()
{
	this->InitHook(method, detour);
}

JavaHook::MethodHook::~MethodHook()
{
	if (this->isHooked)
	{
		this->RemoveHook();
	}

	this->detour = 0;
	this->target_method = 0;

}


void JavaHook::MethodHook::RemoveHook()
{
	if (!this->isHooked)
	{
		return;
	}
	hook_map.erase(this->target_method);
	this->target_method->remove_all_break_points();
}



void JavaHook::MethodHook::SetHook() {

	if (this->isHooked)
	{
		return;
	}

	//TODO : use nmethod to know if method has been JITd.

	hook_map[this->target_method] = this;
	this->target_method->set_dont_inline(true);
	const auto access_flags = this->target_method->get_access_flags();
	access_flags->set_not_c1_compilable();
	access_flags->set_not_c2_compilable();
	access_flags->set_not_c2_osr_compilable();
	access_flags->set_queued_for_compilation();

	const auto constants_pool = target_method->get_const_method()->get_constants();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());
	auto* info = jvm_internal::breakpoint_info::create(target_method, 0);
	info->set_orig_bytecode(static_cast<java_runtime::bytecodes>(target_method->get_const_method()->get_bytecode()[0]));
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);
	this->target_method->set_break_point(0x00,
		breakpoint_callback_handler);
}

void JavaHook::MethodHook::InitHook(const jmethodID method, hook_callback_t detour)
{
	if (!method || !detour)
	{
		return;
	}

	auto target = *reinterpret_cast<java_hotspot::method**>(method);
	if (!target)
	{
		return;
	}

	this->target_method = target;
	this->detour = detour;
	this->isHooked = false;
}

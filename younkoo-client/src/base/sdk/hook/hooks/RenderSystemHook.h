#pragma once
#include <Windows.h>
#include <SDK.hpp>
#include <JVM.hpp>

#include <hotspot/java_hook.h>
#include <hotspot/break/byte_code_info.h>
#include <hotspot/classes/compile_task.h>


#include <wrapper/versions/1_18_1/net/minecraft/client/renderer/GameRenderer.h>
#include <wrapper/versions/1_18_1/com/mojang/blaze3d/vertex/PoseStack.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/MInecraft.h>

#include <utils/Pattern.h>
#include <utils/types/Maths.hpp>

#include <base/Younkoo.hpp>
#include <base/event/Events.h>

#include <format>

namespace RenderSystemHook {

	void applyHook();

	inline std::vector<java_hotspot::method*> methods_being_hooked;
	inline void detour_invoke_compiler_on_method(java_hotspot::compile_task* task);
	inline TitanHook<decltype(&detour_invoke_compiler_on_method)> _invoke_compiler_on_method_hook;
	inline void cleanHook() {
		for (auto ptr : methods_being_hooked)
		{
			auto method = reinterpret_cast<java_hotspot::method*>(ptr);
			method->remove_all_break_points();
		}
		JavaHook::JVM::clean();
		_invoke_compiler_on_method_hook.RemoveHook();
	}
	struct BytecodeInfo
	{
		BytecodeInfo() {  };
		java_runtime::bytecodes opcode;
		std::vector<int> operands;
		int index = 0;
	};
	inline void detour_invoke_compiler_on_method(java_hotspot::compile_task* task) {
		//TODO : hook ok_to_inline to improve performance
		auto method = task->get_method();
		auto current_pool_holder = method->get_const_method()->get_constants()->get_pool_holder();
		//std::cout << "Compiling method :" << method->get_name() << std::endl;
		for (auto pMethod : methods_being_hooked)
		{


			if (current_pool_holder == pMethod->get_const_method()->get_constants()->get_pool_holder())
			{
				//std::cout << "Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string() << std::endl;
				return;
			}
		}

		_invoke_compiler_on_method_hook.GetOrignalFunc()(task);
	}
	inline uintptr_t plocalvariable_table_length_addr = 0;
	inline unsigned short* localvariable_table_length_addr(java_hotspot::const_method* cm) {
		auto func = (decltype(&localvariable_table_length_addr))plocalvariable_table_length_addr;
		return func(cm);
	}
	inline uintptr_t plocalvariable_table_start = 0;
	inline java_hotspot::local_variable_table_element* localvariable_table_start(java_hotspot::const_method* cm) {
		auto func = (decltype(&localvariable_table_start))plocalvariable_table_start;
		return func(cm);
	}
	inline void hook_invoke_compiler_on_method() {
		auto jvm = (uintptr_t)GetModuleHandleA("jvm.dll");

		//CompileBroker::invoke_compiler_on_method(CompileTask *task)
		auto pinvoke_compiler_on_method = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8D AC 24 80 FA FF FF 48 81 EC 80 06 00 00 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 70 05 00 00 33 D2");// this function will call    __dyn_tls_on_demand_init and doing something like NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)TlsIndex);
		if (!pinvoke_compiler_on_method)
		{
			MessageBox(0, L"Failed to get the address of invoke_compiler_on_method", 0, 0);
		}
		_invoke_compiler_on_method_hook.InitHook(pinvoke_compiler_on_method, detour_invoke_compiler_on_method);
		_invoke_compiler_on_method_hook.SetHook();


	}


}
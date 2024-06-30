#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/client/renderer/ClientRenderer.h>
#include <JVM.hpp>
#include  <hotspot/java_hook.h>
#include <hotspot/break/byte_code_info.h>
namespace RenderSystemHook {
	inline std::vector<uint8_t*> methods_being_hooked;
	inline void cleanHook() {
		for (auto ptr : methods_being_hooked)
		{
			auto method = reinterpret_cast<java_hotspot::method*>(ptr);
			method->remove_all_break_points();
		}
		JavaHook::JVM::clean();
	}
	struct BytecodeInfo
	{
		BytecodeInfo() {  };
		java_runtime::bytecodes opcode;
		std::vector<int> operands;
		int index = 0;
	};



	inline void applyHook() {

		jclass klass = JNI::find_class(V1_18_1::GameRenderer::get_name());
		JVM::get().jvmti->RetransformClasses(1, &klass);
		JavaHook::JVM::Init(JNI::get_env());
		const auto method = *reinterpret_cast<java_hotspot::method**>((jmethodID)V1_18_1::GameRenderer::static_obj().renderLevel);

		method->set_dont_inline(true);
		const auto access_flags = method->get_access_flags();
		access_flags->set_not_c1_compilable();
		access_flags->set_not_c2_compilable();
		access_flags->set_not_c2_osr_compilable();
		access_flags->set_queued_for_compilation();

		const auto constants_pool = method->get_const_method()->get_constants();

		auto const_method = method->get_const_method();

		auto bytecodes = const_method->get_bytecode();
		const size_t bytecodes_length = bytecodes.size();
		auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());
		int bytecodes_index = 0;
		std::cout << "length :" << bytecodes_length << std::endl;
		std::cout << "bytecode addr " << (void*)const_method->get_bytecode_start() << std::endl;
		std::list<BytecodeInfo> method_block;
		while (bytecodes_index < bytecodes_length) {
			const auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes[bytecodes_index]);
			auto opcodes = java_runtime::bytecode::bytecode(bytecodes.data() + bytecodes_index);
			BytecodeInfo current_bytecode;
			current_bytecode.opcode = bytecode;
			current_bytecode.index = bytecodes_index;
			{
				auto name = java_runtime::bytecode_names[bytecode];
				std::cout << (int)opcodes.get_opcode() << " " << name << " {";
				auto length = opcodes.get_length();
				for (size_t i = 0; i < length - 1; i++)
				{
					if (i == 0)
					{
						int opreand = (int)bytecodes[bytecodes_index + i];
						current_bytecode.operands.push_back(opreand);
						std::cout << opreand;
					}
					else {

						int opreand = (int)bytecodes[bytecodes_index + i];
						current_bytecode.operands.push_back(opreand);
						std::cout << " , " << (int)bytecodes[bytecodes_index + i];
					}
				}
				method_block.push_back(current_bytecode);
				std::cout << "}" << std::endl;
				bytecodes_index += length;

			}
		}
		for (auto& bytecode_info : method_block)
		{
			if (bytecode_info.opcode == java_runtime::bytecodes::_return_register_finalizer && bytecode_info.operands[0] == 231 && bytecode_info.operands[1] == 156) // ldc "hand"
			{
				std::cout << "setting bytecode on index " << bytecode_info.index << " whose original byte is " << (int)bytecode_info.opcode << " method : " << method << std::endl;
				auto* info = jvm_internal::breakpoint_info::create(method, bytecode_info.index);
				info->set_orig_bytecode(bytecode_info.opcode);
				info->set_next(holder_klass->get_breakpoints());
				holder_klass->set_breakpoints(info);
				methods_being_hooked.push_back((uint8_t*)method);
				jvm_break_points::set_breakpoint_with_original_code(method, bytecode_info.index, static_cast<std::uint8_t>(bytecode_info.opcode), [](break_point_info* bp) -> void
					{
						//auto stack = bp->java_thread->get_operand_stack();
						auto parma = (uintptr_t*)bp->get_parameters();
						auto gameRender = bp->get_parameter(0);
						auto p_109090_ = *(float*)bp->get_parameter(1);
						long p_109091_ = *bp->lload(2);
						auto p_109092_ = bp->get_parameter(3);
						auto matrix4f = bp->get_parameter(25);

						std::cout << "matrix4f :" << matrix4f << "\ngameRender :" << gameRender << "\np_109090_ :" << p_109090_ << "\np_109091_ :" << p_109091_ << "\np_109092_ :" << p_109092_ << "\nmatrix4f :" << matrix4f << "\n" << std::endl;

						return;
					});
				break;
			}
		}


	}

}
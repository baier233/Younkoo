#include "PlayerHook.h"
#include <format>
#include <wrapper/versions/1_18_1/net/minecraft/world/entity/player/Player.h>
void PlayerHook::hook(const HookManagerData& container)
{
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	std::cout << "Processing hook for Level " << std::endl;

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;


	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::Player::get_name());

	JVM::get().jvmti->RetransformClasses(1, &klass);
	auto mid = (jmethodID)V1_18_1::Player::static_obj().attack;
	const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
	methods_being_hooked.emplace_back(method);

	HookUtils::GenericResolve(method);

	const auto constants_pool = method->get_const_method()->get_constants();

	auto const_method = method->get_const_method();

	auto bytecodes = const_method->get_bytecode();
	const size_t bytecodes_length = bytecodes.size();
	auto* holder_klass = static_cast<java_hotspot::instance_klass*>(constants_pool->get_pool_holder());
	std::list<BytecodeInfo> method_block;

	{
		int bytecodes_index = 0;
		auto indices = std::views::iota(size_t{ 0 }, bytecodes_length);

		std::ranges::for_each(indices, [&](auto idx) {
			if (bytecodes_index >= bytecodes_length) return;

			const auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes[bytecodes_index]);
			auto opcodes = java_runtime::bytecode(bytecodes.data() + bytecodes_index);
			BytecodeInfo current_bytecode;
			current_bytecode.opcode = bytecode;
			current_bytecode.index = bytecodes_index;

			const auto& name = java_runtime::bytecode_names[bytecode];
			std::cout << "(" << bytecodes_index << ")  " << name << " {";
			auto length = opcodes.get_length();

			for (int i = 0; i < length - 1; ++i) {
				int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
				current_bytecode.operands.push_back(operand);
				std::cout << (i == 0 ? "" : " , ") << operand;
			}
			method_block.push_back(current_bytecode);
			std::cout << "}" << std::endl;
			bytecodes_index += length;
			});
	}

	auto& bc_info = method_block.front();
	auto hook_index = bc_info.index;
	auto* info = jvm_internal::breakpoint_info::create(method, hook_index);
	auto bytecode = static_cast<java_runtime::bytecodes>(bc_info.opcode);
	info->set_orig_bytecode(bytecode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);

	(void)JNI::get_env()->PopLocalFrame(nullptr);
	std::cout << std::format("setting return hook for :{}", bc_info.index) << std::endl;
	jvm_break_points::set_breakpoint_with_original_code(method, hook_index, static_cast<std::uint8_t>(bytecode), [mid](break_point_info* bp) -> void
		{
			static std::once_flag flag{};
			std::call_once(flag, [bp] {
				{
					const auto c_m = bp->method->get_const_method();
					const auto entries = c_m->get_local_variable_entries();
					std::cout << "Handling setBlock Hook" << std::endl;
					for (auto& entry : entries)
					{
						std::cout << std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot) << std::endl;
					}
				}
				});
			JNI::set_thread_env(bp->java_thread->get_jni_environment());
			auto o_state = bp->java_thread->get_thread_state();
			bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);

			std::cout << "OnAttack" << std::endl;

			bp->java_thread->set_thread_state(o_state);
			//std::cout << "OnRendering BED" << std::endl;

		});

}

#include "RenderSystemHook.h"


void RenderSystemHook::applyHook() {
	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;

	jclass klass = JNI::find_class(V1_18_1::GameRenderer::get_name());

	JavaHook::JVM::Init(JNI::get_env());

	//if we dont hook it, when method is going to be inlined,it will crahes with "error: unhandled bytecode".
	hook_invoke_compiler_on_method();

	JVM::get().jvmti->RetransformClasses(1, &klass);
	auto mid = (jmethodID)V1_18_1::GameRenderer::static_obj().renderLevel;
	const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
	methods_being_hooked.emplace_back(method);
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
	size_t bytecodes_index = 0;
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
			std::cout << "(" << bytecodes_index << ")  " << name << " {";
			auto length = opcodes.get_length();
			for (int i = 0; i < length - 1; i++)
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
	static std::vector<BytecodeInfo> return_register_finalizer_list;
	for (auto& bytecode_info : method_block)
	{

		if (bytecode_info.opcode == java_runtime::bytecodes::_return_register_finalizer /*&& bytecode_info.operands[0] == 231 && bytecode_info.operands[1] == 158*/) // ldc "hand"
		{
			return_register_finalizer_list.push_back(bytecode_info);

		}

	}
	std::cout << " return_register_finalizer_list.size() :" << return_register_finalizer_list.size() << std::endl;
	auto opcode = return_register_finalizer_list.at(return_register_finalizer_list.size() - 2);
	std::cout << "setting bytecode on index " << opcode.index << " whose original byte is " << (int)opcode.opcode << " method : " << method << std::endl;
	auto* info = jvm_internal::breakpoint_info::create(method, opcode.index);
	info->set_orig_bytecode(opcode.opcode);
	info->set_next(holder_klass->get_breakpoints());
	holder_klass->set_breakpoints(info);
	jvm_break_points::set_breakpoint_with_original_code(method, opcode.index, static_cast<std::uint8_t>(opcode.opcode), [mid](break_point_info* bp) -> void
		{
			//auto stack = bp->java_thread->get_operand_stack();
			const auto orginal_state = bp->java_thread->get_thread_state();
			bp->java_thread->set_thread_state(JavaThreadState::_thread_in_native);
			JNI::set_thread_env(bp->java_thread->get_jni_envoriment());

			auto gameRender_obj = (jobject)bp->get_parameter(0);
			auto tickDelta = *(float*)bp->get_parameter(1);

			long startTime = *bp->lload(2);

			static int matrix4f_4f_slot = 11;
			static int poseStack_slot = 4;
			static std::once_flag flag{};
			std::call_once(flag, [bp] {
				{
					auto c_m = bp->method->get_const_method();
					auto entries = c_m->get_local_variable_entries();
					for (auto& entry : entries)
					{
						std::cout << std::format("entry : {}\nstart_location: {}\nlength: {}\nsignature: {}\ngeneric_signature: {}\nslot: {}",
							entry.name, entry.start_location, entry.length, entry.signature, entry.generic_signature, entry.slot) << std::endl;
						if (entry.name == "matrix4f")
						{
							matrix4f_4f_slot = entry.slot;
							std::cout << "Found matrix4f_4f_slot in " << matrix4f_4f_slot << std::endl;
						}

						if (entry.name == "p_109092_")
						{
							poseStack_slot = entry.slot;
							std::cout << "Found poseStack_slot in " << poseStack_slot << std::endl;
						}
					}
				}

				});


			auto poseStack = (jobject)bp->get_parameter(poseStack_slot);
			auto matrix4f = (jobject)bp->get_parameter(matrix4f_4f_slot);


			/*jclass klass = JNI::get_env()->GetObjectClass(matrix4f);
			if (klass)
			{
				auto instacne = java_hotspot::instance_klass::get_instance_class(klass);
				std::cout << "matrix4f klass:" << instacne->get_name()->to_string() << std::endl;

			}*/



#ifdef DEBUG



			JNI::get_env()->DeleteLocalRef(klass);


			{
				jthread thread;
				JVM::get().jvmti->GetCurrentThread(&thread);
				char out[1024];
				jint param_size = 0;

				JVM::get().jvmti->GetArgumentsSize(mid, &param_size);
				printf("method_entry: %s%s%, param_size:%d\n", bp->method->get_signature().c_str(), bp->method->get_name().c_str(), param_size);

				jint entry_count = 0;
				jvmtiLocalVariableEntry* table_ptr = NULL;
				jlocation cur_loc{};
				jmethodID methoid;
				auto err = JVM::get().jvmti->GetLocalVariableTable(mid, &entry_count, &table_ptr);
				err = JVM::get().jvmti->GetFrameLocation(thread, 0, &methoid, &cur_loc);
				for (int j = 0; j < entry_count; j++) {
					if (!table_ptr[j].name || !table_ptr[j].signature) continue;
					printf("name:%s ,signature:%s , slot:%d, start:%ld, cur:%ld, param:%s%s\n", table_ptr[j].name, table_ptr[j].signature, table_ptr[j].slot, table_ptr[j].start_location, cur_loc, table_ptr[j].signature, table_ptr[j].name);
					JVM::get().jvmti->Deallocate(reinterpret_cast<unsigned char*>(table_ptr[j].signature));
					JVM::get().jvmti->Deallocate(reinterpret_cast<unsigned char*>(table_ptr[j].name));
					JVM::get().jvmti->Deallocate(reinterpret_cast<unsigned char*>(table_ptr[j].generic_signature));

				}
			}
#endif // DEBUG


			V1_18_1::PoseStack stack(poseStack, true);
			V1_18_1::Matrix4f projectionMatrix(matrix4f, true);

			V1_18_1::GameRenderer gameRenderer(gameRender_obj, true);

			static auto fill_matrix_with_matrix4f = [](Math::Matrix& matrix_struct, V1_18_1::Matrix4f& matrix_obj) {
				matrix_struct.m00 = matrix_obj.m00.get();
				matrix_struct.m01 = matrix_obj.m01.get();
				matrix_struct.m02 = matrix_obj.m02.get();
				matrix_struct.m03 = matrix_obj.m03.get();

				matrix_struct.m10 = matrix_obj.m10.get();
				matrix_struct.m11 = matrix_obj.m11.get();
				matrix_struct.m12 = matrix_obj.m12.get();
				matrix_struct.m13 = matrix_obj.m13.get();

				matrix_struct.m20 = matrix_obj.m20.get();
				matrix_struct.m21 = matrix_obj.m21.get();
				matrix_struct.m22 = matrix_obj.m22.get();
				matrix_struct.m23 = matrix_obj.m23.get();

				matrix_struct.m30 = matrix_obj.m30.get();
				matrix_struct.m31 = matrix_obj.m31.get();
				matrix_struct.m32 = matrix_obj.m32.get();
				matrix_struct.m33 = matrix_obj.m33.get();
				};

			auto modelViewMatrix = stack.last().pose();
			/*jclass modelview_klass = JNI::get_env()->GetObjectClass(modelViewMatrix);
			if (modelview_klass)
			{
				auto instacne = java_hotspot::instance_klass::get_instance_class(klass);
				std::cout << "modelview klass:" << instacne->get_name()->to_string() << std::endl;

			}*/
			Math::Matrix projection{ }, modelView{};
			fill_matrix_with_matrix4f(projection, projectionMatrix);
			fill_matrix_with_matrix4f(modelView, modelViewMatrix);
			auto scale = V1_18_1::Minecraft::static_obj().getInstance().getWindow().getGuiScale();
			Younkoo::get().EventBus.get()->fire_event(EventRender3D{
				.PROJECTION_MATRIX = projection,
				.MODLEVIEW_MATRIX = modelView,
				.CAMERA_POS = gameRenderer.getMainCamera().getPosition().toVector3(),
				.TICK_DELTA = tickDelta
				,.START_TIME = startTime,
				.GUI_SCALE = scale
				});

			projectionMatrix.clear_ref();
			stack.clear_ref();
			gameRenderer.clear_ref();


			//std::cout << "\tickDelta :" << tickDelta << "\nstartTime :" << startTime << "\nposeStack :" << poseStack << "\nmatrix4f :" << matrix4f << "\n" << std::endl;




			bp->java_thread->set_thread_state(orginal_state);
			return;
		});
}
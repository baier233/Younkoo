//
// Created by Administrator on 2024/3/15.
//

#ifndef THREAD_H
#define THREAD_H

#include "../include_header.h"
#include "../utility/vm_helper.h"
#include "../utility/jvm_internal.h"

namespace java_hotspot {
	class thread_base {
	};

	class java_thread : public thread_base {
	public:
		auto get_next() -> java_thread*;

		auto get_jni_envoriment() -> JNIEnv*;

		inline uintptr_t* get_operand_stack()
		{
			if (!vm_helper::thread_operand_stack_offset)
				throw std::runtime_error("JavaThread::preserved_sp_offset is not initialized");
			return *(uintptr_t**)((uintptr_t)this + vm_helper::thread_operand_stack_offset);
		}

		auto get_thread_object() -> oop;

		auto set_thread_object(oop obj) -> void;

		auto get_thread_state() -> int;

		auto set_thread_state(int state) -> void;
	};

	namespace threads {
		auto first() -> java_thread*;
	}
}


#endif //THREAD_H

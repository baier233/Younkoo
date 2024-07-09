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
	class frame
	{
	public:
		inline static frame* create_frame(uintptr_t frame_address)
		{
			constexpr std::size_t size = offsetof(frame, link);
			return (frame*)(frame_address - size);
		}

		void* initial_sp; // -8
		void* bcp; // -7
		void* cache; // -6
		void* mdp; // -5
		void* mirror; // -4
		void* method; // -3
		void* last_sp; // -2
		uintptr_t sender_sp; // -1;
		uintptr_t link; // 0
		void* return_address; // 1

		inline void debug_print()
		{
			printf("Frame: %llx\n", this);
			printf("\tInitial SP: %llx\n", initial_sp);
			printf("\tBCP: %llx\n", bcp);
			printf("\tCache: %llx\n", cache);
			printf("\tMDP: %llx\n", mdp);
			printf("\tMirror: %llx\n", mirror);
			printf("\tMethod: %llx\n", method);
			printf("\tLast SP: %llx\n", last_sp);
			printf("\tSender SP: %llx\n", sender_sp);
			printf("\tLink: %llx\n", link);
			printf("\tReturn Address: %llx\n", return_address);
		}

	};
	class java_thread : public thread_base {
	public:
		auto get_next() -> java_thread*;

		auto get_jni_environment() -> JNIEnv*;

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

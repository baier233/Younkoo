//
// Created by Administrator on 2024/3/17.
//

#ifndef BREAK_POINT_INFO_H
#define BREAK_POINT_INFO_H
#include <functional>

#include "../classes/java_thread.h"
#include "../classes/bytecode.h"

namespace java_hotspot {
	class method;
}

namespace jvm_internal {
	class breakpoint_info {
	public:
		static auto create(java_hotspot::method* method, int bci) -> breakpoint_info*;

		auto orig_bytecode() -> java_runtime::bytecodes;

		auto bci() -> int;

		auto name_index() -> uint16_t;

		auto signature_index() -> uint16_t;

		auto next() -> breakpoint_info*;

		auto set_orig_bytecode(java_runtime::bytecodes value) -> void;

		auto set_bci(int value) -> void;

		auto set_name_index(uint16_t value) -> void;

		auto set_signature_index(uint16_t value) -> void;

		auto set_next(breakpoint_info* value) -> void;
	};
}


namespace java_hotspot {
	class method;
}


class break_point_info {
public:
	explicit break_point_info(
		java_hotspot::method* method,
		uintptr_t bytecode_address,
		java_hotspot::java_thread* java_thread,
		uintptr_t parameters
	);

	~break_point_info();
	inline int get_operand_count() const
	{
		return this->bytecode->get_stack_consumption();
	}

	[[nodiscard]] auto get_bytecode_address() const->uintptr_t;

	[[nodiscard]] auto get_bytecode() const->java_runtime::bytecode*;

	[[nodiscard]] auto get_parameters() const->uintptr_t;

	[[nodiscard]] inline uintptr_t** get_parameter(std::size_t index) const
	{
		return (uintptr_t**)(this->parameters - index * 8);
	}
	[[nodiscard]] inline long* lload(std::size_t index) const
	{
		return (long*)(this->parameters + (-1 - index) * 8);
	}

	inline uintptr_t* get_operand(int i)
	{
		if (!this->java_thread)
			return nullptr;
		uintptr_t* operand_stack = this->java_thread->get_operand_stack();
		return (uintptr_t*)(operand_stack + i);
	}

	java_hotspot::method* method;

	uintptr_t bytecode_address;
	uintptr_t parameters;
	java_runtime::bytecode* bytecode;
	java_hotspot::java_thread* java_thread;
};


using breakpoint_callback_t = void (*)(java_hotspot::java_thread*, java_hotspot::method*, uintptr_t);
using original_bytecode_handler_t = uint8_t(*)(java_hotspot::java_thread*, java_hotspot::method*, uintptr_t);

using native_callback_t = std::function<void(break_point_info*)>;

#endif //BREAK_POINT_INFO_H

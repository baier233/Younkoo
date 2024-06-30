//
// Created by Administrator on 2024/3/15.
//

#ifndef METHOD_H
#define METHOD_H

#include "const_pool.h"
#include "../break/break_point_info.h"
#include "../utility/jvm_internal.h"


namespace java_hotspot {
	class interpreter_entry {
	public:
		inline uintptr_t get_interception_address() {
			/* Our pattern which identifies the *real* entrypoint to the method */
			/* ASM: jmp qword ptr ds:[r10+rbx*8]                                */
			/* This will never change, unless there is a custom jvm that changes the register order??? */
			constexpr std::uint8_t pattern[] = { 0x41, 0xFF, 0x24, 0xDA };
			constexpr std::size_t max_search_size = 0x1000;
			const auto address = reinterpret_cast<uintptr_t>(this);
			for (std::size_t i = 0; i < max_search_size; i++) {
				if (constexpr std::size_t pattern_size = sizeof(pattern); std::memcmp(
					reinterpret_cast<void*>(address + i),
					pattern, pattern_size) == 0) {
					constexpr std::size_t mov_size = 10;
					return address + i - mov_size;
				}
			}
			return 0;
		}
	};

	class const_method {
	public:
		auto get_constants() -> const_pool*;

		auto get_code_size() -> unsigned short;

		auto get_name_index() -> unsigned short;

		auto get_signature_index() -> unsigned short;

		auto get_const_method_size() -> unsigned short;

		auto get_max_stack() -> unsigned short;

		auto set_max_stack(unsigned short max_stack) -> void;

		auto get_max_locals() -> unsigned short;

		auto set_max_locals(unsigned short max_locals) -> void;

		auto get_size_of_parameters() -> unsigned short;

		auto get_method_idnum() -> unsigned short;

		auto get_bytecode_start() -> uint8_t*;

		auto get_bytecode_size() -> int;

		auto set_bytecode(const std::vector<uint8_t>& bytecode) -> void;

		auto get_bytecode() -> std::vector<uint8_t>;

		static auto get_const_method_length() -> size_t;
	};

	class method {
	public:
		auto get_const_method() -> const_method*;

		auto get_signature() -> std::string;

		auto get_name() -> std::string;

		auto get_i2i_entry() -> interpreter_entry*;

		auto set_break_point(uintptr_t offset, const native_callback_t& callback) -> void;

		auto remove_break_point(uintptr_t offset) -> void;

		auto remove_all_break_points() -> void;

		auto get_access_flags() -> jvm_internal::access_flags*;

		auto get_flags() -> unsigned short*;

		auto set_dont_inline(bool enabled) -> void;
	};

	inline size_t bytecode_start_offset;
}


#endif //METHOD_H

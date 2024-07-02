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


		auto get_const_flags() -> unsigned int*;

#define CM_FLAGS_GET_SET(name, ignore)          \
  bool name() { return (*get_const_flags() & _misc_##name) != 0; } \
  void set_##name() {         \
    *get_const_flags() |= _misc_##name;  \
  }
		CM_FLAGS_DO(CM_FLAGS_GET_SET)
#undef CM_FLAGS_GET_SET

			
		auto get_last_u2_element() -> uintptr_t*;

		auto get_localvariable_table_length_addr() -> void*;

		auto get_exception_table_length_addr() -> void*;



		inline unsigned short* method_parameters_length_addr() {
			assert(has_method_parameters(), "called only if table is present");
			return (unsigned short*)(has_generic_signature() ? (get_last_u2_element() - 1) :
				get_last_u2_element());
		}
		inline uintptr_t* method_parameters_start() {
			unsigned short* addr = method_parameters_length_addr();
			unsigned short length = *addr;
			static size_t method_parameters_element_size = JVMWrappers::find_type("MethodParametersElement").value()->size;
			addr -= length * method_parameters_element_size / sizeof(unsigned short);
			return (uintptr_t*)addr;
		}

		inline unsigned short* checked_exceptions_length_addr() {
			// Located immediately before the generic signature index.
			assert(has_checked_exceptions(), "called only if table is present");
			if (has_method_parameters()) {
				// If method parameters present, locate immediately before them.
				return (unsigned short*)method_parameters_start() - 1;
			}
			else {
				// Else, the exception table is at the end of the constMethod.
				return (unsigned short*)(has_generic_signature() ? (get_last_u2_element() - 1) :
					get_last_u2_element());
			}
		}

		inline uintptr_t* checked_exceptions_start() {
			unsigned short* addr = checked_exceptions_length_addr();
			unsigned short length = *addr;
			assert(length > 0, "should only be called if table is present");
			static size_t check_exception_element_size = JVMWrappers::find_type("CheckedExceptionElement").value()->size;
			addr -= length * check_exception_element_size / sizeof(unsigned short);
			return (uintptr_t*)addr;
		}



		inline uintptr_t* exception_table_start() {
			unsigned short* addr = (unsigned short*)get_exception_table_length_addr();
			unsigned short length = *addr;
			assert(length > 0, "should only be called if table is present");
			static size_t exception_table_size = JVMWrappers::find_type("ExceptionTableElement").value()->size;
			addr -= length * exception_table_size / sizeof(unsigned short);
			return (uintptr_t*)addr;
		}


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

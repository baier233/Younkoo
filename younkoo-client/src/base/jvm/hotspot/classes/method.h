//
// Created by Administrator on 2024/3/15.
//

#ifndef METHOD_H
#define METHOD_H

#include "const_pool.h"
#include "../break/break_point_info.h"
#include "../utility/jvm_internal.h"

#include "local_variable_table.h"

typedef unsigned short u2;

namespace java_hotspot {



#ifdef JDK22FEATURE
	class ConstMethodFlags {

#define CM_FLAGS_DO(flag)  \
   flag(has_linenumber_table      , 1 << 0) \
   flag(has_checked_exceptions    , 1 << 1) \
   flag(has_localvariable_table   , 1 << 2) \
   flag(has_exception_table       , 1 << 3) \
   flag(has_generic_signature     , 1 << 4) \
   flag(has_method_parameters     , 1 << 5) \
   flag(is_overpass               , 1 << 6) \
   flag(has_method_annotations    , 1 << 7) \
   flag(has_parameter_annotations , 1 << 8) \
   flag(has_type_annotations      , 1 << 9) \
   flag(has_default_annotations   , 1 << 10) \
   flag(caller_sensitive          , 1 << 11) \
   flag(is_hidden                 , 1 << 12) \
   flag(has_injected_profile      , 1 << 13) \
   flag(intrinsic_candidate       , 1 << 14) \
   flag(reserved_stack_access     , 1 << 15) \
   flag(is_scoped                 , 1 << 16) \
   flag(changes_current_thread    , 1 << 17) \
   flag(jvmti_mount_transition    , 1 << 18) \
   flag(deprecated                , 1 << 19) \
   flag(deprecated_for_removal    , 1 << 20) \
   /* end of list */

#define CM_FLAGS_ENUM_NAME(name, value)    _misc_##name = value,
		enum {
			CM_FLAGS_DO(CM_FLAGS_ENUM_NAME)
		};
#undef CM_FLAGS_ENUM_NAME

		// These flags are write-once before the class is published and then read-only so don't require atomic updates.
		unsigned int _flags;

	public:

		ConstMethodFlags() : _flags(0) {}

		// Create getters and setters for the flag values.
#define CM_FLAGS_GET_SET(name, ignore)          \
  inline bool name() { return (_flags & _misc_##name) != 0; } \
  inline void set_##name() {         \
    _flags |= _misc_##name;  \
  }
		CM_FLAGS_DO(CM_FLAGS_GET_SET)
#undef CM_FLAGS_GET_SET

			inline int as_int() const { return _flags; }
		inline void print_it() {
#define CM_PRINT(name, ignore)          \
  if (name()) printf(#name " ");
			CM_FLAGS_DO(CM_PRINT)
#undef CM_PRINT
		}
	};
#endif

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

		enum {
			_has_linenumber_table = 0x0001,
			_has_checked_exceptions = 0x0002,
			_has_localvariable_table = 0x0004,
			_has_exception_table = 0x0008,
			_has_generic_signature = 0x0010,
			_has_method_parameters = 0x0020,
			_is_overpass = 0x0040,
			_has_method_annotations = 0x0080,
			_has_parameter_annotations = 0x0100,
			_has_type_annotations = 0x0200,
			_has_default_annotations = 0x0400
		};
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

		auto get_localvariable_table_length_addr() -> void*;

#ifdef JDK22FEATURE
		auto get_const_flags_jdk22() -> ConstMethodFlags*;
#endif // JDK22FEATURE



		auto get_const_flags() -> u2;

		static auto get_const_method_length() -> size_t;

		auto get_size() -> int;

		std::vector<local_variable_entry> get_local_variable_entries();

#ifdef JDK22FEATURE
#define CM_FLAGS_GET_SET(name, ignore)          \
    inline bool name()       { return get_const_flags_jdk22()->name(); } \
	inline void set_##name()       { get_const_flags_jdk22()->set_##name(); }
		CM_FLAGS_DO(CM_FLAGS_GET_SET)
#undef CM_FLAGS_GET_SET
#endif // JDK22FEATURE


			inline bool has_exception_handler()
		{
			return (get_const_flags() & _has_exception_table) != 0;
		}

		inline bool has_method_annotations()
		{
			return (get_const_flags() & _has_method_annotations) != 0;
		}

		inline bool has_parameter_annotations()
		{
			return (get_const_flags() & _has_parameter_annotations) != 0;
		}

		inline bool has_type_annotations()
		{
			return (get_const_flags() & _has_type_annotations) != 0;
		}

		inline bool has_default_annotations()
		{
			return (get_const_flags() & _has_default_annotations) != 0;
		}

		inline bool has_generic_signature()
		{
			return (get_const_flags() & _has_generic_signature) != 0;
		}

		inline bool has_linenumber_table()
		{
			return (get_const_flags() & _has_linenumber_table) != 0;
		}

		inline bool has_checked_exceptions()
		{
			return (get_const_flags() & _has_checked_exceptions) != 0;
		}

		inline bool has_localvariable_table()
		{
			return (get_const_flags() & _has_localvariable_table) != 0;
		}


		inline bool has_method_parameters()
		{
			return (get_const_flags() & _has_method_parameters) != 0;
		}


		auto get_last_u2_element() -> u2*;


		auto get_exception_table_length_addr() -> void*;

		inline local_variable_table_element* localvariable_table_start() {
			u2* addr = (u2*)get_localvariable_table_length_addr();
			u2 length = *addr;
			assert(length > 0, "should only be called if table is present");
			auto local_variable_table_element_size = local_variable_table_element::get_size();
			auto size = static_cast<size_t>(length) * local_variable_table_element_size;
			addr -= size / sizeof(u2);
			return (local_variable_table_element*)addr;
		}


		inline unsigned short* method_parameters_length_addr() {
			assert(has_method_parameters(), "called only if table is present");
			return (unsigned short*)(has_generic_signature() ? (get_last_u2_element() - 1) :
				get_last_u2_element());
		}
		inline uint8_t* method_parameters_start() {
			unsigned short* addr = method_parameters_length_addr();
			unsigned short length = *addr;
			static size_t method_parameters_element_size = JVMWrappers::find_type("MethodParametersElement").value()->size;
			addr -= length * method_parameters_element_size / sizeof(unsigned short);
			return (uint8_t*)addr;
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

		inline uint8_t* checked_exceptions_start() {
			unsigned short* addr = checked_exceptions_length_addr();
			unsigned short length = *addr;
			assert(length > 0, "should only be called if table is present");
			static size_t check_exception_element_size = JVMWrappers::find_type("CheckedExceptionElement").value()->size;
			addr -= length * check_exception_element_size / sizeof(unsigned short);
			return (uint8_t*)addr;
		}



		inline uint8_t* exception_table_start() {
			unsigned short* addr = (unsigned short*)get_exception_table_length_addr();
			unsigned short length = *addr;
			assert(length > 0, "should only be called if table is present");
			static size_t exception_table_size = JVMWrappers::find_type("ExceptionTableElement").value()->size;
			addr -= length * exception_table_size / sizeof(unsigned short);
			return (uint8_t*)addr;
		}


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

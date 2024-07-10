//
// Created by Administrator on 2024/3/15.
//

#ifndef KLASS_H
#define KLASS_H

#include "const_pool.h"
#include "symbol.h"
#include "array.h"
#include "c_method.h"

namespace java_hotspot {
	class instance_klass {
	public:
		auto get_name() -> symbol*;

		auto get_constants() -> const_pool*;

		auto get_methods() -> array<method*>*;

		auto get_fields() -> array<uint16_t>*;

		void set_breakpoints(jvm_internal::breakpoint_info* breakpoints);

		jvm_internal::breakpoint_info* get_breakpoints();

		inline static instance_klass* get_instance_class(_jclass* const klasas) {
			/* Check if class is null */
			if (klasas == nullptr)
				return nullptr;

			/* Dereference class */
			void* klass_ptr = *reinterpret_cast<void**>(klasas);
			if (klass_ptr == nullptr)
				return nullptr;

			// Get the instance klass
			klass_ptr = *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(klass_ptr) + global_offsets::klass_offset);
			return static_cast<java_hotspot::instance_klass*>(klass_ptr);
		}

	};
}


#endif //KLASS_H

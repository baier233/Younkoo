//
// Created by Administrator on 2024/3/15.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "../include_header.h"
#include "../utility/jvm_internal.h"


namespace java_hotspot {
	template<typename T>
	class array {
	public:
		int64_t get_length() {
			if (sizeof(T) != 0x08) {
				return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this));
			}
			static auto typeArray = JVMWrappers::find_type_fields("Array<Klass*>");
			if (!typeArray.has_value()) return 0;
			static auto lengthEntry = typeArray.value().get()["_length"];
			return *reinterpret_cast<int64_t*>(reinterpret_cast<uintptr_t>(this) + lengthEntry->offset);
		}

		T* get_data() {
			if (sizeof(T) != 0x08) {
				static auto typeArray = JVMWrappers::find_type_fields("Array<u2>");
				if (!typeArray.has_value()) return nullptr;
				static auto dataEntry = typeArray.value().get()["_data"];
				return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + dataEntry->offset);
			}
			static auto typeArray = JVMWrappers::find_type_fields("Array<Klass*>");
			if (!typeArray.has_value()) return nullptr;
			static auto dataEntry = typeArray.value().get()["_data"];
			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + dataEntry->offset);
		}

		auto at(int i) -> T {
			if (i >= 0 && i < this->get_length())
				return static_cast<T>(this->get_data()[i]);
			return static_cast<T>(NULL);
		}

		[[nodiscard]] auto is_empty() const -> bool {
			return get_length() == 0;
		}

		T* adr_at(const int i) {
			if (i >= 0 && i < this->get_length())
				return &this->get_data()[i];
			return nullptr;
		}
		class iterator {
		public:
			iterator(T* ptr) : m_ptr(ptr) {}

			iterator operator++() { m_ptr++; return *this; }
			bool operator!=(const iterator& other) const { return m_ptr != other.m_ptr; }
			T& operator*() const { return *m_ptr; }

		private:
			T* m_ptr;
		};
		iterator begin() { return iterator(get_data()); }
		iterator end() { return iterator(get_data() + get_length()); }
	};

}


#endif //ARRAY_H

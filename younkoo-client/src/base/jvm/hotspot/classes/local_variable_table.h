#pragma once
#include <string>

namespace java_hotspot {

	class const_pool;

	struct local_variable_entry {
		long start_location;
		int length;
		std::string name;
		std::string signature;
		std::string generic_signature;
		int slot;
	};

	class local_variable_table_element
	{
	public:
		local_variable_entry wrap_to_jvm_variable_entry(const_pool* constant);
		static size_t get_size();
	};

}

#pragma once
#include "Env.hpp"
#include "Misc.hpp"

#include <iostream>

namespace JNI {
	template<class klass_type> struct jclass_cache
	{
		inline static std::shared_mutex mutex{};
		inline static jclass value = nullptr;
	};

	template<class klass_type> inline jclass get_cached_jclass() //findClass
	{
		jclass& cached = jclass_cache<klass_type>::value;
		{
			std::shared_lock shared_lock{ jclass_cache<klass_type>::mutex };
			if (cached) return cached;
		}
		auto klassName = klass_type::get_name();
		std::cout << "Finding Klass :" <<klassName << std::endl;
		jclass found = (jclass)get_env()->NewGlobalRef(get_env()->FindClass(klassName.c_str()));
		{
			std::unique_lock unique_lock{ jclass_cache<klass_type>::mutex };
			cached = found;
		}
		{
			std::lock_guard lock{ _refs_to_delete_mutex };
			_refs_to_delete.push_back(found);
		}
		return found;
	}


	template<class members_type>
	class Klass : public members_type
	{
	public:
		Klass(jobject object_instance = nullptr, bool is_global_ref = false) :
			members_type(get_cached_jclass<Klass>(), object_instance, is_global_ref) //be careful order of initialization matters
		{
			
		}

		static inline std::string get_name()
		{
			return members_type::get_class_name();
		}

		static inline std::string get_signature()
		{
			return "L" + members_type::get_class_name() + ";" ;
		}
		void print() {
			std::cout << get_name()   + " :\n{	"  << "\n  Name:" << this->get_name() << "\n  Sign:" << this->get_signature() << "\n  owner_klass :" << this->owner_klass << "\n}" << std::endl;
		}
	private:
	};
}
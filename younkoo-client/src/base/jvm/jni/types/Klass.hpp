#pragma once
#include "Env.hpp"
#include "Misc.hpp"


namespace JNI {
	template<typename klass_type> struct jclass_cache
	{
		inline static std::shared_mutex mutex{};
		inline static jclass value = nullptr;
	};

	template<typename klass_type> inline jclass get_cached_jclass() //findClass
	{
		jclass& cached = jclass_cache<klass_type>::value;
		{
			std::shared_lock shared_lock{ jclass_cache<klass_type>::mutex };
			if (cached) return cached;
		}
		jclass found = (jclass)get_env()->NewGlobalRef(get_env()->FindClass(klass_type::get_name()));
		assertm(found, (const char*)(concat<"failed to find class: ", klass_type::get_name()>()));
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
	class klass : public members_type
	{
	public:
		klass(std::string class_name,jobject object_instance = nullptr, bool is_global_ref = false) :
			class_name(class_name),
			members_type(get_cached_jclass<klass>(), object_instance, is_global_ref) //be careful order of initialization matters
		{
		}

		std::string get_name()
		{
			return class_name;
		}

		std::string get_signature()
		{
			return "L" + class_name + ";" ;
		}
	private:
		std::string class_name;
	};
}
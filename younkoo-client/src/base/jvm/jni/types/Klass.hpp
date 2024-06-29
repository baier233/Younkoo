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
	template<class klass_type> inline void clear_cached_jclass() {
		jclass& cached = jclass_cache<klass_type>::value;
		{
			std::unique_lock unique_lock{ jclass_cache<klass_type>::mutex };
			cached = nullptr;
		}
	}
	template<class klass_type> inline jclass get_cached_jclass() //findClass
	{
		jclass& cached = jclass_cache<klass_type>::value;
		{
			std::shared_lock shared_lock{ jclass_cache<klass_type>::mutex };
			if (cached) return cached;
		}

		auto klass_name = klass_type::get_name();
		std::cout << "Finding Klass :" << klass_name << std::endl;
		jclass found = (jclass)get_env()->NewGlobalRef(find_class(klass_name));
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


	template<class members_type, typename get_class_name_lambda>
	class Klass : public members_type
	{
	public:
		Klass(jobject object_instance = nullptr, bool is_global_ref = false) :
			members_type([]() {return get_cached_jclass<Klass>(); }, object_instance, is_global_ref)
		{
		}

		void init() {
			clear_cached_jclass<Klass>();
			get_cached_jclass<Klass>();
		}

		static inline std::string get_name()
		{
			return get_class_name_lambda()();
		}

		static inline std::string get_signature()
		{
			return "L" + get_name() + ";";
		}
		void print() {
			std::cout << get_name() + " :\n{	" << "\n  Name:" << this->get_name() << "\n  Sign:" << this->get_signature() << "\n  owner_klass :" << this->owner_klass << "\n}" << std::endl;
		}
	private:
	};
}
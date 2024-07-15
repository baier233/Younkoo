#pragma once
#include "Env.hpp"
#include "Misc.hpp"
#include "Method.hpp"

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
#ifdef LOG
		std::cout << "Finding Klass :" << klass_name << std::endl;
#endif // LOG
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
		Klass(jobject object_instance = nullptr, bool is_global_ref = false, bool has_super_klass = false) :
			members_type([]() {return get_cached_jclass<Klass>(); }, object_instance, is_global_ref, has_super_klass)
		{
		}

		inline jclass init() {
			clear_cached_jclass<Klass>();

			return get_cached_jclass<Klass>();;
		}

		template<class... method_parameters_type>
		static inline Klass new_object(JNI::ConstructorMethod<method_parameters_type...>members_type::* constructor, jmethodID id, const method_parameters_type&... method_parameters) {
			Klass tmp{};
			return Klass{ JNI::get_env()->NewObject(get_cached_jclass<Klass>(),id , std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...) };
		}

		template<class... method_parameters_type>
		static inline Klass new_object(JNI::ConstructorMethod<method_parameters_type...>members_type::* constructor, const method_parameters_type&... method_parameters) {
			Klass tmp{};
			JNI::ConstructorMethod<method_parameters_type...> c = (tmp.*constructor);
			auto id = c.get_id();
			if (!id)
			{
				c.init();
				id = c.get_id();
			}
			return Klass{ JNI::get_env()->NewObject(get_cached_jclass<Klass>(),id , std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...) };
		}

		static inline std::string get_name()
		{
			return get_class_name_lambda()();
		}

		static inline std::string get_signature()
		{
			return "L" + get_name() + ";";
		}
		inline void print() {
			std::cout << get_name() + " :\n{	" << "\n  Name:" << this->get_name() << "\n  Sign:" << this->get_signature() << "\n  owner_klass :" << this->owner_klass << "\n}" << std::endl;
		}
	private:
	};
}
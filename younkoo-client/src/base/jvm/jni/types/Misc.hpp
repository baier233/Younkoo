#pragma once
#include <string>
#include <functional>
#include <type_traits>
#include <jni/jni.h>
#include <shared_mutex> 
#include <iostream>

#define LOG
namespace JNI {


	template<size_t N>
	struct string_litteral
	{
		constexpr string_litteral(const char(&str)[N])
		{
			std::copy_n(str, N, value);
		}
		constexpr operator const char* () const
		{
			return value;
		}
		constexpr operator std::string_view() const
		{
			return value;
		}
		char value[N];
	};

	template<string_litteral strs>
	struct lambda_container
	{
	private:
		std::function<std::string()> m_lambda;
	public:
		std::string name() { return m_lambda(); }
	};

	template<typename T, typename... U> inline constexpr bool is_any_of_type = (std::is_same_v<T, U> || ...);
	template<typename T> inline constexpr bool is_jni_primitive_type = is_any_of_type<T, jboolean, jbyte, jchar, jshort, jint, jfloat, jlong, jdouble>;

	enum is_static_t : bool
	{
		STATIC = true,
		NOT_STATIC = false
	};

	template<class klass_type>
	struct class_name_cache {
		static std::string value;
		static std::shared_mutex mutex;
	};

	template<class klass_type>
	std::string class_name_cache<klass_type>::value;

	template<class klass_type>
	std::shared_mutex class_name_cache<klass_type>::mutex;

	template<class klass_type> inline void set_cached_name(const std::string name) {
		{
			std::shared_lock shared_lock{ class_name_cache<klass_type>::mutex };
			class_name_cache<klass_type>::value = name;
			std::cout << "set_cached_name Class type: " << typeid(klass_type).name() << " name: " << name << std::endl;
		}
	}
	template<class klass_type> inline std::string get_cached_name() //findClass
	{
		auto& cached = class_name_cache<klass_type>::value;
		{
			std::shared_lock shared_lock{ class_name_cache<klass_type>::mutex };

			std::cout << "get_cached_name Class type: " << typeid(klass_type).name() << " name: " << cached << std::endl;
			if (cached != "e") return cached;
		}
		auto klassName = klass_type::get_name_from_lambda();

		set_cached_name<klass_type>(klassName);

		return klassName;
	}

	template<class T> inline std::string get_signature_for_type()
	{

		if constexpr (std::is_void_v<T>)
			return std::string("V");
		if constexpr (std::is_same_v<jboolean, T>)
			return std::string("Z");
		if constexpr (std::is_same_v<jbyte, T>)
			return std::string("B");
		if constexpr (std::is_same_v<jchar, T>)
			return std::string("C");
		if constexpr (std::is_same_v<jshort, T>)
			return std::string("S");
		if constexpr (std::is_same_v<jint, T>)
			return std::string("I");
		if constexpr (std::is_same_v<jfloat, T>)
			return std::string("F");
		if constexpr (std::is_same_v<jlong, T>)
			return std::string("J");
		if constexpr (std::is_same_v<jdouble, T>)
			return std::string("D");
		if constexpr (!is_jni_primitive_type<T> && !std::is_void_v<T>)
			return T::get_signature();
		return std::string("");
	}



}
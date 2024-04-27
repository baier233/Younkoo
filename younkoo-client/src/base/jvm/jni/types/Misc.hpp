#pragma once
#include <string>
#include <type_traits>
#include <jni/jni.h>

namespace JNI {

	template<typename T, typename... U> inline constexpr bool is_any_of_type = (std::is_same_v<T, U> || ...);
	template<typename T> inline constexpr bool is_jni_primitive_type = is_any_of_type<T, jboolean, jbyte, jchar, jshort, jint, jfloat, jlong, jdouble>;

	enum is_static_t : bool
	{
		STATIC = true,
		NOT_STATIC = false
	};


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
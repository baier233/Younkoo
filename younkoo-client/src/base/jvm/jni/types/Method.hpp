#pragma once
#include "Env.hpp"

namespace JNI {
	template<typename method_return_type, class... method_parameters_type>
	class method
	{
	public:
		method(std::string method_name,bool isStatic ,const empty_members& m) :
			method_name(method_name),
			is_static(isStatic),
			owner_klass(m.owner_klass),
			object_instance(m.object_instance)
		{
			if (id) return;
			if (is_static)
				id = get_env()->GetStaticMethodID(owner_klass, get_name(), get_signature());
			if (!is_static)
				id = get_env()->GetMethodID(owner_klass, get_name(), get_signature());
			assertm(id, (const char*)(concat<"failed to find methodID: ", get_name(), " ", get_signature()>()));
		}

		auto operator()(const method_parameters_type&... method_parameters)
		{
			return call(method_parameters...);
		}

		auto call(const method_parameters_type&... method_parameters)
		{
			if constexpr (std::is_void_v<method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return;
				if (is_static) {
					get_env()->CallStaticVoidMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					get_env()->CallVoidMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				return;
			}

			if constexpr (!is_jni_primitive_type<method_return_type> && !std::is_void_v<method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return method_return_type(nullptr);
				if (is_static) {
					return method_return_type(get_env()->CallStaticObjectMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...));
				}
				else {
					return method_return_type(get_env()->CallObjectMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...));
				}
					
					
			}
			if constexpr (std::is_same_v<jboolean, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jboolean(JNI_FALSE);
				if (is_static) {
					return get_env()->CallStaticBooleanMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallBooleanMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
					
			}
			if constexpr (std::is_same_v<jbyte, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jbyte(0);
				if (is_static) {
					return get_env()->CallStaticByteMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallByteMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
					
			}
			if constexpr (std::is_same_v<jchar, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jchar(0);
				if (is_static) {
					return get_env()->CallStaticCharMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallCharMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
			}
			if constexpr (std::is_same_v<jshort, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jshort(0);
				if (is_static) {
					return get_env()->CallStaticShortMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallShortMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jint, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jint(0);
				if (is_static) {
					return get_env()->CallStaticIntMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallIntMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jfloat, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jfloat(0.f);
				if (is_static) {
					return get_env()->CallStaticFloatMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallFloatMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jlong, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jlong(0LL);
				if (is_static) {
					return get_env()->CallStaticLongMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallLongMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
			}
			if constexpr (std::is_same_v<jdouble, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jdouble(0.0);
				if (is_static)
					return get_env()->CallStaticDoubleMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				if (!is_static)
					return get_env()->CallDoubleMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
			}
		}


		operator jmethodID() const
		{
			return id;
		}

		std::string get_name()
		{
			return method_name;
		}

		std::string get_signature()
		{
			return "("+  get_signature_for_type<method_parameters_type>() + ")" + get_signature_for_type<method_return_type>();
		}

		bool is_method_static()
		{
			return is_static;
		}

	private:
		jclass owner_klass;
		jobject object_instance;
		jmethodID id;
		std::string method_name;
		bool is_static;
	};

}
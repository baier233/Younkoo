#pragma once
#include "Env.hpp"
#include "Misc.hpp"
#include <iostream>
#include "ObjectWrapper.hpp"

namespace JNI {
	template<typename method_return_type, is_static_t is_static = NOT_STATIC, class... method_parameters_type>
	class Method
	{
	public:
		Method(std::string method_name,const EmptyMembers& m) :
			owner_klass(m.owner_klass),
			object_instance(m.object_instance)
		{
			if (id) return;
			this->method_name = method_name;
			auto method_sign = get_signature();
			std::cout << "Getting Method : " << method_name + " " + method_sign << " isStatic :" << is_static << std::endl;
			if constexpr (is_static)
				id = get_env()->GetStaticMethodID(owner_klass, method_name.c_str(), method_sign.c_str());
			if constexpr (!is_static)
				id = get_env()->GetMethodID(owner_klass, method_name.c_str(), method_sign.c_str());
			assertm(id, (const char*)("failed to find MethodID : " +  get_name() + " " + get_signature() ).c_str());
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
				if constexpr (is_static) {
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
				if constexpr (is_static) {
					return method_return_type(get_env()->CallStaticObjectMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...));
				}
				else {
					return method_return_type(get_env()->CallObjectMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...));
				}
					
					
			}
			if constexpr (std::is_same_v<jboolean, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jboolean(JNI_FALSE);
				if constexpr (is_static) {
					return get_env()->CallStaticBooleanMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallBooleanMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
					
			}
			if constexpr (std::is_same_v<jbyte, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jbyte(0);
				if constexpr (is_static) {
					return get_env()->CallStaticByteMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallByteMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
					
			}
			if constexpr (std::is_same_v<jchar, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jchar(0);
				if constexpr (is_static) {
					return get_env()->CallStaticCharMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallCharMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
			}
			if constexpr (std::is_same_v<jshort, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jshort(0);
				if constexpr (is_static) {
					return get_env()->CallStaticShortMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallShortMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jint, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jint(0);
				if constexpr (is_static) {
					return get_env()->CallStaticIntMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallIntMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jfloat, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jfloat(0.f);
				if constexpr (is_static) {
					return get_env()->CallStaticFloatMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallFloatMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
			}
			if constexpr (std::is_same_v<jlong, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jlong(0LL);
				if constexpr (is_static) {
					return get_env()->CallStaticLongMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
				else {
					return get_env()->CallLongMethod(object_instance, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				}
					
			}
			if constexpr (std::is_same_v<jdouble, method_return_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jdouble(0.0);
				if constexpr (is_static)
					return get_env()->CallStaticDoubleMethod(owner_klass, id, std::conditional_t<is_jni_primitive_type<method_parameters_type>, method_parameters_type, jobject>(method_parameters)...);
				if constexpr (!is_static)
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

		inline static std::string get_signature()
		{
			return std::string("(") + (get_signature_for_type<method_parameters_type>() + ... + ")") + get_signature_for_type<method_return_type>();
		}

		void print() {
			std::cout << this->get_name() <<" :\n{" << "\n   Name: " << this->get_name() << "\n   Sign:" << this->get_signature() << "\n   ID :" << this->id << "\n}" << std::endl;
		}

		bool is_method_static()
		{
			return is_static;
		}

		private:
			jclass owner_klass;
			jobject object_instance;
			static inline jmethodID id = nullptr;
			std::string method_name;
		};

}
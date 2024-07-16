#pragma once

#include "Env.hpp"
#include "ObjectWrapper.hpp"
#include <functional>
#include <iostream>

namespace JNI {
	template<typename field_type, is_static_t is_static = NOT_STATIC, typename field_name_lambda = decltype([] {return ""; }) >
	class Field
	{
	public:
		Field(const EmptyMembers& m) :
			owner_klass(m.owner_klass),
			object_instance(m.object_instance)
		{
			if (id) return;
			field_name = field_name_lambda()();
#ifdef LOG
			std::cout << "Getting Field : " << get_name() + " " + get_signature() << " isStatic :" << is_static << " type:" << typeid(*this).name() << std::endl;
#endif // LOG
			if constexpr (is_static)
				id = get_env()->GetStaticFieldID(owner_klass, get_name().c_str(), get_signature().c_str());
			if constexpr (!is_static)
				id = get_env()->GetFieldID(owner_klass, get_name().c_str(), get_signature().c_str());
			assertm(id, "failed to find FieldID ");
		}

		Field(std::string field_name, const EmptyMembers& m) :
			field_name(field_name),
			owner_klass(m.owner_klass),
			object_instance(m.object_instance)
		{
			if (id) return;
			init();
		}

		Field& operator=(const field_type& new_value)
		{
			set(new_value);
			return *this;
		}
		void init() {
			field_name = field_name_lambda()();
#ifdef LOG
			std::cout << "Getting Field : " << get_name() + " " + get_signature() << " isStatic :" << is_static << " type:" << typeid(*this).name() << std::endl;
#endif // LOG
			if constexpr (is_static)
				id = get_env()->GetStaticFieldID(owner_klass, get_name().c_str(), get_signature().c_str());
			if constexpr (!is_static)
				id = get_env()->GetFieldID(owner_klass, get_name().c_str(), get_signature().c_str());
			assertm(id, "failed to find FieldID ");
		}
		void set(const field_type& new_value)
		{
			if (!id)
			{
				init();
			}
			if (!id || !owner_klass || (!is_static && !object_instance)) return;
			if constexpr (!is_jni_primitive_type<field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticObjectField(owner_klass, id, (jobject)new_value);
				if constexpr (!is_static)
					return get_env()->SetObjectField(object_instance, id, (jobject)new_value);
			}
			if constexpr (std::is_same_v<jboolean, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticBooleanField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetBooleanField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jbyte, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticByteField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetByteField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jchar, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticCharField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetCharField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jshort, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticShortField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetShortField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jint, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticIntField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetIntField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jfloat, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticFloatField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetFloatField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jlong, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticLongField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetLongField(object_instance, id, new_value);
			}
			if constexpr (std::is_same_v<jdouble, field_type>)
			{
				if constexpr (is_static)
					return get_env()->SetStaticDoubleField(owner_klass, id, new_value);
				if constexpr (!is_static)
					return get_env()->SetDoubleField(object_instance, id, new_value);
			}
		}

		auto get() //usable only if Field is not static (requires an instance of the owner class
		{
			if (!id)
			{
				init();
			}
			if constexpr (!is_jni_primitive_type<field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return field_type(nullptr);
				if constexpr (is_static)
					return field_type(get_env()->GetStaticObjectField(owner_klass, id));
				if constexpr (!is_static)
					return field_type(get_env()->GetObjectField(object_instance, id));
			}
			if constexpr (std::is_same_v<jboolean, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jboolean(JNI_FALSE);
				if constexpr (is_static)
					return get_env()->GetStaticBooleanField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetBooleanField(object_instance, id);
			}
			if constexpr (std::is_same_v<jbyte, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jbyte(0);
				if constexpr (is_static)
					return get_env()->GetStaticByteField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetByteField(object_instance, id);
			}
			if constexpr (std::is_same_v<jchar, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jchar(0);
				if constexpr (is_static)
					return get_env()->GetStaticCharField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetCharField(object_instance, id);
			}
			if constexpr (std::is_same_v<jshort, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jshort(0);
				if constexpr (is_static)
					return get_env()->GetStaticShortField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetShortField(object_instance, id);
			}
			if constexpr (std::is_same_v<jint, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jint(0);
				if constexpr (is_static)
					return get_env()->GetStaticIntField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetIntField(object_instance, id);
			}
			if constexpr (std::is_same_v<jfloat, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jfloat(0.f);
				if constexpr (is_static)
					return get_env()->GetStaticFloatField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetFloatField(object_instance, id);
			}
			if constexpr (std::is_same_v<jlong, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jlong(0LL);
				if constexpr (is_static)
					return get_env()->GetStaticLongField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetLongField(object_instance, id);
			}
			if constexpr (std::is_same_v<jdouble, field_type>)
			{
				if (!id || !owner_klass || (!is_static && !object_instance)) return jdouble(0.0);
				if constexpr (is_static)
					return get_env()->GetStaticDoubleField(owner_klass, id);
				if constexpr (!is_static)
					return get_env()->GetDoubleField(object_instance, id);
			}
		}

		static inline auto get_name()
		{
			return field_name;
		}

		static inline auto get_signature()
		{
			return get_signature_for_type<field_type>();
		}

		bool is_field_static()
		{
			return is_static;
		}

		void print() {
			std::cout << this->get_name() << " :\n{" << "\n   Name: " << this->get_name() << "\n   Sign:" << this->get_signature() << "\n   Value :" << this->get() << "\n}" << std::endl;
		}


		operator jfieldID() const
		{
			return id;
		}
	private:
		jclass owner_klass = nullptr;
		jobject object_instance = nullptr;
		inline static jfieldID id = nullptr;
		inline static std::string field_name;
	};


}
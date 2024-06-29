#pragma once
#include "Env.hpp"
#include "ObjectWrapper.hpp"

namespace JNI {

	template<class array_element_type>
	class Array : public ObjectWrapper
	{
	public:
		Array(jobject object_instance, bool is_global_ref = false) :
			ObjectWrapper(object_instance, is_global_ref)
		{
		}

		std::vector<array_element_type> to_vector()
		{
			jsize length = get_length();
			std::vector<array_element_type> vector{};
			vector.reserve(length);
			if constexpr (!is_jni_primitive_type<array_element_type>)
			{
				for (jsize i = 0; i < length; ++i)
					vector.push_back(array_element_type(get_env()->GetObjectArrayElement((jobjectArray)object_instance, i)));
			}
			if constexpr (std::is_same_v<jboolean, array_element_type>)
			{
				std::unique_ptr<jboolean[]> buffer = std::make_unique<jboolean[]>(length);
				get_env()->GetBooleanArrayRegion((jbooleanArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jbyte, array_element_type>)
			{
				std::unique_ptr<jbyte[]> buffer = std::make_unique<jbyte[]>(length);
				get_env()->GetByteArrayRegion((jbyteArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jchar, array_element_type>)
			{
				std::unique_ptr<jchar[]> buffer = std::make_unique<jchar[]>(length);
				get_env()->GetCharArrayRegion((jcharArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jshort, array_element_type>)
			{
				std::unique_ptr<jshort[]> buffer = std::make_unique<jshort[]>(length);
				get_env()->GetShortArrayRegion((jshortArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jint, array_element_type>)
			{
				std::unique_ptr<jint[]> buffer = std::make_unique<jint[]>(length);
				get_env()->GetIntArrayRegion((jintArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jfloat, array_element_type>)
			{
				std::unique_ptr<jfloat[]> buffer = std::make_unique<jfloat[]>(length);
				get_env()->GetFloatArrayRegion((jfloatArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jlong, array_element_type>)
			{
				std::unique_ptr<jlong[]> buffer = std::make_unique<jlong[]>(length);
				get_env()->GetLongArrayRegion((jlongArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			if constexpr (std::is_same_v<jdouble, array_element_type>)
			{
				std::unique_ptr<jdouble[]> buffer = std::make_unique<jdouble[]>(length);
				get_env()->GetDoubleArrayRegion((jdoubleArray)object_instance, 0, length, buffer.get());
				vector.insert(vector.begin(), buffer.get(), buffer.get() + length);
			}
			return vector;
		}

		jsize get_length()
		{
			return get_env()->GetArrayLength((jarray)object_instance);
		}

		static inline std::string get_signature()
		{
			return "[" + get_signature_for_type<array_element_type>();
		}

		static inline std::string get_name() //this is used for FindClass
		{
			return get_signature();
		}

		static Array create(const std::vector<array_element_type>& values)
		{
			jobject object = nullptr;
			if constexpr (!is_jni_primitive_type<array_element_type>)
			{
				object = get_env()->NewObjectArray((jsize)values.size(), get_cached_jclass<array_element_type>(), nullptr);
				for (jsize i = 0; i < values.size(); ++i)
					get_env()->SetObjectArrayElement((jobjectArray)object, i, (jobject)values[i]);
			}
			if constexpr (std::is_same_v<jboolean, array_element_type>)
			{
				object = get_env()->NewBooleanArray((jsize)values.size());
				get_env()->SetBooleanArrayRegion((jbooleanArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jbyte, array_element_type>)
			{
				object = get_env()->NewByteArray((jsize)values.size());
				get_env()->SetByteArrayRegion((jbyteArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jchar, array_element_type>)
			{
				object = get_env()->NewCharArray((jsize)values.size());
				get_env()->SetCharArrayRegion((jcharArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jshort, array_element_type>)
			{
				object = get_env()->NewShortArray((jsize)values.size());
				get_env()->SetShortArrayRegion((jshortArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jint, array_element_type>)
			{
				object = get_env()->NewIntArray((jsize)values.size());
				get_env()->SetIntArrayRegion((jintArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jfloat, array_element_type>)
			{
				object = get_env()->NewFloatArray((jsize)values.size());
				get_env()->SetFloatArrayRegion((jfloatArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jlong, array_element_type>)
			{
				object = get_env()->NewLongArray((jsize)values.size());
				get_env()->SetLongArrayRegion((jlongArray)object, 0, (jsize)values.size(), values.data());
			}
			if constexpr (std::is_same_v<jdouble, array_element_type>)
			{
				object = get_env()->NewDoubleArray((jsize)values.size());
				get_env()->SetDoubleArrayRegion((jdoubleArray)object, 0, (jsize)values.size(), values.data());
			}
			return Array(object);
		}
	};
}
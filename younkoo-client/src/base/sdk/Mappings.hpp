#pragma once
#include "../jvm/jni/Wrapper.hpp"
#include <map>


inline std::map<std::string, std::string> ClassNameMap;
inline std::map<std::string, std::string> MethodNameMap;
inline std::map<std::string, std::string> FieldNameMap;
namespace maps
{
		BEGIN_KLASS_DEF(Object, "java/lang/Object")
		END_KLASS_DEF()

		BEGIN_KLASS_DEF(String, "java/lang/String")
		String create(const char* str)
		{
			return String(JNI::get_env()->NewStringUTF(str));
		}

		std::string to_string()
		{
			jstring str_obj = (jstring)(jobject)object_instance;
			jsize utf8_size = JNI::get_env()->GetStringUTFLength(str_obj);
			jsize size = JNI::get_env()->GetStringLength(str_obj);

			std::string str(utf8_size, '\0');
			JNI::get_env()->GetStringUTFRegion(str_obj, 0, size, str.data());
			return str;
		}
		END_KLASS_DEF()

		BEGIN_KLASS_DEF(Collection, "java/util/Collection")
			JNI::Method<JNI::Array<Object>> toArray{ "toArray" ,*this };
		END_KLASS_DEF()

		BEGIN_KLASS_DEF_EX(List, "java/util/List", Collection)
		END_KLASS_DEF()

		BEGIN_KLASS_DEF(Main, "Main")
			JNI::Field<jint,JNI::STATIC> field_0{ "field_0",*this };
		END_KLASS_DEF()
			
		BEGIN_KLASS_DEF(SubClass, "SubClass")
			JNI::Field<jint,JNI::NOT_STATIC> field_1{ "field_1",*this };
			JNI::Method<SubClass,JNI::STATIC> getInstance{"getInstance",*this};
		END_KLASS_DEF()

}
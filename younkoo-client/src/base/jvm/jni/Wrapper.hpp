#pragma once
#include "types/Array.hpp"
#include "types/Field.hpp"
#include "types/ObjectWrapper.hpp"
#include "types/Method.hpp"
#include "types/Klass.hpp"'
#include "types/Env.hpp"
#include "types/Misc.hpp"'
#include <map>
#include <string>
#include <functional>



#define BEGIN_KLASS_DEF(unobf_klass_name, obf_klass_name)													\
	struct unobf_klass_name##_members;																		\
	using unobf_klass_name = JNI::Klass<unobf_klass_name##_members>;						\
	struct unobf_klass_name##_members : public JNI::EmptyMembers											\
	{																										\
		unobf_klass_name##_members( std::function<jclass()> lambda_get_klass,jobject object_instance, bool is_global_ref,std::function<std::string()> lambda_get_name =[](){obf_klass_name;} ) :		\
			JNI::EmptyMembers(lambda_get_klass, object_instance, is_global_ref, lambda_get_name)									\
		{																									\
		}																									\

#define END_KLASS_DEF()	}

#define BEGIN_KLASS_DEF_EX(unobf_klass_name, obf_klass_name, inherit_from)									\
	struct unobf_klass_name##_members;																		\
	using unobf_klass_name = JNI::Klass< unobf_klass_name##_members>;						\
	struct unobf_klass_name##_members : public inherit_from##_members										\
	{																										\
		unobf_klass_name##_members(std::function<jclass()> lambda_get_klass,jobject object_instance, bool is_global_ref, std::function<std::string()> lambda_get_name =[](){obf_klass_name;}) :		\
			inherit_from##_members(lambda_get_klass,object_instance, is_global_ref, lambda_get_name)								\
		{																									\
		}																									\


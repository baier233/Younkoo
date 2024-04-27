#pragma once
#include "types/Array.hpp"
#include "types/Field.hpp"
#include "types/ObjectWrapper.hpp"
#include "types/Method.hpp"
#include "types/Klass.hpp"'
#include "types/Env.hpp"
#include "types/Misc.hpp"'

#define BEGIN_KLASS_DEF(unobf_klass_name, obf_klass_name)													\
	struct unobf_klass_name##_members;																		\
	using unobf_klass_name = JNI::Klass<unobf_klass_name##_members>;						\
	struct unobf_klass_name##_members : public JNI::EmptyMembers											\
	{																										\
		unobf_klass_name##_members(jclass owner_klass, jobject object_instance, bool is_global_ref) :		\
			JNI::EmptyMembers(owner_klass, object_instance, is_global_ref)									\
		{																									\
	}																									\
		std::string get_class_name() override\
		{																										\
			return obf_klass_name;																										\
		}																										\

#define END_KLASS_DEF()	};

#define BEGIN_KLASS_DEF_EX(unobf_klass_name, obf_klass_name, inherit_from)									\
	struct unobf_klass_name##_members;																		\
	using unobf_klass_name = JNI::Klass< unobf_klass_name##_members>;						\
	struct unobf_klass_name##_members : public inherit_from##_members										\
	{																										\
		unobf_klass_name##_members(jclass owner_klass, jobject object_instance, bool is_global_ref) :		\
			inherit_from##_members(owner_klass, object_instance, is_global_ref)								\
		{																									\
		}																									\
		std::string get_class_name() override\
		{																										\
			return obf_klass_name;																										\
		}		


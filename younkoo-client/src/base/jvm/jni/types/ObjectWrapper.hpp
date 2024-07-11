#pragma once
#include "Env.hpp"
#include "Misc.hpp"
#include <functional>
#include <iostream>

namespace JNI {


	class ObjectWrapper
	{
	public:
		ObjectWrapper(jobject object_instance, bool is_global_ref) :
			object_instance((is_global_ref&& object_instance ? get_env()->NewGlobalRef(object_instance) : object_instance)),
			is_global_ref(is_global_ref)
		{
		}

		ObjectWrapper(const ObjectWrapper& other) :
			ObjectWrapper(other.object_instance, other.is_global_ref)
		{
		}

		~ObjectWrapper()
		{
			if (is_global_ref)
				clear_ref();
		}

		bool is_same_object(const ObjectWrapper& other) const
		{
			return get_env()->IsSameObject(object_instance, other.object_instance) == JNI_TRUE;
		}

		template<typename klass_type>
		bool is_instance_of() const
		{
			return get_env()->IsInstanceOf(object_instance, get_cached_jclass<klass_type>()) == JNI_TRUE;
		}

		ObjectWrapper& operator=(const ObjectWrapper& other) //operator = keeps the current ref type
		{
			if (is_global_ref)
			{
				clear_ref();
				object_instance = get_env()->NewGlobalRef(other.object_instance);
			}
			else
				object_instance = other.object_instance;
			return *this;
		}

		ObjectWrapper& operator=(jobject other) //operator = keeps the current ref type
		{
			if (is_global_ref)
			{
				clear_ref();
				object_instance = get_env()->NewGlobalRef(other);
			}
			else
				object_instance = other;
			return *this;
		}

		void clear_ref()
		{
			if (!object_instance) return;
			if (is_global_ref)
				get_env()->DeleteGlobalRef(object_instance);
			object_instance = nullptr;
		}

		operator jobject() const
		{
			return this->object_instance;
		}

		bool is_global() const
		{
			return is_global_ref;
		}

		jobject object_instance;
	private:
		bool is_global_ref; //global refs aren't destroyed on PopLocalFrame, and can be shared between threads
	};
	struct EmptyMembers : public ObjectWrapper
	{
		EmptyMembers(std::function<jclass()> lambda_get_klass, jobject object_instance, bool is_global_ref, bool has_super_klass = false) :
			ObjectWrapper(object_instance, is_global_ref)
		{
			if (!has_super_klass)
			{
				this->owner_klass = lambda_get_klass();
			}
		}

		jclass owner_klass = nullptr;
	};
}
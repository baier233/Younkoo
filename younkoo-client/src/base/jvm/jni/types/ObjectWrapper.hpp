#pragma once
#include "JNI.hpp"
#include "Misc.hpp"

namespace JNI {

	class object_wrapper
	{
	public:
		object_wrapper(jobject object_instance, bool is_global_ref) :
			object_instance((is_global_ref&& object_instance ? get_env()->NewGlobalRef(object_instance) : object_instance)),
			is_global_ref(is_global_ref)
		{
		}

		object_wrapper(const object_wrapper& other) :
			object_wrapper(other.object_instance, other.is_global_ref)
		{
		}

		~object_wrapper()
		{
			if (is_global_ref)
				clear_ref();
		}

		object_wrapper& operator=(const object_wrapper& other) //operator = keeps the current ref type
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

	struct empty_members : public object_wrapper
	{
		empty_members(jclass owner_klass, jobject object_instance, bool is_global_ref) :
			object_wrapper(object_instance, is_global_ref),
			owner_klass(owner_klass)
		{
		}

		jclass owner_klass;
	};
}
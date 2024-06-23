#pragma once
#include "Env.hpp"
#include "Misc.hpp"
#include <functional>
#include <iostream>
#include "Klass.hpp"

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
		EmptyMembers(std::function<jclass(const std::string&)> lambda_get_klass, jobject object_instance, bool is_global_ref, std::function<std::string()> lambda_get_name) :
			ObjectWrapper(object_instance, is_global_ref)
		{
			this->lambda_get_name = lambda_get_name;
			this->owner_klass = lambda_get_klass(get_class_name());
		}
		static inline std::string get_class_name() {
			return lambda_get_name();
		}
		static inline std::function <std::string()> lambda_get_name;
		jclass owner_klass;
	};
}
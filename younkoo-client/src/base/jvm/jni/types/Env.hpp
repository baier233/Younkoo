#pragma once

#include <Windows.h>
#include <jni/jni.h>
#include <string>
#include <type_traits>
#include <cassert>
#include <memory>
#include <vector>
#include <shared_mutex>

#include "Misc.hpp"


#define assertm(exp, msg) assert(((void)msg, exp))

namespace JNI
{
	inline uint32_t _tls_index = 0;
	inline std::vector<jobject> _refs_to_delete{};
	inline std::mutex _refs_to_delete_mutex{};
	inline jobject class_loader{};

	inline JNIEnv* get_env()
	{
		return (JNIEnv*)TlsGetValue(_tls_index);
	}
	inline void set_thread_env(JNIEnv* new_env)
	{
		if (get_env()) return;
		TlsSetValue(_tls_index, new_env);
	}

	inline jclass find_class(std::string class_name) {
		if (class_loader)
		{
			static jclass classloder_class = get_env()->FindClass("java/lang/ClassLoader");
			static auto mid_findClass = get_env()->GetMethodID(classloder_class, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
			auto modify_class_name = class_name;
			size_t pos = modify_class_name.find("/");
			while (pos != std::string::npos) {
				modify_class_name.replace(pos, 1, ".");
				pos = modify_class_name.find("/", pos + 1);
			}
			auto klass_name = get_env()->NewStringUTF(modify_class_name.c_str());
			auto klass = (jclass)get_env()->CallObjectMethod(class_loader, mid_findClass, klass_name);
			get_env()->DeleteLocalRef(klass_name);
			if (klass) {
				return klass;
			}
		}
		return get_env()->FindClass(class_name.c_str());
	}

	inline void set_class_loader(jobject custom_loader) {
		class_loader = custom_loader;
	}

	inline void init()
	{
		if (_tls_index) return;
		_tls_index = TlsAlloc();
		assertm(_tls_index, "tls index allocation failed");
	}
	inline void shutdown() //needs to be called on exit, library unusable after this
	{
		{
			std::lock_guard lock{ _refs_to_delete_mutex }; //shouldn't be necessary, every jni calls should be stopped before calling jni::destroy_cache
			for (jobject object : _refs_to_delete)
			{
				if (!object) continue;
				get_env()->DeleteGlobalRef(object);
			}
		}
		TlsFree(_tls_index);
	}
}
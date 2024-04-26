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

	inline JNIEnv* get_env()
	{
		return (JNIEnv*)TlsGetValue(_tls_index);
	}
	inline void set_thread_env(JNIEnv* new_env)
	{
		if (get_env()) return;
		TlsSetValue(_tls_index, new_env);
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
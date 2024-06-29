#pragma once
#include "include_header.h"
#include "utility/jvm_internal.h"
#include "break/jvm_break_points.h"
#include "utility/vm_helper.h"
#include "classes/method.h"
#include "classes/java_thread.h"
#include "classes/klass.h"
#include "classes/const_pool.h"


namespace JavaHook {
	namespace JVM {
		bool Init(JNIEnv* env);
		bool clean();
	}
	class hook_callback_info
	{
	public:
		hook_callback_info(java_hotspot::method* hooked_method, java_hotspot::java_thread* thread, uintptr_t locals) : method(hooked_method), locals(locals), thread(thread) {}

		hook_callback_info(break_point_info* info);
		~hook_callback_info();

		jobject get_locals_jobject_at(const size_t local_index) const {
			return reinterpret_cast<jobject>(reinterpret_cast<uint8_t*>(this->locals) + local_index * sizeof(uint8_t*));
		}
		template<typename T>
		T get_locals_object_at(const size_t local_index) {
			const auto address = reinterpret_cast<uint8_t*>(this->locals);
			return *reinterpret_cast<T*>(address - local_index * sizeof(uint8_t*));
		}

		template<typename T>
		T* get_locals_pobject_at(const size_t local_index) {
			const auto address = reinterpret_cast<uint8_t*>(this->locals);
			return reinterpret_cast<T*>(address - local_index * sizeof(uint8_t*));
		}
		java_hotspot::method* method;
		java_hotspot::java_thread* thread;
	private:
		uintptr_t locals;
	};
	class MethodHook;
	class hook_callbak_info;



	using hook_callback_t = std::function<void(JavaHook::hook_callback_info*)>;

	class MethodHook {
	public:
		MethodHook();
		MethodHook(const jmethodID method, hook_callback_t detour);
		~MethodHook();
		static auto breakpoint_callback_handler(break_point_info* info) -> void {
			auto hook_info = std::make_shared<hook_callback_info>(info);
			hook_map[info->method]->detour(hook_info.get());
		}
		void RemoveHook();
		void SetHook();
		void InitHook(const jmethodID method, hook_callback_t detour);

	private:
		static inline std::unordered_map<java_hotspot::method*, MethodHook*> hook_map;
		java_hotspot::method* target_method;
		hook_callback_t detour;
		bool isHooked;
	};


	inline hook_callback_info::hook_callback_info(break_point_info* info) : hook_callback_info(info->method, info->java_thread, info->parameters)
	{

	}

	inline hook_callback_info::~hook_callback_info()
	{
		this->method = 0;
		this->locals = 0;
	}
}

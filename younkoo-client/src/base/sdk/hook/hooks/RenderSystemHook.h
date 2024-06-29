#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/client/renderer/ClientRenderer.h>
#include <JVM.hpp>
#include  <hotspot/wrapper.h>
namespace RenderSystemHook {
	inline JavaHook::MethodHook RENDER_SYSTEM_HOOK;
	inline void applyHook() {
		jclass klass = JNI::find_class(V1_18_1::GameRenderer::get_name());
		JVM::get().jvmti->RetransformClasses(1, &klass);
		JavaHook::JVM::Init(JNI::get_env());
		V1_18_1::GameRenderer::static_obj();//find class,field,etc.
		RENDER_SYSTEM_HOOK.InitHook((jmethodID)V1_18_1::GameRenderer::static_obj().renderLevel, [](JavaHook::hook_callback_info* callback) {

			//std::cout << "Hooked " << std::endl;
			});
		RENDER_SYSTEM_HOOK.SetHook();
	}

}
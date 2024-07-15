#pragma once
#include <JVM.hpp>
#include <SDK.hpp>
#include <hotspot/java_hook.h>
#include <hotspot/break/byte_code_info.h>
namespace HookUtils {

	inline void GenericResolve(java_hotspot::method* method) {
		method->set_dont_inline(true);
		const auto access_flags = method->get_access_flags();
		access_flags->set_not_c1_compilable();
		access_flags->set_not_c2_compilable();
		access_flags->set_not_c2_osr_compilable();
		access_flags->set_queued_for_compilation();
	}
}
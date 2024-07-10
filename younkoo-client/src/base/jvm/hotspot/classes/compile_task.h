#pragma once
#include "../include_header.h"
#include "../utility/jvm_internal.h"
#include "c_method.h"

namespace java_hotspot {
	class compile_task
	{
	public:
		auto get_method() -> method*;
	};
}

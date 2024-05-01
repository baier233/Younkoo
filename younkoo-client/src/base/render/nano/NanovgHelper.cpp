#include "NanovgHelper.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg_gl.h>

bool NanoVGHelper::InitContext()
{
	if (Context) return true;
	Context = nvgCreateGL3(NVG_ANTIALIAS);
	return Context != nullptr;
}

bool NanoVGHelper::DeleteContext()
{
	nvgDeleteGL3(Context);
	Context = nullptr;
	return true;
}

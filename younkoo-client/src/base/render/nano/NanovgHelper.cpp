#include "NanovgHelper.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define NANOVG_GL2_IMPLEMENTATION
#include <nanovg_gl.h>

bool NanoVGHelper::InitContext()
{
	Context = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES );
	return true;
}

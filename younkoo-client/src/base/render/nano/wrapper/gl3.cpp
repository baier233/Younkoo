#include "gl3.h"

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

NVGcontext* gl3::init()
{
	return nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void gl3::clean(NVGcontext* vg)
{
	nvgDeleteGL3(vg);
}


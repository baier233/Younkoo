#include "gl2.h"

#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg_gl.h"

NVGcontext* gl2::init()
{
	return nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

void gl2::clean(NVGcontext* vg)
{
	nvgDeleteGL2(vg);
}

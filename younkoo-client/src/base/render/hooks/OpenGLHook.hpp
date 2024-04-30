#pragma once
#include "../../../utils/Singleton.hpp"
#include "../../../utils/Structs.hpp"

#include "titan_hook.h"


namespace OpenGLHook {
	bool Detour_wglSwapBuffers(_In_ HDC hdc);
	bool Init();
	bool Clean();

}

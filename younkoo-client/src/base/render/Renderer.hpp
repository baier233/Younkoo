#pragma once
#include <Windows.h>


#include "../../utils/Singleton.hpp"
#include "../../utils/Structs.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "nanovg.h"




class Renderer : public Singleton<Renderer>
{
protected:
	DEFAULT_DTOR(Renderer);
	NON_COPYABLE(Renderer);
public:

	Renderer() {
		OriginalGLContext = 0; MenuGLContext = 0; HandleDeviceContext = 0; HandleWindow = 0;
	}

	HGLRC OriginalGLContext = 0;
	HGLRC MenuGLContext = 0;
	HDC HandleDeviceContext = 0;
	HWND HandleWindow = 0;

	bool Init();
	bool Shutdown();
};


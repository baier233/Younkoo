#pragma once
#include <Windows.h>

#include <vector>

#include "../../utils/Singleton.hpp"
#include "../../utils/Structs.hpp"

struct RenderContext
{
	HGLRC OriginalGLContext = 0;
	HGLRC MenuGLContext = 0;
	HDC HandleDeviceContext = 0;
	HWND HandleWindow = 0;
	float devicePixelRatio = 1;
	std::pair<int, int>winSize;
};


class Renderer : public Singleton<Renderer>
{
protected:
	DEFAULT_DTOR(Renderer);
	NON_COPYABLE(Renderer);
public:

	Renderer() {
		renderContext.OriginalGLContext = 0; renderContext.MenuGLContext = 0; renderContext.HandleDeviceContext = 0; renderContext.HandleWindow = 0;
	}

	RenderContext renderContext;


	bool Initialized = 0;

	bool Init();
	bool Shutdown();
};


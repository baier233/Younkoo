#include "Renderer.hpp"
#include "hooks/OpenGLHook.hpp"



bool Renderer::Init()
{
	return OpenGLHook::Init();
}

bool Renderer::Shutdown()
{
	return OpenGLHook::Clean() && wglDeleteContext(renderContext.MenuGLContext);
}

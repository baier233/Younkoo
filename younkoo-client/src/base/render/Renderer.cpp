#include "Renderer.hpp"
#include "hooks/OpenGLHook.hpp"
bool Renderer::Init()
{
	return OpenGLHook::get().Init();
}

bool Renderer::Shutdown()
{
	return OpenGLHook::get().Clean();
}

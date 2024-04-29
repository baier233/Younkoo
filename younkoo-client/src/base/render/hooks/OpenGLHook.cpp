#include "OpenGLHook.hpp"
#include "../Renderer.hpp"
bool OpenGLHook::hook_wglSwapBuffers(_In_ HDC hdc) {
	auto &renderer = Renderer::get();
	renderer.OriginalGLContext = wglGetCurrentContext();
	renderer.HandleDeviceContext = hdc;
	renderer.HandleWindow = WindowFromDC(hdc);

	//glDepthFunc(GL_LEQUAL);
	
	return wglSwapBuffersHook.GetOrignalFunc()(hdc);
}
OpenGLHook::OpenGLHook()
{
	auto gl = GetModuleHandleW(L"opengl32.dll");
	if (!gl)
		gl = GetModuleHandleW(L"opengl64.dll");
	
	if(gl) wglSwapBuffers = (LPVOID)GetProcAddress(gl, "wglSwapBuffers");
}
bool OpenGLHook::Init() const
{
	if (!wglSwapBuffers) return false;
	wglSwapBuffersHook.InitHook(wglSwapBuffers, hook_wglSwapBuffers);
	wglSwapBuffersHook.SetHook();
	return true;
}

bool OpenGLHook::Clean()
{
	wglSwapBuffersHook.RemoveHook();
	return true;
}

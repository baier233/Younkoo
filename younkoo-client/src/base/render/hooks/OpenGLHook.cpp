#include "OpenGLHook.hpp"

#include "../Renderer.hpp"
#include "../nano/NanovgHelper.hpp"


typedef bool(__stdcall* template_wglSwapBuffers) (HDC hdc);
static TitanHook<template_wglSwapBuffers> wglSwapBuffersHook;
static LPVOID wglSwapBuffers{};

#include <tuple>

static auto getWindowSize(const HWND& window) {
	RECT windowRect;
	GetWindowRect(window, &windowRect);
	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;
	return std::make_tuple(windowWidth, windowHeight, windowWidth / windowHeight);
}


#include <mutex>
#include <memory>
#include <GL/glew.h>
#include <nanovg.h>
#include <iostream>

#include "WndProcHook.hpp"


bool OpenGLHook::Detour_wglSwapBuffers(_In_ HDC hdc) {

	auto &renderer = Renderer::get();
	renderer.OriginalGLContext = wglGetCurrentContext();
	renderer.HandleDeviceContext = hdc;
	renderer.HandleWindow = WindowFromDC(hdc);
	
	if(!renderer.Initialized){
		
		// Create My Mirror Context(When I rendering my own stuff,i use this context for not to impact the minecraft gl enviorment)
		renderer.MenuGLContext = wglCreateContext(hdc);
		// Copy Minecraft's opengl context to mine.
		wglCopyContext(renderer.OriginalGLContext, renderer.MenuGLContext,GL_ALL_ATTRIB_BITS); 
		// Change Current Context to my mirror context.
		wglMakeCurrent(hdc, renderer.MenuGLContext);
		// Init Nanovg Context in my mirror context
		NanoVGHelper::InitContext(renderer.HandleWindow);
		// Change it back to Minecraft's opengl context.
		wglMakeCurrent(renderer.HandleDeviceContext, renderer.OriginalGLContext);

		WndProcHook::Init(renderer.HandleWindow);

		renderer.Initialized = true;
	}
	else if(WndProcHook::RESIZED){
		// If Initialized,update my mirror context from minecraft's.
		wglCopyContext(renderer.OriginalGLContext, renderer.MenuGLContext, GL_ALL_ATTRIB_BITS);
	}
	// Change current context back to mine.
	wglMakeCurrent(renderer.HandleDeviceContext, renderer.MenuGLContext);

	
	// Do draw and render here.
	GLint viewport[4]{};
	glGetIntegerv(GL_VIEWPORT, viewport);
	int winWidth = viewport[2];
	int winHeight = viewport[3];

	auto& vg = NanoVGHelper::Context;
	nvgBeginFrame(vg, winWidth, winHeight, /*devicePixelRatio*/ 1.0f);
	nvgSave(vg);


	nvgBeginPath(vg);
	nvgRect(vg, winWidth / static_cast<float>(2) - 50, winHeight / static_cast<float>(2) - 50, 100, 100); // 中心矩形
	nvgFillColor(vg, nvgRGBA(220, 160, 0, 200)); // 颜色填充
	nvgFill(vg);
	nvgClosePath(vg);

	nvgBeginPath(vg);
	nvgFillColor(vg, nvgRGB(255, 255, 255));
	nvgFontFaceId(vg, NanoVGHelper::fontHarmony);
	nvgFontSize(vg, 66.f);
	nvgText(vg, 0, 66, "我爱情染", NULL);
	nvgClosePath(vg);
	nvgRestore(vg);
	nvgEndFrame(vg);

	//End Drawing and Rendering and Dispatch back to minecraft's opengl context
	wglMakeCurrent(renderer.HandleDeviceContext, renderer.OriginalGLContext);
	return wglSwapBuffersHook.GetOrignalFunc()(hdc);
}


bool OpenGLHook::Init() 
{

	// Hook wglswapbuffers here.

	static auto gl = GetModuleHandleW(L"opengl32.dll");

	if (gl) wglSwapBuffers = (LPVOID)GetProcAddress(gl, "wglSwapBuffers");

	if (!wglSwapBuffers) return false;

	wglSwapBuffersHook.InitHook(wglSwapBuffers, Detour_wglSwapBuffers);
	wglSwapBuffersHook.SetHook();
	return true;
}

bool OpenGLHook::Clean()
{

	// Ensure current gl context is orignal minecraft context.
	wglMakeCurrent(Renderer::get().HandleDeviceContext, Renderer::get().OriginalGLContext);

	wglSwapBuffersHook.RemoveHook();
	
	return NanoVGHelper::DeleteContext();
}

#include "OpenGLHook.hpp"

#include "../Renderer.hpp"
#include "../nano/NanovgHelper.hpp"
#include "../../event/Events.h"

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

#include <locale>
#include <codecvt>
#include "../../Younkoo.hpp"


static bool showMenu = false;
#include "../gui/input/Context.hpp"
#include "../gui/GUI.h"

#include "../../../utils/Wnd.h"
bool OpenGLHook::Detour_wglSwapBuffers(_In_ HDC hdc) {
	if (Younkoo::get().shouldShutDown) return wglSwapBuffersHook.GetOrignalFunc()(hdc);
	auto& renderer = Renderer::get();
	renderer.OriginalGLContext = wglGetCurrentContext();
	renderer.HandleDeviceContext = hdc;

	static LONG winWidth = {};
	static LONG winHeight = {};

	static float devicePixelRatio = {};

	if (!renderer.Initialized) {
		GLint viewport[4]{};
		glGetIntegerv(GL_VIEWPORT, viewport);
		context.ScreenWidth = viewport[2];
		context.ScreenHeight = viewport[3];

		renderer.HandleWindow = WindowFromDC(hdc);
		WCHAR className[256];
		GetClassNameW(renderer.HandleWindow, className, sizeof(className) / sizeof(WCHAR));
		wprintf(L"Class Name: %ls\n", className);

		// Create My Mirror Context(When I rendering my own stuff,i use this context for not to impact the minecraft gl enviorment)


		renderer.MenuGLContext = wglCreateContext(hdc);
		// Copy Minecraft's opengl context to mine.
		wglCopyContext(renderer.OriginalGLContext, renderer.MenuGLContext, GL_ALL_ATTRIB_BITS);
		// Change Current Context to my mirror context.
		wglMakeCurrent(hdc, renderer.MenuGLContext);
		devicePixelRatio = Wnd::get_pixel_ratio(renderer.HandleWindow);

		// Init Nanovg Context in my mirror context
		NanoVGHelper::InitContext(renderer.HandleWindow);
		RECT area;
		GetClientRect(renderer.HandleWindow, &area);

		winWidth = area.right;
		winHeight = area.bottom;

		winWidth = static_cast<int>(static_cast<float>(winWidth) / devicePixelRatio);
		winHeight = static_cast<int>(static_cast<float>(winHeight) / devicePixelRatio);

		WndProcHook::Init(renderer.HandleWindow);
		NanoGui::Init(renderer.HandleWindow, hdc, NanoVGHelper::Context);
		// Change it back to Minecraft's opengl context.
		wglMakeCurrent(renderer.HandleDeviceContext, renderer.OriginalGLContext);

		GetClientRect(renderer.HandleWindow, &area);

		winWidth = area.right;
		winHeight = area.bottom;

		winWidth = static_cast<int>(static_cast<float>(winWidth) / devicePixelRatio);
		winHeight = static_cast<int>(static_cast<float>(winHeight) / devicePixelRatio);
		renderer.Initialized = true;
	}
	else if (WndProcHook::RESIZED) {
		renderer.HandleWindow = WindowFromDC(hdc);
		// If Initialized,update my mirror context from minecraft's.
		wglCopyContext(renderer.OriginalGLContext, renderer.MenuGLContext, GL_ALL_ATTRIB_BITS);
	}
	// Change current context back to mine.
	wglMakeCurrent(renderer.HandleDeviceContext, renderer.MenuGLContext);


	// Do draw and render here.


	/*
	*
	GLint dims[4] = { 0 };
	glGetIntegerv(GL_VIEWPORT, dims);
	GLint fbWidth = dims[2];
	GLint fbHeight = dims[3];
	*/

	auto& vg = NanoVGHelper::Context;
	using namespace NanoVGHelper;




	if (context.IsKeyPressed(VK_INSERT, false))
	{
		showMenu = !showMenu;
		NanoGui::available = !NanoGui::available;
	}

	if (NanoGui::available)
	{
		NanoGui::drawGui();
	}
	else {
		NanoGui::drawContents();
	}


	context.EndFrame();
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
	NanoGui::clean();
	return NanoVGHelper::DeleteContext() && WndProcHook::Clean();
}

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
#include "../../../utils/Wstr.h"
bool OpenGLHook::Detour_wglSwapBuffers(_In_ HDC hdc) {
	if (Younkoo::get().shouldShutDown) return wglSwapBuffersHook.GetOrignalFunc()(hdc);
	auto& renderer = Renderer::get();
	renderer.renderContext.OriginalGLContext = wglGetCurrentContext();
	renderer.renderContext.HandleDeviceContext = hdc;

	static LONG winWidth = {};
	static LONG winHeight = {};


	if (!renderer.Initialized) {
		GLint viewport[4]{};
		glGetIntegerv(GL_VIEWPORT, viewport);

		renderer.renderContext.HandleWindow = WindowFromDC(hdc);
		WCHAR className[256];
		GetClassNameW(renderer.renderContext.HandleWindow, className, sizeof(className) / sizeof(WCHAR));
		wprintf(L"Class Name: %ls\n", className);
		renderer.renderContext.ClassName = wstr::toString(className);
		// Create My Mirror Context(When I rendering my own stuff,i use this context for not to impact the minecraft gl enviorment)


		renderer.renderContext.MenuGLContext = wglCreateContext(hdc);
		// Copy Minecraft's opengl context to mine.
		wglCopyContext(renderer.renderContext.OriginalGLContext, renderer.renderContext.MenuGLContext, GL_ALL_ATTRIB_BITS);
		// Change Current Context to my mirror context.
		wglMakeCurrent(hdc, renderer.renderContext.MenuGLContext);
		renderer.renderContext.devicePixelRatio = Wnd::get_pixel_ratio(renderer.renderContext.HandleWindow);

		// Init Nanovg Context in my mirror context
		NanoVGHelper::InitContext(renderer.renderContext.HandleWindow);
		RECT area;
		GetClientRect(renderer.renderContext.HandleWindow, &area);

		winWidth = area.right;
		winHeight = area.bottom;

		winWidth = static_cast<int>(static_cast<float>(winWidth) / renderer.renderContext.devicePixelRatio);
		winHeight = static_cast<int>(static_cast<float>(winHeight) / renderer.renderContext.devicePixelRatio);

		renderer.renderContext.winSize = std::make_pair(winWidth, winHeight);

		WndProcHook::Init(renderer.renderContext.HandleWindow);
		NanoGui::Init(renderer.renderContext.HandleWindow, hdc, NanoVGHelper::Context);
		// Change it back to Minecraft's opengl context.
		wglMakeCurrent(renderer.renderContext.HandleDeviceContext, renderer.renderContext.OriginalGLContext);
		renderer.Initialized = true;
	}
	else if (WndProcHook::RESIZED.load()) {
		renderer.renderContext.HandleWindow = WindowFromDC(hdc);
		// If Initialized,update my mirror context from minecraft's.

		winWidth = static_cast<int>(static_cast<float>(winWidth) / renderer.renderContext.devicePixelRatio);
		winHeight = static_cast<int>(static_cast<float>(winHeight) / renderer.renderContext.devicePixelRatio);

		renderer.renderContext.winSize = std::make_pair(winWidth, winHeight);
		wglCopyContext(renderer.renderContext.OriginalGLContext, renderer.renderContext.MenuGLContext, GL_ALL_ATTRIB_BITS);
		WndProcHook::RESIZED.store(false);
	}
	// Change current context back to mine.
	wglMakeCurrent(renderer.renderContext.HandleDeviceContext, renderer.renderContext.MenuGLContext);


	// Do draw and render here.
	auto& vg = NanoVGHelper::Context;
	using namespace NanoVGHelper;




	if (context.IsKeyPressed(VK_INSERT, false))
	{
		showMenu = !showMenu;
		NanoGui::available = !NanoGui::available;
	}

	if (NanoGui::available.load())
	{
		NanoGui::drawGui();
	}
	else {
		NanoGui::drawContents();
	}


	context.EndFrame();

	//End Drawing and Rendering and Dispatch back to minecraft's opengl context
	wglMakeCurrent(renderer.renderContext.HandleDeviceContext, renderer.renderContext.OriginalGLContext);
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
	wglMakeCurrent(Renderer::get().renderContext.HandleDeviceContext, Renderer::get().renderContext.OriginalGLContext);

	wglSwapBuffersHook.RemoveHook();
	NanoGui::clean();
	return NanoVGHelper::DeleteContext() && WndProcHook::Clean();
}

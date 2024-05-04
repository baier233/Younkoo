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

#include <locale>
#include <codecvt>
#include "../../Younkoo.hpp"



static bool showMenu = false;
#include "../gui/input/Context.hpp"
#include "../gui/GUI.h"
std::unique_ptr<YounkooGui> gui = std::make_unique<YounkooGui>(600, 400);
bool OpenGLHook::Detour_wglSwapBuffers(_In_ HDC hdc) {
	if (Younkoo::get().shouldShutDown) return wglSwapBuffersHook.GetOrignalFunc()(hdc);
	auto& renderer = Renderer::get();
	renderer.OriginalGLContext = wglGetCurrentContext();
	renderer.HandleDeviceContext = hdc;

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
		// Init Nanovg Context in my mirror context
		NanoVGHelper::InitContext(renderer.HandleWindow);
		// Change it back to Minecraft's opengl context.
		wglMakeCurrent(renderer.HandleDeviceContext, renderer.OriginalGLContext);

		WndProcHook::Init(renderer.HandleWindow);

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
	GLint viewport[4]{};
	glGetIntegerv(GL_VIEWPORT, viewport);
	int winWidth = viewport[2];
	int winHeight = viewport[3];
	/*
	*
	GLint dims[4] = { 0 };
	glGetIntegerv(GL_VIEWPORT, dims);
	GLint fbWidth = dims[2];
	GLint fbHeight = dims[3];
	*/

	static auto devicePixelRatio = 1/*(float)fbWidth / (float)winWidth*/;
	auto& vg = NanoVGHelper::Context;
	nvgBeginFrame(vg, winWidth, winHeight, devicePixelRatio);
	nvgSave(vg);

	using namespace NanoVGHelper;
	static std::wstring watermark(L"Younkoo Client");
	static float x = winWidth / static_cast<float>(2), y = 100;
	float bounds[4] = { 0 };
	nvgFontSize(vg, 60);
	nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFontFaceId(vg, NanoVGHelper::fontHarmony);
	nvgTextBoundsW(vg, x, y, watermark, bounds);
	float w = bounds[2] - bounds[0];
	float h = bounds[3] - bounds[1];
	w *= 1.5;
	h *= 1.5;

	nvgBeginPath(vg);
	NVGpaint shadowPaint = nvgBoxGradient(vg, x - w / 2, y - h / 2, w, h, 10, 20, nvgRGBA(0, 0, 0, 128), nvgRGBA(0, 0, 0, 0));
	nvgFillPaint(vg, shadowPaint);
	nvgRect(vg, x - w / 2, y - h / 2, w, h);
	nvgFill(vg);

	nvgBeginPath(vg);
	nvgFillColor(vg, nvgRGBA(255, 255, 255, 190));
	nvgTextW(vg, x + 15, y, watermark);

	if (context.IsKeyPressed(VK_INSERT, false))
	{
		showMenu = !showMenu;
	}

	if (showMenu)
	{
		gui->drawScreen(vg, context.MousePos.x, context.MousePos.y);
	}

	nvgRestore(vg);
	nvgEndFrame(vg);
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

	return NanoVGHelper::DeleteContext() && WndProcHook::Clean();
}

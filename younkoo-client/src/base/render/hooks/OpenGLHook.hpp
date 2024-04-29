#pragma once
#include "../../../utils/Singleton.hpp"
#include "../../../utils/Structs.hpp"

#include "titan_hook.h"
class OpenGLHook : public Singleton<OpenGLHook>
{
protected:
	NON_COPYABLE(OpenGLHook);
	DEFAULT_DTOR(OpenGLHook);
public:
	OpenGLHook();
	static bool hook_wglSwapBuffers(_In_ HDC hdc);
	bool Init() const;
	bool Clean();
private:
	typedef bool(__stdcall* template_wglSwapBuffers) (HDC hdc);
	static inline TitanHook<template_wglSwapBuffers> wglSwapBuffersHook;
	static inline LPVOID wglSwapBuffers{};

};


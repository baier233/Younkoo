/*
	src/screen.cpp -- Top-level widget and interface between NanoGUI and CALLBACK

	A significant redesign of this code was contributed by Christian Schueller.

	NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
	The widget drawing code is based on the NanoVG demo application
	by Mikko Mononen.

	All rights reserved. Use of this source code is governed by a
	BSD-style license that can be found in the LICENSE.txt file.
*/

#include "Screen.h"
#include "Theme.h"
#include "OpenGL.h"
#include "Popup.h"
#include <map>
#include <iostream>





/* Allow enforcing the GL2 implementation of NanoVG */
#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg_gl.h>
#include "../input/Context.hpp"
#include "../input/IOEvents.h"

NAMESPACE_BEGIN(nanogui)

std::map<HWND, Screen*> __nanogui_screens;

#if defined(NANOGUI_GLAD)
static bool gladInitialized = false;
#endif

/* Calculate pixel ratio for hi-dpi devices. */

#include "../input/Context.hpp"
#include "../../../../utils/Wnd.h"
Screen::Screen()
	: Widget(nullptr),
	mCursor(Cursor::Arrow), mBackground(0.3f, 0.3f, 0.32f, 1.f),
	mShutdownGLFWOnDestruct(false), mFullscreen(false) {
}
Screen::Screen(HWND hwnd, HDC hDC, NVGcontext* vg, const std::string& caption, bool resizable,
	bool fullscreen, int colorBits, int alphaBits, int depthBits,
	int stencilBits, int nSamples)
	: Widget(nullptr), mWindow(hwnd),
	mCursor(Cursor::Arrow), mBackground(0.3f, 0.3f, 0.32f, 1.f), mCaption(caption),
	mShutdownGLFWOnDestruct(false), mFullscreen(fullscreen) {
	memset(mCursors, 0, sizeof(HCURSOR) * (int)Cursor::CursorCount);
	mNVGContext = vg;

	initialize(mWindow, true);
}

void Screen::initialize(HWND window, bool shutdownGLFWOnDestruct) {
	mWindow = window;
	mShutdownGLFWOnDestruct = shutdownGLFWOnDestruct;

	mPixelRatio = Wnd::get_pixel_ratio(window);
	setTheme(new Theme(mNVGContext));

	mMousePos = Vector2i::Zero();
	mMouseState = mModifiers = 0;
	mDragActive = false;
	mLastInteraction = glfwGetTime();
	mProcessEvents = true;
	__nanogui_screens[mWindow] = this;
	for (int i = 0; i < (int)Cursor::CursorCount; ++i) {
		mCursors[i] = LoadCursor(NULL, IDC_ARROW + i);
	}

	/* Detect framebuffer properties and set up compatible NanoVG context */
	GLint nStencilBits = 0, nSamples = 0;
	glGetFramebufferAttachmentParameteriv(GL_DRAW_FRAMEBUFFER,
		GL_STENCIL, GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE, &nStencilBits);
	glGetIntegerv(GL_SAMPLES, &nSamples);


	if (mNVGContext == nullptr)
		throw std::runtime_error("Could not initialize NanoVG!");


	/// Fixes retina display-related font rendering issue (#185)
	nvgBeginFrame(mNVGContext, mSize[0], mSize[1], mPixelRatio);
	nvgEndFrame(mNVGContext);
}

Screen::~Screen() {
	for (int i = 0; i < (int)Cursor::CursorCount; ++i) {
		if (mCursors[i])
			DestroyCursor(mCursors[i]);
	}
}

void Screen::setVisible(bool visible) {
	if (mVisible != visible) {
		mVisible = visible;

		if (visible);
		//glfwShowWindow(mGLFWWindow);
		else;
		//glfwHideWindow(mGLFWWindow);
	}
}

void Screen::setCaption(const std::string& caption) {
	if (caption != mCaption) {
		SetWindowTextA(mWindow, caption.c_str());
		mCaption = caption;
	}
}

void Screen::setSize(const Vector2i& size) {
	Widget::setSize(size);

	RECT rect = { 0, 0, size.x() * mPixelRatio, size.y() * mPixelRatio };
	AdjustWindowRect(&rect, GetWindowLong(mWindow, GWL_STYLE), false);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	SetWindowPos(mWindow, HWND_TOP, rect.left, rect.top, width, height, SWP_NOZORDER);

}

void Screen::drawAll() {

	drawContents();
	drawWidgets();

	//glfwSwapBuffers(mGLFWWindow);
}

void Screen::drawWidgets() {
	if (!mVisible)
		return;

	RECT area;
	GetClientRect(mWindow, &area);

	mSize[0] = area.right;
	mSize[1] = area.bottom;


	mFBSize[0] = mSize[0];
	mFBSize[1] = mSize[1];


	mSize = (mSize.cast<float>() / mPixelRatio).cast<int>();
	mFBSize = (mSize.cast<float>() * mPixelRatio).cast<int>();


	glViewport(0, 0, mFBSize[0], mFBSize[1]);
	glBindSampler(0, 0);

	nvgBeginFrame(mNVGContext, mSize[0], mSize[1], mPixelRatio);

	draw(mNVGContext);

	if (mMousePos.x() < 0) {
		mMousePos[0] = 0;
	}
	if (mMousePos.y() < 0)
	{
		mMousePos[1] = 0;
	}
	if (mMousePos.y() > mSize[1])
	{
		mMousePos[1] = 0;
	}
	double elapsed = glfwGetTime() - mLastInteraction;

	if (elapsed > 0.5f) {
		/* Draw tooltips */
		const Widget* widget = findWidget(mMousePos);
		if (widget && !widget->tooltip().empty()) {
			int tooltipWidth = 150;

			float bounds[4];
			nvgFontFace(mNVGContext, "sans");
			nvgFontSize(mNVGContext, 15.0f);
			nvgTextAlign(mNVGContext, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
			nvgTextLineHeight(mNVGContext, 1.1f);
			Vector2i pos = widget->absolutePosition() +
				Vector2i(widget->width() / 2, widget->height() + 10);

			nvgTextBounds(mNVGContext, pos.x(), pos.y(),
				widget->tooltip().c_str(), nullptr, bounds);
			int h = (bounds[2] - bounds[0]) / 2;
			if (h > tooltipWidth / 2) {
				nvgTextAlign(mNVGContext, NVG_ALIGN_CENTER | NVG_ALIGN_TOP);
				nvgTextBoxBounds(mNVGContext, pos.x(), pos.y(), tooltipWidth,
					widget->tooltip().c_str(), nullptr, bounds);

				h = (bounds[2] - bounds[0]) / 2;
			}
			nvgGlobalAlpha(mNVGContext,
				min(1.0, 2 * (elapsed - 0.5f)) * 0.8);

			nvgBeginPath(mNVGContext);
			nvgFillColor(mNVGContext, Color(0, 255));
			nvgRoundedRect(mNVGContext, bounds[0] - 4 - h, bounds[1] - 4,
				(int)(bounds[2] - bounds[0]) + 8,
				(int)(bounds[3] - bounds[1]) + 8, 3);

			int px = (int)((bounds[2] + bounds[0]) / 2) - h;
			nvgMoveTo(mNVGContext, px, bounds[1] - 10);
			nvgLineTo(mNVGContext, px + 7, bounds[1] + 1);
			nvgLineTo(mNVGContext, px - 7, bounds[1] + 1);
			nvgFill(mNVGContext);

			nvgFillColor(mNVGContext, Color(255, 255));
			nvgFontBlur(mNVGContext, 0.0f);
			nvgTextBox(mNVGContext, pos.x() - h, pos.y(), tooltipWidth,
				widget->tooltip().c_str(), nullptr);
		}
	}

	nvgEndFrame(mNVGContext);
}

bool Screen::keyboardEvent(int key, int scancode, int action, int modifiers) {
	if (mFocusPath.size() > 0) {
		for (auto it = mFocusPath.rbegin() + 1; it != mFocusPath.rend(); ++it)
			if ((*it)->focused() && (*it)->keyboardEvent(key, scancode, action, modifiers))
				return true;
	}

	return false;
}

bool Screen::keyboardCharacterEvent(unsigned int codepoint) {
	if (mFocusPath.size() > 0) {
		for (auto it = mFocusPath.rbegin() + 1; it != mFocusPath.rend(); ++it)
			if ((*it)->focused() && (*it)->keyboardCharacterEvent(codepoint))
				return true;
	}
	return false;
}

bool Screen::resizeEvent(const Vector2i& size) {
	if (mResizeCallback) {
		mResizeCallback(size);
		return true;
	}
	return false;
}

bool Screen::cursorPosCallbackEvent(double x, double y) {
	Vector2i p((int)x, (int)y);

	if (p.x() < 0) {
		p[0] = 0;
	}
	if (p.y() < 0)
	{
		p[1] = 0;
	}
#if defined(_WIN32) || defined(__linux__)
	p = (p.cast<float>() / mPixelRatio).cast<int>();
#endif

	bool ret = false;
	mLastInteraction = glfwGetTime();
	try {
		p -= Vector2i(1, 2);

		if (!mDragActive) {
			Widget* widget = findWidget(p);
			if (widget != nullptr && widget->cursor() != mCursor) {
				mCursor = widget->cursor();
				//glfwSetCursor(mGLFWWindow, mCursors[(int)mCursor]);
			}
		}
		else {
			ret = mDragWidget->mouseDragEvent(
				p - mDragWidget->parent()->absolutePosition(), p - mMousePos,
				mMouseState, mModifiers);
		}

		if (!ret)
			ret = mouseMotionEvent(p, p - mMousePos, mMouseState, mModifiers);

		mMousePos = p;

		return ret;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
		return false;
	}
}
bool Screen::mouseButtonCallbackEvent(int button, int action, int modifiers) {
	mModifiers = modifiers;
	mLastInteraction = glfwGetTime();
	try {
		if (mFocusPath.size() > 1) {
			const Window* window =
				dynamic_cast<Window*>(mFocusPath[mFocusPath.size() - 2]);
			if (window && window->modal()) {
				if (!window->contains(mMousePos))
					return false;
			}
		}

		if (action == CALLBACK_PRESS)
			mMouseState |= 1 << button;
		else
			mMouseState &= ~(1 << button);

		auto dropWidget = findWidget(mMousePos);
		if (mDragActive && action == CALLBACK_RELEASE &&
			dropWidget != mDragWidget)
			mDragWidget->mouseButtonEvent(
				mMousePos - mDragWidget->parent()->absolutePosition(), button,
				false, mModifiers);

		if (dropWidget != nullptr && dropWidget->cursor() != mCursor) {
			mCursor = dropWidget->cursor();
		}

		if (action == CALLBACK_PRESS && (button == CALLBACK_MOUSE_BUTTON_1 || button == CALLBACK_MOUSE_BUTTON_2)) {
			mDragWidget = findWidget(mMousePos);
			if (mDragWidget == this) {
				mDragWidget = nullptr;
			}
			else {
				std::cout << "HIt" << std::endl;
			}
			mDragActive = mDragWidget != nullptr;
			if (!mDragActive)
				updateFocus(nullptr);
		}
		else {
			mDragActive = false;
			mDragWidget = nullptr;
		}

		return mouseButtonEvent(mMousePos, button, action == CALLBACK_PRESS,
			mModifiers);
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
		return false;
	}
}

bool Screen::keyCallbackEvent(int key, int scancode, int action, int mods) {
	mLastInteraction = glfwGetTime();
	try {
		return keyboardEvent(key, scancode, action, mods);
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
		return false;
	}
}

bool Screen::charCallbackEvent(unsigned int codepoint) {
	mLastInteraction = glfwGetTime();
	try {
		return keyboardCharacterEvent(codepoint);
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what()
			<< std::endl;
		return false;
	}
}

bool Screen::dropCallbackEvent(int count, const char** filenames) {
	std::vector<std::string> arg(count);
	for (int i = 0; i < count; ++i)
		arg[i] = filenames[i];
	return dropEvent(arg);
}

bool Screen::scrollCallbackEvent(double x, double y) {
	mLastInteraction = glfwGetTime();
	try {
		if (mFocusPath.size() > 1) {
			const Window* window =
				dynamic_cast<Window*>(mFocusPath[mFocusPath.size() - 2]);
			if (window && window->modal()) {
				if (!window->contains(mMousePos))
					return false;
			}
		}
		return scrollEvent(mMousePos, Vector2f(x, y));
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what()
			<< std::endl;
		return false;
	}
}

bool Screen::resizeCallbackEvent(int, int) {
	Vector2i fbSize, size;
	RECT rect;
	GetClientRect(mWindow, &rect);
	size = { rect.right - rect.left ,rect.bottom - rect.top };
	HDC hDC = GetDC(mWindow);
	fbSize = { GetDeviceCaps(hDC, HORZRES),  GetDeviceCaps(hDC, VERTRES) };
	ReleaseDC(mWindow, hDC);


#if defined(_WIN32) || defined(__linux__)
	size = (size.cast<float>() / mPixelRatio).cast<int>();
#endif

	if (fbSize == Vector2i(0, 0) || size == Vector2i(0, 0))
		return false;

	mFBSize = fbSize; mSize = size;
	mLastInteraction = glfwGetTime();

	try {
		return resizeEvent(mSize);
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception in event handler: " << e.what()
			<< std::endl;
		return false;
	}
}

void Screen::updateFocus(Widget* widget) {
	for (auto w : mFocusPath) {
		if (!w->focused())
			continue;
		w->focusEvent(false);
	}
	mFocusPath.clear();
	Widget* window = nullptr;
	while (widget) {
		mFocusPath.push_back(widget);
		if (dynamic_cast<Window*>(widget))
			window = widget;
		widget = widget->parent();
	}
	for (auto it = mFocusPath.rbegin(); it != mFocusPath.rend(); ++it)
		(*it)->focusEvent(true);

	if (window)
		moveWindowToFront((Window*)window);
}

void Screen::disposeWindow(Window* window) {
	if (std::find(mFocusPath.begin(), mFocusPath.end(), window) != mFocusPath.end())
		mFocusPath.clear();
	if (mDragWidget == window)
		mDragWidget = nullptr;
	removeChild(window);
}

void Screen::centerWindow(Window* window) {
	if (window->size() == Vector2i::Zero()) {
		window->setSize(window->preferredSize(mNVGContext));
		window->performLayout(mNVGContext);
	}
	window->setPosition((mSize - window->size()) / 2);
}

void Screen::moveWindowToFront(Window* window) {
	mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), window), mChildren.end());
	mChildren.push_back(window);
	/* Brute force topological sort (no problem for a few windows..) */
	bool changed = false;
	do {
		size_t baseIndex = 0;
		for (size_t index = 0; index < mChildren.size(); ++index)
			if (mChildren[index] == window)
				baseIndex = index;
		changed = false;
		for (size_t index = 0; index < mChildren.size(); ++index) {
			Popup* pw = dynamic_cast<Popup*>(mChildren[index]);
			if (pw && pw->parentWindow() == window && index < baseIndex) {
				moveWindowToFront(pw);
				changed = true;
				break;
			}
		}
	} while (changed);
}

NAMESPACE_END(nanogui)

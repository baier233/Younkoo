#pragma once
class Component {
public:
	virtual ~Component() {}

	virtual void drawScreen(int mouseX, int mouseY) = 0;

	virtual void mouseClicked(int mouseX, int mouseY, int mouseButton) = 0;

	virtual void mouseReleased(int mouseX, int mouseY, int state) = 0;

	virtual void keyTyped(char typedChar, int keyCode) = 0;
};

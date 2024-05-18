#pragma once
class NVGcontext;
#include "../../../utils/Singleton.hpp"
class YounkooGui {
protected:
	NON_COPYABLE(YounkooGui);
public:
	YounkooGui(int posX, int posY) {};
	void drawScreen(NVGcontext* ctx, int x, int y);

};


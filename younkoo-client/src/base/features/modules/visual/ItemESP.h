#pragma once
#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
class ItemESP : public AbstractModule
{
public:
	static ItemESP& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	void onRender3D(const EventRender3D& e);


	DEFINE_BOOL_VALUE(displayNameValue, "Display Name", "Display Name", false);

	std::shared_ptr<ModeValue> modeValue = std::make_shared<ModeValue>("Mode", std::vector<int>{ PSEUDO3D, MODE3D, MODE2D }, std::vector<std::string>{ "Pseudo 3D", "3D", "2D" }, PSEUDO3D);

	enum TARGETMODE {
		PSEUDO3D,
		MODE3D,
		MODE2D,
	};
private:
	ItemESP();
};

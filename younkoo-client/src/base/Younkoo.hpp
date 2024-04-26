#pragma once
#include "../utils/Singleton.hpp"
#include "../utils/Structs.hpp"

class Younkoo : public Singleton<Younkoo>{
protected:
	DEFAULT_DTOR(Younkoo);
	NON_COPYABLE(Younkoo);
public:
	Younkoo();
	bool setup();
};


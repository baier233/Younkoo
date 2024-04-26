#pragma once
#include "../utils/Singleton.hpp"

class Younkoo : public Singleton<Younkoo>{
protected:
	NON_COPYABLE(Younkoo);
	DEFAULT_DTOR(Younkoo);
public:
	Younkoo();
	bool setup();
};


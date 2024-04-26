#pragma once
#include "../../utils/Singleton.hpp"
#include "jni/Pro.hpp"
class JVM : public Singleton<JVM>
{
protected:
	DEFAULT_DTOR(JVM);
	NON_COPYABLE(JVM);
public:
	JVM();
	bool setup();
private:
};

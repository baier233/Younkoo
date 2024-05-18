#pragma once
#include "../../utils/Singleton.hpp"
#include "jni/Wrapper.hpp"
class JVM : public Singleton<JVM>
{
protected:
	DEFAULT_DTOR(JVM);
	NON_COPYABLE(JVM);
public:
	JVM();
	bool setup();
	bool shutdown();
	JNIEnv* Env;
	JavaVM* jvm;
private:
};



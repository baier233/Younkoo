#pragma once
#include "../../utils/Singleton.hpp"
#include "jni/Wrapper.hpp"
#include <jni/jvmti.h>
class JVM : public Singleton<JVM>
{
protected:
	DEFAULT_DTOR(JVM);
	NON_COPYABLE(JVM);
public:
	JVM();
	bool setup();
	bool shutdown();
	JNIEnv* attachAndGetEnv();
	JNIEnv* Env = nullptr;
	jvmtiEnv* jvmti = nullptr;
	JavaVM* jvm = nullptr;
private:
};



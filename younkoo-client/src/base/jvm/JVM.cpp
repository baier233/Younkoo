#include "JVM.hpp"

JVM::JVM()
{

}

bool JVM::setup()
{
	JNI::init();
	jsize count{};
	if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0)
		return false;

	jint res = jvm->GetEnv((void**)&Env, JNI_VERSION_1_8);

	if (res == JNI_EDETACHED)
		res = jvm->AttachCurrentThreadAsDaemon((void**)&Env, nullptr);

	if (res != JNI_OK)
		return false;
	JNI::set_thread_env(Env);
	return true;
}

bool JVM::shutdown()
{
	JNI::shutdown();
	auto err = jvm->DetachCurrentThread();
	return err == 0;
}

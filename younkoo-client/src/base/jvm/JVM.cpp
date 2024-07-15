#include "JVM.hpp"

JVM::JVM()
{

}

bool JVM::setup()
{
	JNI::init();
	Env = attachAndGetEnv();

	if (!jvmti)
	{
		auto res = jvm->GetEnv((void**)&jvmti, JVMTI_VERSION_1_2);
		if (res != JNI_OK)
			return false;

		jvmtiCapabilities capabilities{ .can_retransform_classes = JVMTI_ENABLE };
#ifdef DEBUG
		capabilities.can_access_local_variables = JVMTI_ENABLE;
#endif // DEBUG
		auto err = jvmti->AddCapabilities(&capabilities);
	}



	JNI::set_thread_env(Env);
	return true;
}

bool JVM::shutdown()
{
	JNI::shutdown();
	auto err = jvm->DetachCurrentThread();
	return err == 0;
}

JNIEnv* JVM::attachAndGetEnv()
{
	jsize count{};
	JNIEnv* env{};
	JavaVM* vm = {};
	if (JNI_GetCreatedJavaVMs((jvm) ? &vm : &jvm, 1, &count) != JNI_OK || count == 0)
		return nullptr;

	jint res = jvm->GetEnv((void**)&env, JNI_VERSION_1_8);

	if (res == JNI_EDETACHED)
		res = jvm->AttachCurrentThreadAsDaemon((void**)&env, nullptr);

	if (res != JNI_OK)
		return nullptr;

	return env;
}

#pragma once
#include <jni/Wrapper.hpp>
#include <mapper/SRGParser.h>
//#define TEST
#define EMPTY_CONTENT


namespace SDK {

	inline jobject MinecraftClassLoader;

	inline bool SetUpClassLoader(std::string class_name) {
		auto env = JNI::get_env();
		jclass c_Thread = env->FindClass("java/lang/Thread");
		jclass c_Map = env->FindClass("java/util/Map");
		jclass c_Set = env->FindClass("java/util/Set");
		jclass c_ClassLoader = env->FindClass("java/lang/ClassLoader");

		jmethodID mid_getAllStackTraces = env->GetStaticMethodID(c_Thread, "getAllStackTraces", "()Ljava/util/Map;");
		jmethodID mid_keySet = env->GetMethodID(c_Map, "keySet", "()Ljava/util/Set;");
		jmethodID mid_toArray = env->GetMethodID(c_Set, "toArray", "()[Ljava/lang/Object;");
		jmethodID mid_getContextClassLoader = env->GetMethodID(c_Thread, "getContextClassLoader", "()Ljava/lang/ClassLoader;");
		static auto mid_findClass = env->GetMethodID(c_ClassLoader, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
		//jmethodID mid_currentThread = env->GetStaticMethodID(c_Thread, "currentThread", "()Ljava/lang/Thread;");

		jobject obj_stackTracesMap = env->CallStaticObjectMethod(c_Thread, mid_getAllStackTraces);
		jobject obj_threadsSet = env->CallObjectMethod(obj_stackTracesMap, mid_keySet);

		jobjectArray threads = (jobjectArray)env->CallObjectMethod(obj_threadsSet, mid_toArray);
		jint szThreads = env->GetArrayLength(threads);

		for (int i = 0; i < szThreads; i++)
		{
			jobject thread = env->GetObjectArrayElement(threads, i);
			jobject classLoaderObj = env->CallObjectMethod(thread, mid_getContextClassLoader);

			if (classLoaderObj) {

				jstring className = env->NewStringUTF(class_name.c_str());
				jobject klass = env->CallObjectMethod(classLoaderObj, mid_findClass, className);

				if (klass)
				{
					MinecraftClassLoader = env->NewGlobalRef(classLoaderObj);
					std::lock_guard lock{ JNI::_refs_to_delete_mutex };
					JNI::_refs_to_delete.push_back(MinecraftClassLoader);
					env->DeleteLocalRef(className);
					env->DeleteLocalRef(klass);
					break;
				}
				env->DeleteLocalRef(className);
			}

			env->DeleteLocalRef(thread);
		}

		env->DeleteLocalRef(threads);
		env->DeleteLocalRef(obj_stackTracesMap);
		env->DeleteLocalRef(obj_threadsSet);
		env->DeleteLocalRef(c_Thread);
		env->DeleteLocalRef(c_Map);
		env->DeleteLocalRef(c_Set);
		env->DeleteLocalRef(c_ClassLoader);
		return MinecraftClassLoader != nullptr;
	}

	inline bool SetUpForge1181ClassLoader(std::string thread_name) {
		auto jniEnv = JNI::get_env();
		//(void)jniEnv->PushLocalFrame(15);
		jobject targetClassLoader = NULL;
		typedef jobjectArray(JNICALL* JVM_GetAllThreads)(JNIEnv* env, jclass dummy);
		JVM_GetAllThreads getAllThreads = (JVM_GetAllThreads)GetProcAddress(GetModuleHandleW(L"jvm.dll"), "JVM_GetAllThreads");
		jobjectArray threadsArray = getAllThreads(jniEnv, NULL);
		int threadsCount = jniEnv->GetArrayLength(threadsArray);
		for (int i = 0; i < threadsCount; i++) {
			jobject thread = jniEnv->GetObjectArrayElement(threadsArray, i);
			jclass thread_class = jniEnv->FindClass("java/lang/Thread");
			jmethodID getName = jniEnv->GetMethodID(thread_class, "getName", "()Ljava/lang/String;");
			jstring threadName = (jstring)jniEnv->CallObjectMethod(thread, getName);
			auto threadNameStr = std::string(jniEnv->GetStringUTFChars(threadName, 0));
			std::cout << "threadNameStr :" << threadNameStr << std::endl;
			if (threadNameStr == thread_name) {
				jfieldID ctxClsLoader = jniEnv->GetFieldID(thread_class, "contextClassLoader", "Ljava/lang/ClassLoader;");
				jobject classLoader = jniEnv->GetObjectField(thread, ctxClsLoader);
				MinecraftClassLoader = jniEnv->NewGlobalRef(classLoader);
				std::lock_guard lock{ JNI::_refs_to_delete_mutex };
				JNI::_refs_to_delete.push_back(MinecraftClassLoader);
				break;
			}
		}
		//(void)jniEnv->PopLocalFrame(nullptr);
		return MinecraftClassLoader != nullptr;
	}
}



namespace maps
{
	BEGIN_KLASS_DEF(Object, "java/lang/Object")
		EMPTY_CONTENT;
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(String, "java/lang/String")
		String create(const char* str)
	{
		return String(JNI::get_env()->NewStringUTF(str));
	}

	std::string to_string()
	{
		jstring str_obj = (jstring)(jobject)object_instance;
		jsize utf8_size = JNI::get_env()->GetStringUTFLength(str_obj);
		jsize size = JNI::get_env()->GetStringLength(str_obj);

		std::string str(utf8_size, '\0');
		JNI::get_env()->GetStringUTFRegion(str_obj, 0, size, str.data());
		return str;
	}
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(Collection, "java/util/Collection")
		JNI::Method<JNI::Array<Object>> toArray{ "toArray" ,*this };
	END_KLASS_DEF();

	BEGIN_KLASS_DEF_EX(List, "java/util/List", Collection)
		EMPTY_CONTENT;
	END_KLASS_DEF();
#ifdef TEST
	BEGIN_KLASS_DEF(Main, "Main")
		JNI::Field<jint, JNI::STATIC> field_0{ "field_0",*this };
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(SubClass, "SubClass")
		JNI::Field<jint, JNI::NOT_STATIC> field_1{ "field_1",*this };
	JNI::Method<SubClass, JNI::STATIC> getInstance{ "getInstance",*this };
	END_KLASS_DEF();
#endif // TEST



}
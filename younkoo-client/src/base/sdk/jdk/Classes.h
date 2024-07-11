#pragma once
#include <SDK.hpp>


namespace JDK {

	BEGIN_KLASS_DEF(Object, return "java/lang/Object");
	END_KLASS_DEF();

	BEGIN_KLASS_DEF(Collection, return "java/util/Collection")
		JNI::Method<JNI::Array<Object>, JNI::NOT_STATIC, DECLARE_NAME(return "toArray")> toArray{ *this };
	END_KLASS_DEF();

	BEGIN_KLASS_DEF_EX(List, return "java/util/List", Collection)
		END_KLASS_DEF();

	BEGIN_KLASS_DEF(FloatBuffer, return "java/nio/FloatBuffer")
		END_KLASS_DEF();

	namespace java_util {

		BEGIN_KLASS_DEF(Iterator, return "java/util/Iterator")
			JNI::Method<jboolean, JNI::NOT_STATIC, DECLARE_NAME(return "hasNext")> hasNext{ *this };
		JNI::Method<JDK::Object, JNI::NOT_STATIC, DECLARE_NAME(return "next")> next{ *this };
		END_KLASS_DEF();
	}
	namespace java_lang {
		BEGIN_KLASS_DEF(Iterable, return "java/lang/Iterable")
			JNI::Method<java_util::Iterator, JNI::NOT_STATIC, DECLARE_NAME(return "iterator")> iterator{ *this };
		END_KLASS_DEF();
	}



}
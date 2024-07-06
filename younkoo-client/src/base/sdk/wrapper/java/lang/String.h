#pragma once

#include <SDK.hpp>
#include <string>
BEGIN_KLASS_DEF(String, return "java/lang/String")
std::string toString() {
	auto chars = JNI::get_env()->GetStringUTFChars((jstring)this->object_instance,0);
	return std::string(chars);
}
END_KLASS_DEF();

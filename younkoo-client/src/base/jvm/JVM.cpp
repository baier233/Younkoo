#include "JVM.hpp"

JVM::JVM()
{

}

bool JVM::setup()
{
	JNI::init();
	return true;
}

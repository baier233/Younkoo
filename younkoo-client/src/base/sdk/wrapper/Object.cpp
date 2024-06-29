#include "Object.h"


using namespace Wrapper;

Object::Object(const Object& other_Object) {
	this->instance = std::make_shared<JNI::EmptyMembers>(*other_Object.instance.get());
}

Object::Object(const JNI::EmptyMembers& obj_wrap)
{
	this->instance = std::make_shared<JNI::EmptyMembers>(obj_wrap);
}

bool Object::operator ==(const Object& other_Object)
{
	return this->instance->object_instance == other_Object.instance->object_instance || JNI::get_env()->IsSameObject(this->instance->object_instance, other_Object.instance->object_instance);
}

bool Object::isEqualTo(const Object& other_Object)
{
	return JNI::get_env()->IsSameObject(this->instance->object_instance, other_Object.instance->object_instance);
}


bool Object::isNULL()
{
	return JNI::get_env()->IsSameObject(this->instance->object_instance, NULL);
}

jclass Object::getClass()
{
	return this->instance->owner_klass;
}

jobject Object::getObject()
{
	return this->instance->object_instance;
}


Object::~Object()
{

}
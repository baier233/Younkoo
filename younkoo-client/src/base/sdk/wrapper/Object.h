#pragma once

#include <SDK.hpp>

BEGIN_WRAP

class Object {
public:
	Object() {};
	~Object();
	Object(const Object& other_Object);
	Object(JNI::EmptyMembers& obj_wrap);
	Object(JNI::EmptyMembers obj_wrap);
	bool operator==(const Object& other_Object);
	bool isEqualTo(const Object& other_Object);
	bool isNULL();
	jclass getClass();
	jobject getObject();
protected:

	std::shared_ptr<JNI::EmptyMembers> instance;
};

END_WRAP
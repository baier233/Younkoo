#pragma once

#include <SDK.hpp>

BEGIN_WRAP

class Object {
public:
	Object() {};
	~Object();
	Object(const JNI::EmptyMembers& obj_wrap);
	Object(const Object& other_Object);
	bool operator==(const Object& other_Object);
	Object operator=(const Object& other_Object);
	bool isEqualTo(const Object& other_Object);
	bool isNULL();
	jclass getClass();
	jobject getObject();

	jclass getClass() const;
	jobject getObject() const;

	std::shared_ptr<JNI::EmptyMembers> instance;

};

END_WRAP
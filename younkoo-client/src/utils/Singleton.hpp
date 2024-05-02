#pragma once
#include "Structs.hpp"
//单例模式模板类
template <typename T>
class Singleton {
protected:
	DEFAULT_CTOR_DTOR(Singleton);
	NON_COPYABLE(Singleton);

public:
	[[nodiscard]] static T& get() {
		static T instance = {};
		return instance;
	}
};
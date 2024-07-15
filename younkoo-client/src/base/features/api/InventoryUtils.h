#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <jni/jni.h>
namespace InventoryUtils {
	std::vector<jclass> findBlocksEndingWith(const std::vector<std::string>& targets);
}
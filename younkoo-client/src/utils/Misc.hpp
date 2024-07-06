#pragma once

#include <string>
#include <vector>

namespace Utils {
	namespace Misc {
		template<typename T>
		static std::string arrayToString(const T* arr, size_t size) {
			std::ostringstream oss;
			oss << "[";
			for (size_t i = 0; i < size; ++i) {
				oss << arr[i];
				if (i < size - 1) {
					oss << ", ";
				}
			}
			oss << "]";
			return oss.str();
		}

		template<typename T>
		static std::string arrayToString(const std::vector<T>& arr) {
			std::ostringstream oss;
			oss << "[";
			for (size_t i = 0; i < arr.size(); ++i) {
				oss << arr[i];
				if (i < arr.size() - 1) {
					oss << ", ";
				}
			}
			oss << "]";
			return oss.str();
		}
	}
}

#pragma once
#include <vector>
#include <stdint.h>
#include <string>

namespace SocketUtils {


	enum class PacketHeaderLenType : uint8_t {
		PacketHeaderLen_16,
		PacketHeaderLen_32,
		PacketHeaderLen_64
	};

	__forceinline std::vector<uint8_t> PackN(const std::vector<uint8_t>& buf, PacketHeaderLenType pLen);

	__forceinline std::vector<uint8_t> UnpackN(const std::vector<uint8_t>& data, PacketHeaderLenType pLen);

	std::string Unpack(const std::string& data);

	std::string Pack(const std::string& data);
	inline std::vector<uint8_t> stringToVector(const std::string& str) {
		std::vector<uint8_t> vec(str.begin(), str.end());
		return vec;
	}

	inline std::string vectorToString(const std::vector<uint8_t>& vec) {
		std::string str(vec.begin(), vec.end());
		return str;
	}
	inline void UnsignedCharToVector(unsigned char* data, size_t length, std::vector<uint8_t>& result) {
		for (size_t i = 0; i < length; ++i) {
			result.push_back(data[i]);
		}
	}
}

#include "packer.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <algorithm>



namespace SocketUtils {


	inline std::vector<uint8_t> encodeLength(uint32_t length, PacketHeaderLenType pLen) {
		std::vector<uint8_t> bufLen;
		switch (pLen) {
		case PacketHeaderLenType::PacketHeaderLen_16:
			bufLen.push_back(static_cast<uint8_t>(length & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 8) & 0xFF));
			break;
		case PacketHeaderLenType::PacketHeaderLen_32:
			bufLen.push_back(static_cast<uint8_t>(length & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 8) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 16) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 24) & 0xFF));
			break;
		case PacketHeaderLenType::PacketHeaderLen_64:
			bufLen.push_back(static_cast<uint8_t>(length & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 8) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 16) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 24) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 32) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 40) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 48) & 0xFF));
			bufLen.push_back(static_cast<uint8_t>((length >> 56) & 0xFF));
			break;
		default:
			throw std::runtime_error(("?哥你逆不明白就别逆了"));
		}
		return bufLen;
	}

	__forceinline std::vector<uint8_t> PackN(const std::vector<uint8_t>& buf, PacketHeaderLenType pLen) {
		uint32_t bufSize = static_cast<uint32_t>(buf.size());
		std::vector<uint8_t> bufBinaryLen = encodeLength(bufSize, pLen);
		bufBinaryLen.insert(bufBinaryLen.end(), buf.begin(), buf.end());
		return bufBinaryLen;
	}

	__forceinline std::vector<uint8_t> UnpackN(const std::vector<uint8_t>& data, PacketHeaderLenType pLen) {
		uint32_t packHeaderLen = 0;
		std::vector<uint8_t> lenBuf;

		switch (pLen) {
		case PacketHeaderLenType::PacketHeaderLen_16:
			lenBuf = { data[0], data[1] };
			packHeaderLen = static_cast<uint32_t>(lenBuf[0]) + (static_cast<uint32_t>(lenBuf[1]) << 8);
			break;
		case PacketHeaderLenType::PacketHeaderLen_32:
			lenBuf = { data[0], data[1], data[2], data[3] };
			packHeaderLen = static_cast<uint32_t>(lenBuf[0]) + (static_cast<uint32_t>(lenBuf[1]) << 8) +
				(static_cast<uint32_t>(lenBuf[2]) << 16) + (static_cast<uint32_t>(lenBuf[3]) << 24);
			break;
		case PacketHeaderLenType::PacketHeaderLen_64:
			lenBuf = { data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7] };
			packHeaderLen = static_cast<uint32_t>(lenBuf[0]) + (static_cast<uint32_t>(lenBuf[1]) << 8) +
				(static_cast<uint32_t>(lenBuf[2]) << 16) + (static_cast<uint32_t>(lenBuf[3]) << 24) +
				(static_cast<uint32_t>(lenBuf[4]) << 32) + (static_cast<uint32_t>(lenBuf[5]) << 40) +
				(static_cast<uint32_t>(lenBuf[6]) << 48) + (static_cast<uint32_t>(lenBuf[7]) << 56);
			break;
		default:
			throw std::runtime_error(("?哥你逆不明白就别逆了"));
		}
		std::vector<uint8_t> buf(data.begin() + lenBuf.size() - 1, data.begin() + lenBuf.size() + packHeaderLen);

		return buf;

	}
	std::string Pack(const std::string& data) {
		return vectorToString(SocketUtils::PackN(stringToVector(data), SocketUtils::PacketHeaderLenType::PacketHeaderLen_32));

	}
	std::string Unpack(const std::string& data) {
		return vectorToString(SocketUtils::UnpackN(stringToVector(data), SocketUtils::PacketHeaderLenType::PacketHeaderLen_32));

	}
}
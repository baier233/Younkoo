#include "verify.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>

#include <string>

#include "packer.h"

#include <iostream>
#include "utils/strutils.h"
using namespace SocketUtils;
bool Verfiy::init()
{
	WSADATA wsaData;
	char buffs[100]{};

	SOCKET clientSocket{};
	SOCKADDR_IN serverAddress;
	char buff[1024];
	memset(buff, 0, sizeof(buff));
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		return false;
	}
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(14889);
	serverAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == clientSocket) {
		return false;
	}
	if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == INVALID_SOCKET) {
		return false;
	}

	std::string packedData = SocketUtils::Pack("Younkoo");
	if (send(clientSocket, packedData.c_str(), packedData.length(), 0) == SOCKET_ERROR) {
		closesocket(clientSocket);
		WSACleanup();
		return false;
	}
	char server_reply[1024] = {};
	int len = recv(clientSocket, server_reply, 1024, 0);
	if (len <= 0 || !server_reply) {
		return false;
	}
	unsigned char* recive_data = new unsigned char[len];


	for (int i = 0; i < len; i++)
		recive_data[i] = server_reply[i];


	std::vector<uint8_t> output;
	UnsignedCharToVector(recive_data, len, output);

	auto result = vectorToString(SocketUtils::UnpackN(output, SocketUtils::PacketHeaderLenType::PacketHeaderLen_32));

	delete[] recive_data;
	recive_data = nullptr;
	strutil::trim(result);
	constexpr auto excepted = std::string_view("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	int i = 0;
	auto length = excepted.length();
	result.erase(0, 1);
	return result == excepted;
}

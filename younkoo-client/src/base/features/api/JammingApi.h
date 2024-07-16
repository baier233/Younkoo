#pragma once

#include <string>
struct PlayerInfo
{
	unsigned int NETEASE_USERID;
};


namespace JammingAPI {
	PlayerInfo QueryUserInfo(const std::string& player_name);
}
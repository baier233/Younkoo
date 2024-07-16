#include "JammingApi.h"

#include <httplib/httplib.h>
#include <json.hpp>

constexpr std::string_view API_ADDR = R"(http://43.138.51.85:14224/)";
constexpr std::string_view HEYPIXEL_GAMEID = "4661334467366178884";


static const std::string build_query_user_info_json(const std::string& player_name) {
	nlohmann::json json;
	json["Type"] = "Box";
	json["Token"] = player_name;
	json["Mode"] = 1;
	json["GameID"] = HEYPIXEL_GAMEID;
	return json.dump();

}


PlayerInfo JammingAPI::QueryUserInfo(const std::string& player_name)
{
	auto json_content = build_query_user_info_json(player_name);
	httplib::Client cli(API_ADDR.data());
	auto res = cli.Post("/", json_content, "application/json");

	if (res && res->status == 200) {
		nlohmann::json response_json = nlohmann::json::parse(res->body);

	}
	return PlayerInfo();
}

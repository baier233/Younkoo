#pragma once
#include <string>
#include <codecvt>
namespace wstr {
	inline std::string toString(const std::wstring& wstr) {
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
		return converter.to_bytes(wstr);
	}
}
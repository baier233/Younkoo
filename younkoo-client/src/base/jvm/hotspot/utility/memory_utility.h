//
// Created by Administrator on 2024/3/15.
//

#ifndef MEMORY_UTILITY_H
#define MEMORY_UTILITY_H

#include "../include_header.h"

inline std::string hex_to_bytes(std::string hex_string) {
    std::string bytes;
    std::erase_if(hex_string, isspace);
    for (uint32_t i = 0; i < hex_string.length(); i += 2) {
        if (static_cast<uint8_t>(hex_string[i]) == '?') {
            bytes += '?';
            i -= 1;

            continue;
        }
        const uint8_t byte = static_cast<uint8_t>(std::strtol(hex_string.substr(i, 2).c_str(), nullptr, 16));
        bytes += byte;
    }
    return bytes;
}

inline uintptr_t scan(const char *pattern, const uintptr_t start, const uintptr_t end) {
    const std::string signature = hex_to_bytes(pattern);

    auto base = reinterpret_cast<uint8_t *>(start);
    const auto last = reinterpret_cast<uint8_t *>(end);
    const uint8_t first = signature.at(0);

    for (; base < last; ++base) {
        if (*base != first)
            continue;

        uint8_t *bytes = base;

        for (auto sig = (uint8_t *) signature.c_str(); *sig; ++sig, ++bytes) {
            if (*sig == '?')
                continue;

            if (*bytes != *sig)
                goto end;
        }

        return reinterpret_cast<uintptr_t>(base);

    end:;
    }

    return 0;
}

#endif //MEMORY_UTILITY_H

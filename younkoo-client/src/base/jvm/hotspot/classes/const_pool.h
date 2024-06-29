//
// Created by Administrator on 2024/3/15.
//

#ifndef CONST_POOL_H
#define CONST_POOL_H

#include "symbol.h"

#include "array.h"


namespace java_hotspot {
    class const_pool {
    public:
        auto get_base() -> void **;

        auto get_tags() -> array<unsigned char> *;

        auto get_length() -> int;

        auto get_symbol_at(int index) -> symbol *;

        auto get_symbol_at_address(int index) -> symbol **;

        auto get_pool_holder() -> void*;


    };
}


#endif //CONST_POOL_H

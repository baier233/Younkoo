//
// Created by Administrator on 2024/3/16.
//

#ifndef JVM_STATIC_H
#define JVM_STATIC_H
#include "../classes/symbol.h"


namespace vm_symbols {
    auto get_symbol() -> java_hotspot::symbol **;

    auto symbol_at(int index) -> java_hotspot::symbol *;
}




#endif //JVM_STATIC_H

//
// Created by Administrator on 2024/3/15.
//

#ifndef KLASS_H
#define KLASS_H

#include "const_pool.h"
#include "symbol.h"
#include "array.h"
#include "method.h"

namespace java_hotspot {
    class instance_klass {
    public:
        auto get_name() -> symbol *;

        auto get_constants() -> const_pool *;

        auto get_methods() -> array<method *> *;

        auto get_fields() -> array<uint16_t> *;

        auto set_breakpoints(jvm_internal::breakpoint_info* breakpoints) -> void;

        auto get_breakpoints() -> jvm_internal::breakpoint_info*;
    };
}


#endif //KLASS_H

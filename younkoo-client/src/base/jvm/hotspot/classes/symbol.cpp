//
// Created by Administrator on 2024/3/15.
//

#include "symbol.h"
#include "../utility/jvm_internal.h"

auto java_hotspot::symbol::to_string() -> std::string {
    auto type_symbol = JVMWrapper::from_instance("Symbol", this).value();
    const uint16_t length = *type_symbol.get_field<uint16_t>("_length").value();
    const char *body = type_symbol.get_field<char>("_body").value();
    return std::string{body, static_cast<std::string::size_type>(length)};
}

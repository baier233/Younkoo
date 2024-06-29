//
// Created by Administrator on 2024/3/16.
//

#include "field_info.h"

#include "../utility/jvm_internal.h"
#include "../utility/jvm_static.h"


auto java_hotspot::field_info::from_field_array(array<uint16_t> *fields, const int index) -> field_info * {
    return reinterpret_cast<field_info *>(fields->adr_at(index * field_slots));
}

java_hotspot::field_info *java_hotspot::field_info::from_field_array(uint16_t *fields, const int index) {
    return reinterpret_cast<field_info *>(fields + index * field_slots);
}

auto java_hotspot::field_info::get_shorts() -> uint16_t * {
    return reinterpret_cast<uint16_t *>(reinterpret_cast<uint8_t *>(this));
}

auto java_hotspot::field_info::get_access_flags() -> uint16_t {
    return get_shorts()[access_flags_offset];
}

auto java_hotspot::field_info::get_name_index() -> uint16_t {
    return get_shorts()[name_index_offset];
}

auto java_hotspot::field_info::get_signature_index() -> uint16_t {
    return get_shorts()[signature_index_offset];
}

auto java_hotspot::field_info::get_initval_index() -> uint16_t {
    return get_shorts()[initval_index_offset];
}

auto java_hotspot::field_info::get_offset() -> uint32_t {
    const auto shorts = get_shorts();
    switch (const auto lower = shorts[low_packed_offset]; lower & FIELDINFO_TAG_MASK) {
        case FIELDINFO_TAG_OFFSET:
            return build_int_from_shorts(shorts[low_packed_offset], shorts[high_packed_offset]) >> FIELDINFO_TAG_SIZE;
        default:
            return 0;
    }
}

auto java_hotspot::field_info::get_name(const_pool *const_pool) -> symbol * {
    const int index = get_name_index();
    if (is_internal()) {
        return lookup_symbol(index);
    }
    return const_pool->get_symbol_at(index);
}

auto java_hotspot::field_info::is_internal() -> bool {
    return (get_access_flags() & jvm_internal::JVM_ACC_FIELD_INTERNAL) != 0;
}

auto java_hotspot::field_info::lookup_symbol(const int index) -> symbol * {
    return vm_symbols::symbol_at(index);
}

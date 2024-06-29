//
// Created by Administrator on 2024/3/16.
//

#ifndef FIELD_INFO_H
#define FIELD_INFO_H


#include "../classes/array.h"
#include "../classes/const_pool.h"
#include "../classes/symbol.h"

#include "../include_header.h"

#define FIELDINFO_TAG_SIZE             2
#define FIELDINFO_TAG_BLANK            0
#define FIELDINFO_TAG_OFFSET           1
#define FIELDINFO_TAG_TYPE_PLAIN       2
#define FIELDINFO_TAG_TYPE_CONTENDED   3
#define FIELDINFO_TAG_MASK             3

namespace java_hotspot {
    enum FieldOffset {
        access_flags_offset = 0,
        name_index_offset = 1,
        signature_index_offset = 2,
        initval_index_offset = 3,
        low_packed_offset = 4,
        high_packed_offset = 5,
        field_slots = 6
    };

    class field_info {
    public:
        static auto from_field_array(array<uint16_t>* fields, int index) -> field_info *;

        static auto from_field_array(uint16_t *fields, int index) -> field_info *;

        [[nodiscard]] auto get_shorts() -> uint16_t *;

        auto get_access_flags() -> uint16_t;

        auto get_name_index() -> uint16_t;

        auto get_signature_index() -> uint16_t;

        auto get_initval_index() -> uint16_t;

        auto get_offset() -> uint32_t;

        auto get_name(const_pool *const_pool) -> symbol *;

        auto is_internal() -> bool;

        static auto lookup_symbol(int index) -> symbol *;

    };
}


#endif //FIELD_INFO_H

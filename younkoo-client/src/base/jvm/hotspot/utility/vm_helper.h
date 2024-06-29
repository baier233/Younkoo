//
// Created by Administrator on 2024/3/15.
//

#ifndef VM_HELPER_H
#define VM_HELPER_H

#include "../include_header.h"


namespace vm_helper {
	inline std::size_t thread_frame_offset = 0x0;
	inline std::size_t thread_operand_stack_offset = 0x0;
	inline uintptr_t restore_register_addr = 0x0;
	inline std::string vm_call_pattern = R"(
    49 89 AF ? ? ? ?
    49 89 87 ? ? ? ?
    48 83 EC 20
    40 F6 C4 0F
    0F 84 ? ? ? ?
    48 83 EC 08
    48 ? ? ? ? ? ? ? ? ?
    FF
    )";

	inline std::string vm_call_pattern2 = R"(
    49 89 AF ? ? ? ?
    49 89 87 ? ? ? ?
    48 83 EC 20
    F7 C4 0F 00 00 00
    0F 84 ? ? ? ?
    48 83 EC 08
    49 ? ? ? ? ? ? ? ? ?
    41 FF
    )";

	inline std::string vm_call_address_pattern = R"(
    48 83 EC 08
    )";

	inline std::string vm_call_restore_register_pattern = R"(
    4C 8B 6D ? 4C 8B 75 ? C3
    )";
	auto find_vm_calls(PVOID start) -> std::vector<PVOID>;
};


#endif //VM_HELPER_H

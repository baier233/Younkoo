//
// Created by Administrator on 2024/3/15.
//

#include "vm_helper.h"
#include "memory_utility.h"

auto vm_helper::find_vm_calls(PVOID start) -> std::vector<PVOID> {
	std::vector<PVOID> calls;
	constexpr size_t max_len = 0x500;

	const auto start_addr = reinterpret_cast<uintptr_t>(start);
	const uintptr_t end_addr = start_addr + max_len;
	auto call_pattern = const_cast<char*>(vm_call_pattern.c_str());
	auto restore_register_pattern = const_cast<char*>(vm_call_restore_register_pattern.c_str());


	restore_register_addr = scan(restore_register_pattern, start_addr, end_addr);
#ifdef DEBUGGER
	std::cout << "Restore_register_addr :" << (void*)restore_register_addr << std::endl;
#endif // DEBUGGER

	uintptr_t vm_call_addr = scan(call_pattern, start_addr, end_addr);
	if (!vm_call_addr) {
#ifdef DEBUGGER
		std::cout << "Failed to find vm_call_addr using pattern 1" << std::endl;
#endif
		call_pattern = const_cast<char*>(vm_call_pattern2.c_str());
		vm_call_addr = scan(call_pattern, start_addr, end_addr);
	}


	if (vm_call_addr && !thread_frame_offset) {
		const auto preserve_frame_mov = vm_call_addr;
		/*
				49:89AF F0030000         | mov qword ptr ds:[r15+3F0],rbp
			*/
		thread_frame_offset = *reinterpret_cast<uint32_t*>(preserve_frame_mov + 3);
		const uintptr_t operand_stack_mov = preserve_frame_mov + 7;
		/*
				49:8987 E0030000         | mov qword ptr    ds:[r15+3E0],rax
			*/
		thread_operand_stack_offset = *reinterpret_cast<uint32_t*>(operand_stack_mov + 3);
	}

	if (!vm_call_addr) {
#ifdef DEBUGGER
		std::cout << "Failed to find vm_call_addr using pattern 2" << std::endl;
#endif
	}

	// TODO: Wait fix finded address
#ifdef DEBUGGER
	std::cout << "vm_call_addr: " << reinterpret_cast<void*>(vm_call_addr) << std::endl;
#endif
	while (vm_call_addr) {
		const uintptr_t vm_call_address = scan(vm_call_address_pattern.c_str(), vm_call_addr, vm_call_addr + 0x64);
		switch (const uint8_t type = *reinterpret_cast<uint8_t*>(vm_call_address + 4)) {
		case 0x49: // mov
		{
			calls.push_back(*reinterpret_cast<PVOID*>(vm_call_address + 6));
		}
		break;
		case 0xE8: // call
		{
			const auto call_offset_address = reinterpret_cast<uint8_t*>(vm_call_address) + 4;
			const auto offset_ptr = reinterpret_cast<int32_t*>(static_cast<uint8_t*>(call_offset_address) + 1);
			const auto offset = *offset_ptr;
			const auto absolute_address = static_cast<PVOID>(
				static_cast<uint8_t*>(call_offset_address) + offset + 5);
			calls.push_back(absolute_address);
		}
		break;
		default:

#ifdef DEBUGGER
			std::cout << "Unknown type: " << std::hex << static_cast<int>(type) << std::endl;
#endif
			break;
		}

		vm_call_addr = scan(call_pattern, vm_call_addr + 1, end_addr);
	}

	return calls;
}

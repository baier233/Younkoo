#include "bytecode.h"

#include "../break/break_point_info.h"
#include "../break/byte_code_info.h"

namespace java_runtime {
	bytecode::bytecode(uint8_t* address) : opcode(address) {
		if (const bytecodes opcode = this->get_opcode();
			opcode == bytecodes::_lookupswitch || opcode == bytecodes::_tableswitch) {
			throw std::runtime_error("Must use the other constructor for address");
		}
	}

	bytecode::bytecode(uint8_t* bytecode_start, uint8_t* address) : opcode(address) {
		bytecode_offsets[bytecode_start] = address - bytecode_start;
	}

	bytecodes bytecode::get_opcode() const {
		return static_cast<bytecodes>(*this->opcode);
	}

	static uint32_t get_java_u4(const uint8_t* p) {
		return (static_cast<uint32_t>(p[0]) << 24) |
			(static_cast<uint32_t>(p[1]) << 16) |
			(static_cast<uint32_t>(p[2]) << 8) |
			static_cast<uint32_t>(p[3]);
	}
	static intptr_t mask_bits(const intptr_t x, const intptr_t m) { return x & m; }

	inline intptr_t round_to(const intptr_t x, const uintptr_t s) {
		const uintptr_t m = s - 1;
		return mask_bits(x + m, ~m);
	}
	int bytecode::get_length() const {
		switch (this->get_opcode()) {
		case bytecodes::_wide: {
			/* Get next opcode */
			if (const auto wide_opcode = static_cast<bytecodes>(opcode[1]); wide_opcode == bytecodes::_iinc)
				return 6;
			return 4;
		}
		case bytecodes::_lookupswitch: // fall through
		case bytecodes::_fast_binaryswitch: // fall through
		case bytecodes::_fast_linearswitch: {
			const auto aligned_bcp = reinterpret_cast<uint8_t*>(round_to(
				reinterpret_cast<intptr_t>(opcode) + 1, 4));
			const __int64 npairs = static_cast<jint>(get_java_u4(aligned_bcp + 4));
			const __int64 length = (aligned_bcp - opcode) + (2 + 2 * npairs) * 4;
			return (length > 0 && length == static_cast<int>(length)) ? static_cast<int>(length) : -1;
		}
		case bytecodes::_tableswitch: {
			const auto aligned_bcp = reinterpret_cast<uint8_t*>(round_to(
				reinterpret_cast<intptr_t>(opcode) + 1, 4));
			const __int64 low = static_cast<int>(get_java_u4(aligned_bcp + 1 * 4));
			const __int64 high = static_cast<int>(get_java_u4(aligned_bcp + 2 * 4));
			const __int64 length = (aligned_bcp - opcode) + (3 + high - low + 1) * 4;
			return (length > 0 && length == static_cast<int>(length)) ? static_cast<int>(length) : -1;
		}
		default: {
			return static_cast<int>(jvm_byte_code::bytecode_lengths[static_cast<unsigned int>(this->get_opcode())] &
				0xF);
		}
		}
		// Should never happen
		return 0;
	}

	int bytecode::get_stack_consumption() const {
		return jvm_byte_code::bytecode_operand_consumption[static_cast<uint8_t>(this->get_opcode())];
	}
}

/* Static bytecode map */
std::map<uint8_t*, uint16_t> java_runtime::bytecode::bytecode_offsets;

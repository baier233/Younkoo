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

    int bytecode::get_length() const {
        return static_cast<int>(jvm_byte_code::bytecode_lengths[static_cast<unsigned int>(this->get_opcode())]);
    }

    int bytecode::get_stack_consumption() const {
        return jvm_byte_code::bytecode_operand_consumption[static_cast<uint8_t>(this->get_opcode())];
    }
}

/* Static bytecode map */
std::map<uint8_t *, uint16_t> java_runtime::bytecode::bytecode_offsets;

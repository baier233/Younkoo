#include "local_variable_table.h"
#include <hotspot/utility/jvm_internal.h>
#include <hotspot/classes/const_pool.h>
using namespace java_hotspot;

local_variable_entry local_variable_table_element::wrap_to_jvm_variable_entry(const_pool* constant)
{

    static VMStructEntry* start_bci = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["start_bci"];
    static VMStructEntry* length = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["length"];
    static VMStructEntry* name_cp_index = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["name_cp_index"];
    static VMStructEntry* descriptor_cp_index = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["descriptor_cp_index"];
    static VMStructEntry* signature_cp_index = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["signature_cp_index"];
    static VMStructEntry* slot = JVMWrappers::find_type_fields("LocalVariableTableElement").value().get()["slot"];


    auto name = constant->get_symbol_at(*(int*)(this + name_cp_index->offset))->to_string();
                
    auto signatrue = constant->get_symbol_at(*(int*)(this + descriptor_cp_index->offset))->to_string();

    auto generic_signature_index = *(int*)(this + signature_cp_index->offset);

    auto ret_value = local_variable_entry{
        .start_location = *(long*)(this+start_bci->offset),
        .length = *(int*)(this + length->offset),
        .name = name,.signature = signatrue,
        .generic_signature = (generic_signature_index > 0 ) ? constant->get_symbol_at(generic_signature_index)->to_string() : "",
        .slot = *(int*)(this + slot->offset)
    };



    return ret_value;
}

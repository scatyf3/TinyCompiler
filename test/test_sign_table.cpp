#include <cassert>
#include "../src/sign_table.hpp"
#include <iostream>

void testSearchAndCalculateOffset() {
    SignTable sign_table;
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg1"});
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg2"});
    sign_table.addSymbol({SymbolType::LOCAL_VAR, "var1"});
    sign_table.addSymbol({SymbolType::LOCAL_VAR, "var2"});

    int arg1_offset = sign_table.searchAndCalculateOffset("arg1");
    std::cout<<sign_table.printSignTable()<<std::endl;
    std::cout<<arg1_offset<<std::endl;
    assert(arg1_offset == 8);

    int arg2_offset = sign_table.searchAndCalculateOffset("arg2");
    
    assert(arg2_offset == 12);

    int var1_offset = sign_table.searchAndCalculateOffset("var1");
    assert(var1_offset == -4);

    int var2_offset = sign_table.searchAndCalculateOffset("var2");
    assert(var2_offset == -8);

    int invalid_offset = sign_table.searchAndCalculateOffset("invalid");
    assert(invalid_offset == -1);
}
void testIsInSignTable() {
    SignTable sign_table;
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg1"});
    sign_table.addSymbol({SymbolType::LOCAL_VAR, "var1"});

    assert(sign_table.isInSignTable("arg1"));
    assert(sign_table.isInSignTable("var1"));
    assert(!sign_table.isInSignTable("invalid"));
}

int main() {
    testSearchAndCalculateOffset();
    testIsInSignTable();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
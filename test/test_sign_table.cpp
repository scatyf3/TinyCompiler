#include <cassert>
#include "../src/sign_table.hpp"
#include <iostream>

void testSearchAndCalculateOffset() {
    SignTable sign_table;
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg1"});
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg2"});
    sign_table.addSymbol({SymbolType::FUNC_ARG, "arg3"});

    //args 可被视作栈，先进入的在栈的更“高位”，所以offset大
    std::cout<<sign_table.printSignTable()<<std::endl;
    int arg1_offset = sign_table.searchAndCalculateOffset("arg1");
    std::cout<<arg1_offset;
    assert(arg1_offset == 16);
    

    int arg2_offset = sign_table.searchAndCalculateOffset("arg2");
    assert(arg2_offset == 12);

    int var1_offset = sign_table.searchAndCalculateOffset("arg3");
    assert(var1_offset == 8);

    //int var2_offset = sign_table.searchAndCalculateOffset("var2");
    //assert(var2_offset == -8);

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
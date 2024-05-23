#include "../src/MIPS.h"
#include <cassert>
#include <iostream>

void testSearchAndCalculateOffset() {
    // 测试用例1
    std::vector<std::pair<SymbolType, std::string>> sign_table1 = {
        {SymbolType::FUNC_ARG, "arg1"},
        {SymbolType::FUNC_ARG, "arg2"},
        {SymbolType::LOCAL_VAR, "var1"},
        {SymbolType::LOCAL_VAR, "var2"},
        {SymbolType::LOCAL_VAR, "var3"}
    };
    printSignTable(sign_table1);
    
    assert(searchAndCalculateOffset("arg1", sign_table1) == 8);
    assert(searchAndCalculateOffset("arg2", sign_table1) == 4);
    assert(searchAndCalculateOffset("var1", sign_table1) == -4);
    assert(searchAndCalculateOffset("var2", sign_table1) == -8);
    assert(searchAndCalculateOffset("var3", sign_table1) == -12);
    
    // 测试用例2
    std::vector<std::pair<SymbolType, std::string>> sign_table2 = {
        {SymbolType::FUNC_ARG, "arg1"},
        {SymbolType::LOCAL_VAR, "var1"},
        {SymbolType::LOCAL_VAR, "var2"}
    };
    
    assert(searchAndCalculateOffset("arg1", sign_table2) == 8);
    assert(searchAndCalculateOffset("var1", sign_table2) == -4);
    assert(searchAndCalculateOffset("var2", sign_table2) == -8);
    
    // 测试用例3
    std::vector<std::pair<SymbolType, std::string>> sign_table3 = {
        {SymbolType::LOCAL_VAR, "var1"},
        {SymbolType::LOCAL_VAR, "var2"},
        {SymbolType::LOCAL_VAR, "var3"}
    };
    
    assert(searchAndCalculateOffset("var1", sign_table3) == -4);
    assert(searchAndCalculateOffset("var2", sign_table3) == -8);
    assert(searchAndCalculateOffset("var3", sign_table3) == -12);
    
    // 添加更多测试用例...
    
    std::cout << "All test cases passed!" << std::endl;
}


int main() {
    testSearchAndCalculateOffset();
    return 0;
}
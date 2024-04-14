#include "tcc.hpp"
#include "lexer.h"



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }
    yyin = fopen("../test/testcase.minic", "r");
    yylex();
    printTokens(token);
    std::cout<<"======="<<std::endl;
    std::string output = compile(token);
    std::cout << output << std::endl;
    return 0;
}

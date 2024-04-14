#include "../src/tcc.hpp"
#include <cassert>


int main(){
    //TODO:这个代码旨在测试给定token deque，然后输出mips汇编的能力
    std::deque<Token> code;
    code.push_back((Token("int","keyword")));
    code.push_back((Token("main","keyword")));
    code.push_back((Token("(","brackets")));
    code.push_back((Token(")","brackets")));
    code.push_back((Token("{","brackets")));
    code.push_back(Token("int","keyword"));
    code.push_back(Token("a","identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("a","identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("1","constant"));
    code.push_back(Token(";", "semicolon"));
    code.push_back((Token("return","keyword")));
    code.push_back(Token("0","constant"));
    code.push_back((Token("}","brackets")));
    const std::string asm_src = compile(code);
    
    std::cout<<asm_src<<std::endl;

    return 0;
}
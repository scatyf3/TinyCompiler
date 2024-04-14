#include "../src/tcc.hpp"
#include <cassert>


int main(){
    //TODO:这个代码旨在测试给定token deque，然后输出mips汇编的能力
    std::deque<Token> code;
    /* CASE1: BASIC compile
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
    code.push_back(Token(";","semicolon"));
    code.push_back((Token("}","brackets")));
    */

    /*
     * CASE 2: more ops -> 变量声明必须早于运算，否则bug
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("main", "keyword"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token("{", "brackets"));

// 声明变量
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("int", "keyword"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("c", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("d", "identifier"));
    code.push_back(Token(";", "semicolon"));

// 赋值语句
    code.push_back(Token("a", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("10", "constant"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("b", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("5", "constant"));
    code.push_back(Token(";", "semicolon"));

// 比较运算
    code.push_back(Token("d", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(">", "operator"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));


    code.push_back(Token("c", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token("&", "operator"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));

    code.push_back((Token("return","keyword")));
    code.push_back(Token("0","constant"));
    code.push_back(Token(";","semicolon"));
    code.push_back(Token("}", "brackets"));
    */

    /*
     * CASE3:PRINT

    code.push_back(Token("int", "keyword"));
    code.push_back(Token("main", "keyword"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token("{", "brackets"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("c", "identifier"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("a", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("1", "constant"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("b", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("2", "constant"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("println_int", "std_function"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token(";", "semicolon"));

    code.push_back(Token("c", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("114514", "constant"));
    code.push_back(Token(";", "semicolon"));

    code.push_back((Token("return","keyword")));
    code.push_back(Token("0","constant"));
    code.push_back(Token(";","semicolon"));
    code.push_back(Token("}", "brackets"));
     */

    code.push_back(Token("int", "keyword"));
    code.push_back(Token("main", "keyword"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token("{", "brackets"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("int", "keyword"));
    code.push_back(Token("d", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("1", "constant"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("2", "constant"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("println_int", "std_function"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("println_int", "std_function"));
    code.push_back(Token("(", "brackets"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(")", "brackets"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("d", "identifier"));
    code.push_back(Token("=", "operator"));
    code.push_back(Token("a", "identifier"));
    code.push_back(Token("+", "operator"));
    code.push_back(Token("b", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("return", "keyword"));
    code.push_back(Token("d", "identifier"));
    code.push_back(Token(";", "semicolon"));
    code.push_back(Token("}", "brackets"));

    const std::string asm_src = compile(code);
    
    std::cout<<asm_src<<std::endl;

    return 0;
}
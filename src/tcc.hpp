#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <utility>


struct Token {
    std::string value;
    std::string type;
    Token(std::string  val, std::string  t) : value(std::move(val)), type(std::move(t)) {}
};

std::vector<std::string> sign_table;

std::string compile(std::deque<Token> token);
bool isValidLeftExpression(const std::deque<Token>& leftExp);
std::string pushToken(Token t);
std::string eval(std::deque<Token> leftExp);
std::vector<std::string> splitString(const std::string& str, char delimiter);
void printTokens(const std::deque<Token>& tokens);
void printLine(const std::deque<Token>& line);
bool checkBrackets(const std::deque<Token> tokens);
bool process_main(std::deque<Token>* token);

//input: int a;\nint b;\nint d;\na = 1;\nb = 2;\nd = a + b;\nreturn d;
//按照空格分token，按照\n分行
//output: std::deque<std::deque<Token>>,which one line of src is std::deque<Token>
//struct Token {
//    std::string value;
//    std::string type;
//    Token(std::string  val, std::string  t) : value(std::move(val)), type(std::move(t)) {}
//};

//"sw $zero,-4($fp)\nsw $zero,-8($fp)\nsw $zero,-12($fp)\nlw $v0, 4($sp)\naddiu $sp, $sp, 4\nsw $v0,-4($fp)\nlw $v0, 4($sp)\naddiu $sp, $sp, 4\nsw $v0,-8($fp)\n"
std::string compile(std::deque<Token> token) {
    //printLine(token);
    std::string asm_src;
    std::deque<Token> prev_code;//在main函数入口之前的一些代码
    while(token.front().value!="main"){
        prev_code.push_back(token.front());
        token.pop_front();
    }
    if(!checkBrackets(token)){
        std::cout<<"Brackets match error"<<std::endl;
    }
    if(process_main(&token)){
        // init function
        asm_src+=".data\n"
                 "newline: .asciiz \"\\n\"\n"
                 ".text\n"
                 ".globl main\n"
                 "main:\n"
                 "move $fp, $sp\n"
                 "addiu $sp, $sp, -0x100\n";
    }
    else{
        std::cout<<"cannot find program's entrance point"<<std::endl;
    }
    //直到作为入口点
    while (!token.empty() && token.front().value!="}") {
        //从token提取出一行，直到出现分号
        std::deque<Token> cur_line;
        while(token.front().type!="semicolon"){
            cur_line.push_back(token.front());
            token.pop_front();
        }
        //dbg
        //printTokens(cur_line);
        //弹出semicolon
        token.pop_front();
        //编译单行代码
        //printLine(cur_line);
        while (!cur_line.empty()) {
            printLine(cur_line);
            //debug std::cout<<asm_src<<std::endl;
            //std::cout<<cur_line.front().value<<std::endl;
            if (cur_line.front().value == "return") {
                // exit program
                cur_line.pop_front();
                Token val_to_return = cur_line.front();
                if (val_to_return.type == "constant") {
                    asm_src += "li $v0,";
                    asm_src += val_to_return.value;
                    asm_src += "\n";
                } else {
                    asm_src += "lw $v0,";
                    auto it = std::find(sign_table.begin(), sign_table.end(),
                                        val_to_return.value);
                    if (it != sign_table.end()) {
                        int index = std::distance(sign_table.begin(), it);
                        int result = (index + 1) * -4;
                        asm_src += std::to_string(result);
                    } else {
                        asm_src += "Compile Error: Undefined Symbol";
                    }
                    asm_src += "($fp)\n";
                }
                asm_src+="move $v1, $v0\n"
                         "li $v0, 10\n"
                         "syscall\n";
                return asm_src;
            }
            //std::cout<<cur_line.front().value<<std::endl;
            //std::cout<<(cur_line.front().value == "int")<<std::endl;
            if (cur_line.front().value == "int") { //✅
                // 声明 eg: int a;
                std::cout<<"处理赋值声明"<<std::endl;
                cur_line.pop_front();
                Token symbol = cur_line.front();
                if (symbol.type != "identifier") {
                    asm_src += "Compile Error: Unknown Syntax";
                    std::cout<<"Compile Error: Unknown Syntax"<<std::endl;
                }
                sign_table.push_back(symbol.value);
                cur_line.pop_front();
                asm_src += "sw $zero,";
                auto it = std::find(sign_table.begin(), sign_table.end(),
                                    symbol.value);
                if (it != sign_table.end()) {
                    int index = std::distance(sign_table.begin(), it);
                    int result = (index + 1) * -4;
                    asm_src += std::to_string(result);
                }
                asm_src += "($fp)";
                if (!cur_line.empty()) {
                    asm_src += "Compile Error: Declear error";
                    std::cout<<"Compile Error: Declear error"<<std::endl;
                }
            }
            if (cur_line.front().type == "identifier") {
                // 赋值
                Token symbol =cur_line.front();
                cur_line.pop_front();
                Token op = cur_line.front();
                if (op.value != "=") {
                    asm_src += "Compile Error: Unknown Syntax";
                }
                cur_line.pop_front();
                asm_src += eval(cur_line);
                asm_src += "sw $v0,";
                auto it = std::find(sign_table.begin(), sign_table.end(),
                                    symbol.value);
                if (it != sign_table.end()) {
                    int index = std::distance(sign_table.begin(), it);
                    int result = (index + 1) * -4;
                    asm_src += std::to_string(result);
                }
                asm_src += "($fp)";
                break;//如果没有意外，全部的左值都交给eval，这样的话本行已然处理完毕
            }
            if(cur_line.front().type == "std_function"){
                //系统库函数
                //check and pop left bracket
                //弹出函数
                cur_line.pop_front();
                //弹出左括号
                if(cur_line.front().value!="("){
                    asm_src += "Compile Error: UB in function call";
                }
                cur_line.pop_front();
                //弹出参数
                Token val_to_print = cur_line.front();
                cur_line.pop_front();
                //暂时只处理打印int
                if(val_to_print.type!="identifier" && val_to_print.type!="constant" ){
                    asm_src += "Compile Error: println_int argument error";
                }
                if(val_to_print.type=="identifier"){
                    asm_src += "lw $a0,"; //系统函数的参数是a系列寄存器
                    auto it = std::find(sign_table.begin(), sign_table.end(),
                                        val_to_print.value);
                    if (it != sign_table.end()) {
                        int index = std::distance(sign_table.begin(), it);
                        int result = (index + 1) * -4;
                        asm_src += std::to_string(result);
                    } else {
                        asm_src += "Compile Error: Undefined Symbol";
                    }
                    asm_src += "($fp)\n";
                }else{
                    asm_src += "li $a0,";
                    asm_src += val_to_print.value;
                }
                asm_src+="li $v0, 1 # 设置系统调用号为 1，即打印整数\n"
                         "syscall # 系统调用\n"
                         "li $v0, 4 # 设置系统调用号为 4，即打印字符串\n"
                         "la $a0, newline # 准备系统调用参数\n"
                         "syscall # 系统调用\n";
                //弹出右括号
                cur_line.pop_front();
            }
        }
        asm_src += "\n";
    }
    return asm_src;
}

std::string eval(std::deque<Token> leftExp) {
    std::string asm_src = "";
    if (!isValidLeftExpression(leftExp)) {
        asm_src += "Syntax Error: Invalid Left Exp";
    }

    asm_src += pushToken(leftExp.front());
    leftExp.pop_front();

    while (!leftExp.empty()) {
        Token curOp = leftExp.front();
        leftExp.pop_front();

        asm_src += pushToken(leftExp.front());
        leftExp.pop_front();

        asm_src += "lw $t1, " + std::to_string(4) + "($sp)\n";
        asm_src += "lw $t0, " + std::to_string(8) + "($sp)\n";

        if (curOp.value == "+") {
            asm_src += "add $t0, $t0, $t1\n";
        } else if (curOp.value == "-") {
            asm_src += "sub $t0, $t0, $t1\n";
        } else if (curOp.value == "*") {
            asm_src += "mul $t0, $t0, $t1\n";
        } else if (curOp.value == "/") {
            asm_src += "div $t0, $t0, $t1\n";
        } else if (curOp.value == "%") {
            asm_src += "rem $t0, $t0, $t1\n";
        } else if (curOp.value == "<") {
            asm_src += "slt $t0, $t0, $t1\n";
        } else if (curOp.value == "<=") {
            asm_src += "sle $t0, $t0, $t1\n";
        } else if (curOp.value == ">") {
            asm_src += "sgt $t0, $t0, $t1\n";
        } else if (curOp.value == ">=") {
            asm_src += "sge $t0, $t0, $t1\n";
        } else if (curOp.value == "==") {
            asm_src += "seq $t0, $t0, $t1\n";
        } else if (curOp.value == "!=") {
            asm_src += "sne $t0, $t0, $t1\n";
        } else if (curOp.value == "&") {
            asm_src += "and $t0, $t0, $t1\n";
        } else if (curOp.value == "|") {
            asm_src += "or $t0, $t0, $t1\n";
        } else if (curOp.value == "^") {
            asm_src += "xor $t0, $t0, $t1\n";
        }
        asm_src += "sw $t0, 8($sp)\n";
        asm_src += "addiu $sp, $sp, 4\n";
    }
    asm_src += "lw $v0, 4($sp)\n";
    asm_src += "addiu $sp, $sp, 4\n";

    return asm_src;
}

bool isValidLeftExpression(const std::deque<Token>& leftExp) {
    if (leftExp.empty()) {
        return false;
    }
    if (leftExp.front().type != "constant" && leftExp.front().type != "identifier") {
        std::cerr<<"type error:"<<leftExp.front().type<<std::endl;
        return false;
    }
    for (size_t i = 1; i < leftExp.size() - 1; ++i) {
        if (i % 2 == 1 && leftExp[i].type != "operator") {
            return false;
        }
        if (i % 2 == 0 && (leftExp[i].type != "constant" &&
                           leftExp[i].type != "identifier")) {
            return false;
        }
    }
    if (leftExp.back().type != "constant" &&
        leftExp.back().type != "identifier") {
        return false;
    }
    return true;
}

std::string pushToken(Token t) {//✅
    // lw $v0, -4($fp) #if token is varible
    // li $v0, 42 # if token is pure value
    // sw $v0, 0($sp)
    // addiu $sp, $sp, -4
    std::string asm_src = "";
    if (t.type == "constant") {
        asm_src += "li $v0, ";
        asm_src += t.value;
        asm_src += "\n";
    }
    if (t.type == "identifier") {
        asm_src += "lw $v0, ";
        auto it = std::find(sign_table.begin(), sign_table.end(), t.value);
        if (it != sign_table.end()) {
            int index = std::distance(sign_table.begin(), it);
            int result = (index + 1) * -4;
            asm_src += std::to_string(result);
        }
        asm_src += "($fp)\n";
    }
    asm_src += "sw $v0, 0($sp)\n";
    asm_src += "addiu $sp, $sp, -4\n";
    return asm_src;
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> substrings;
    std::string currentSubstring;
    for (char c : str) {
        if (c == delimiter) {
            substrings.push_back(currentSubstring);
            currentSubstring.clear();
        } else {
            currentSubstring += c;
        }
    }
    // Add the last substring if it's not empty
    if (!currentSubstring.empty()) {
        substrings.push_back(currentSubstring);
    }

    return substrings;
}


void printTokens(const std::deque<Token>& tokens) {
    for (const auto& token : tokens) {
            std::cout << "Value: " << token.value << ", Type: " << token.type << std::endl;
    }
}

void printLine(const std::deque<Token>& line) {
    for (const auto& token : line) {
        std::cout << "Value: " << token.value << ", Type: " << token.type << std::endl;
    }
    std::cout << std::endl; // 打印每一行之间的空行
}
bool process_main(std::deque<Token>* token) {
    if (!token->empty() && token->front().value == "main") {
        token->pop_front(); // 弹出 "main" token
    } else {
        return false; // "main" 不匹配，返回 false
    }

    if (!token->empty() && token->front().value == "(") {
        token->pop_front(); // 弹出 "(" token
    } else {
        return false; // "(" 不匹配，返回 false
    }

    if (!token->empty() && token->front().value == "identifier" && token->front().value== "argc") {
        token->pop_front(); // 弹出 "argc" token
        if (!token->empty() && token->front().value == "identifier" && token->front().value == "argv") {
            token->pop_front(); // 弹出 "argv" token
        } else {
            return false; // "argv" 不匹配，返回 false
        }
    }

    if (!token->empty() && token->front().value == ")") {
        token->pop_front(); // 弹出 ")" token
    } else {
        return false; // ")" 不匹配，返回 false
    }

    if (!token->empty() && token->front().value == "{") {
        token->pop_front(); // 弹出 "{" token
    } else {
        return false; // "{" 不匹配，返回 false
    }

    return true; // 所有检查通过，返回 true
}


bool checkBrackets(const std::deque<Token> tokens) {
    std::stack<Token> stack;

    for (const Token& token : tokens) {
        if (token.type == "brackets") {
            if (token.value == "{" || token.value == "(") {
                stack.push(token);
            } else { // token.value == "}" or token.value == ")"
                if (stack.empty()) {
                    return false; // 没有匹配的左括号
                }
                Token openingBracket = stack.top();
                stack.pop();

                if ((token.value == "}" && openingBracket.value != "{") ||
                    (token.value == ")" && openingBracket.value != "(")) {
                    return false; // 左右括号类型不匹配
                }
            }
        }
    }

    return stack.empty(); // 所有左括号都有对应的右括号
}
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

std::string compile(std::deque<std::deque<Token>> token);
bool isValidLeftExpression(const std::deque<Token>& leftExp);
std::deque<std::deque<Token>> tokenize(const std::string& str);
std::string pushToken(Token t);
std::string eval(std::deque<Token> leftExp);
std::vector<std::string> splitString(const std::string& str, char delimiter);
void printTokens(const std::deque<std::deque<Token>>& tokens);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }

    std::string sourceCodeFileName = argv[1];
    std::ifstream inputFile(sourceCodeFileName);

    if (inputFile.is_open()) {
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string sourceCode = buffer.str();
        sourceCode.erase(std::remove(sourceCode.begin(), sourceCode.end(), ';'), sourceCode.end());
        inputFile.close();

        std::deque<std::deque<Token>> token = tokenize(sourceCode);
        printTokens(token);
        std::string output = compile(token);
        std::cout << output << std::endl;
    } else {
        std::cout << "无法打开源代码文件." << std::endl;
    }

    return 0;
}

//input: int a;\nint b;\nint d;\na = 1;\nb = 2;\nd = a + b;\nreturn d;
//按照空格分token，按照\n分行
//output: std::deque<std::deque<Token>>,which one line of src is std::deque<Token>
//struct Token {
//    std::string value;
//    std::string type;
//    Token(std::string  val, std::string  t) : value(std::move(val)), type(std::move(t)) {}
//};
std::deque<std::deque<Token>> tokenize(const std::string& str) {
    std::deque<std::deque<Token>> lines;
    std::istringstream iss(str);
    std::string line;

    while (std::getline(iss, line, '\n')) {
        std::deque<Token> tokens;
        std::istringstream lineIss(line);
        std::string token;
        while (lineIss >> token) {
            std::string type = "unknown";
            // Check if the token is a keyword
            if (token == "int" || token == "return")
                type = "keyword";
                // Check if the token is a numeric constant
            else if (std::all_of(token.begin(), token.end(), ::isdigit))
                type = "constant";
                // Check if the token is an identifier (variable name)
            else if (std::isalpha(token[0]) || token[0] == '_')
                type = "identifier";
                // Check if the token is an operator
            else if (token == "=" || token == "+"||token == "*" || token == "/")
                type = "operator";
                // Check if the token is a semicolon
            else if (token == ";")
                {}//DO NOTHING
            tokens.emplace_back(token, type);
        }
        lines.push_back(tokens);
    }

    return lines;
}

std::string compile(std::deque<std::deque<Token>> token) {
    std::string asm_src;

    while (!token.empty()) {
        std::deque<Token> cur_line = token.front();
        while (!cur_line.empty()) {
            if (cur_line.front().value == "return") {
                // exit program
                cur_line.pop_front();
                Token val_to_return = cur_line.front();
                if (val_to_return.type == "constant") {
                    asm_src += "li $v0,";
                    asm_src += val_to_return.value;
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
                    asm_src += "($fp)";
                }
                asm_src += "lw $v0, -12($fp)";
            }
            if (cur_line.front().value == "int") {
                // 声明 eg: int a;
                cur_line.pop_front();
                Token symbol = cur_line.front();
                if (symbol.type != "identifier") {
                    asm_src += "Compile Error: Unknown Syntax";
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

            }
            else{
                std::cout<<"Unknown Token"<<std::endl;
            }
        }
        token.pop_front();
        asm_src += "\n";
    }
}

std::string eval(std::deque<Token> leftExp) {
    // a fuction that evaluate left expression
    std::string asm_src = "";
    if (!isValidLeftExpression(leftExp)) {
        asm_src += "Syntax Error: Invalid Left Exp";
    }
    // load ops and values into stack
    //lw $v0, -4($fp) 
    //sw $v0, 0($sp)
    //addiu $sp, $sp, -4
    //lw $v0, -8($fp)
    //sw $v0, 0($sp)
    //addiu $sp, $sp, -4
    std::stack<Token> ops;
    int stack_counter = 1;
    pushToken(leftExp.front());
    leftExp.pop_front();
    while (!leftExp.empty()) {
        ops.push(leftExp.front());
        leftExp.pop_front();
        pushToken(leftExp.front());
        leftExp.pop_front();
    }
    // calculate
    // lw $t1, 4($sp)
    // lw $t0, 8($sp)
    // add $t0, $t0, $t1
    while (!ops.empty()) {
        asm_src += "lw $t1, " + std::to_string(stack_counter * 4) + "($sp)\n";
        asm_src += "lw $t0, " + std::to_string((stack_counter + 1) * 4) + "($sp)\n";
        Token op = ops.top();

        // 翻译为不同的汇编指令
        if (op.value == "+") {
            asm_src += "add $t0, $t0, $t1\n";
        } else if (op.value == "-") {
            asm_src += "sub $t0, $t0, $t1\n";
        } else if (op.value == "*") {
            asm_src += "mul $t0, $t0, $t1\n";
        } else if (op.value == "/") {
            asm_src += "div $t0, $t0, $t1\n";
        }
        ops.pop();  
        asm_src+="sw $t0, 8($sp)";
        asm_src+="addiu $sp, $sp, 4";
    }
    //复原stack,储存回fp
    asm_src+="lw $v0, 4($sp)\n";
    asm_src +="addiu $sp, $sp, 4\n";
    return asm_src;
}

bool isValidLeftExpression(const std::deque<Token>& leftExp) {
    if (leftExp.empty()) {
        return false;
    }
    if (leftExp.front().type != "constant" &&
        leftExp.front().type != "identifier") {
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

std::string pushToken(Token t) {
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


void printTokens(const std::deque<std::deque<Token>>& tokens) {
    for (const auto& line : tokens) {
        for (const auto& token : line) {
            std::cout << "Value: " << token.value << ", Type: " << token.type << std::endl;
        }
        std::cout << std::endl;  // 打印每一行之间的空行
    }
}
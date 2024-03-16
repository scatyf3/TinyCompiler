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
        inputFile.close();

        std::deque<std::deque<Token>> token = tokenize(sourceCode);
        std::string output = compile(token);
        std::cout << output << std::endl;
    } else {
        std::cout << "无法打开源代码文件." << std::endl;
    }

    return 0;
}

std::deque<std::deque<Token>> tokenize(const std::string& str) {
    std::deque<std::deque<Token>> tokenGroups;
    std::deque<Token> currentGroup;
    std::regex keyword("\\b(int|return)\\b");
    std::regex identifier("\\b[a-zA-Z]+\\b");
    std::regex constant(R"(\b\d+\b)");
    std::regex operatorRegex("[=+\\-*/]");
    std::regex delimiter(";");
    std::istringstream iss(str);
    std::string line;
    while (std::getline(iss, line)) {
        std::smatch match;
        std::string remaining = line;
        while (std::regex_search(remaining, match, keyword)) {
            currentGroup.emplace_back(match.str(), "keyword");
            remaining = match.suffix().str();
        }
        while (std::regex_search(remaining, match, identifier)) {
            currentGroup.emplace_back(match.str(), "identifier");
            remaining = match.suffix().str();
        }
        while (std::regex_search(remaining, match, constant)) {
            currentGroup.push_back(Token(match.str(), "constant"));
            remaining = match.suffix().str();
        }
        while (std::regex_search(remaining, match, operatorRegex)) {
            currentGroup.push_back(Token(match.str(), "operator"));
            remaining = match.suffix().str();
        }
        while (std::regex_search(remaining, match, delimiter)) {
            currentGroup.push_back(Token(match.str(), "delimiter"));
            tokenGroups.push_back(currentGroup);
            currentGroup.clear();
            remaining = match.suffix().str();
        }
    }
    return tokenGroups;
}

std::string compile(std::deque<std::deque<Token>> token) {
    std::string asm_src = "";

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
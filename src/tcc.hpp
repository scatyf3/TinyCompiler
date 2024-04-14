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
bool checkBrackets(const std::deque<Token> token);
bool process_main(std::deque<Token> token);
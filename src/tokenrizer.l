%{
#include "../src/tcc.hpp"
std::deque<Token> token;
%}

%option noyywrap

%%
[+*-/%=!<>]           { token.push_back(Token(yytext, "operator")); }
"|"                { token.push_back(Token(yytext, "operator"));}
"^"                { token.push_back(Token(yytext, "operator"));}
"&"                { token.push_back(Token(yytext, "operator"));}
"<="                { token.push_back(Token(yytext, "operator"));}
">="                { token.push_back(Token(yytext, "operator"));}
"=="                {token.push_back(Token(yytext, "operator"));}
"!="                { token.push_back(Token(yytext, "operator"));}
"&&"                { token.push_back(Token(yytext, "operator"));}
"||"                { token.push_back(Token(yytext, "operator"));}
";"                     { token.push_back(Token(yytext, "semicolon"));}
"int"                    { token.push_back(Token(yytext, "keyword")); }
"return"                   { token.push_back(Token(yytext, "keyword")); }
"main"                   { token.push_back(Token(yytext, "keyword")); }
"println_int"            { token.push_back(Token(yytext, "std_function")); }
"("|")"|"{"|"}"                    { token.push_back(Token(yytext, "brackets")); }
[0-9]+                { token.push_back(Token(yytext, "constant")); }
[A-Za-z_][0-9A-Za-z_]*                   { token.push_back(Token(yytext, "identifier")); }
[ \n\t\r\a]+          { /* ignore all spaces */               }
.                     { printf("未识别的字符 %c，ASCII 编码：%d\n", *yytext, *yytext); }
<<EOF>>                  { return 0; }
%%


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }
    std::string filename = argv[1];  // 获取文件名
    yyin = fopen(filename.c_str(), "r");  // 使用文件名打开文件
    yylex();
    // for debug
    //printTokens(token);
    //std::cout << "=======" << std::endl;
    std::string output = compile(token);
    std::cout << output << std::endl;
    return 0;
}
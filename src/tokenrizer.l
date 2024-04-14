%{
#include "../src/tcc.hpp"
std::deque<Token> token;
%}

%option noyywrap
WORD		([^ \t\n\r\a]+)

%%
println_int         { token.push_back(Token(yytext, "std_function")); }
println_string     { token.push_back(Token(yytext, "std_function")); }
int   { token.push_back(Token(yytext, "keyword")); }
return   { token.push_back(Token(yytext, "keyword")); }
main                    { token.push_back(Token(yytext, "keyword")); }
[{|}|}(|)]                    { token.push_back(Token(yytext, "brackets")); }
[;]                      { token.push_back(Token(yytext, "semicolon"));}
[A-Za-z_][0-9A-Za-z_]*                 { token.push_back(Token(yytext, "identifier")); }
[0-9]+                   { token.push_back(Token(yytext, "constant")); }
[=|+|-|*|/|%|<|<=|>|>=|!=|&|||^]              { token.push_back(Token(yytext, "operator")); }
[&][&]|[|][|]            { token.push_back(Token(yytext, "operator")); }
[[:space:]]+             ; // Ignore whitespace
.                        ; // Ignore unrecognized characters
<<EOF>>                  { return 0; }
%%

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
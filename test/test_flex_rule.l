%{
#include "../src/tcc.hpp"
std::deque<Token> token;
%}

%option noyywrap
WORD		([^ \t\n\r\a]+)

%%
println_int         { token.push_back(Token(yytext, "std_function")); }
println_string     { token.push_back(Token(yytext, "std_function")); }
int[[:space:]]+ { token.push_back(Token(yytext, "keyword")); }
return[[:space:]]+ { token.push_back(Token(yytext, "keyword")); }
main                    { token.push_back(Token(yytext, "keyword")); }
[{|}|}(|)]                    { token.push_back(Token(yytext, "brackets")); }
[;]                      { token.push_back(Token(yytext, "semicolon"));}
[A-Za-z_][0-9A-Za-z_]*                 { token.push_back(Token(yytext, "identifier")); }
[0-9]+                   { token.push_back(Token(yytext, "constant")); }
[=|+|-|*|/|%|<|<=|>|>=|!=|&|||^]              { token.push_back(Token(yytext, "operator")); }
[&][&]|[|][|]            { token.push_back(Token(yytext, "operator")); }
[[:space:]]+             ; // Ignore whitespace
.                        ; // Ignore unrecognized characters
%%
int main(){
    std::cout<<"processing IO"<<std::endl;
    //yyin = "int a;\na=1;"; //yyin 默认为stdin
    yyin = fopen("../test/testcase.minic", "r");
    //结论：使用c++风格的fileio会出事情
    std::cout<<"call yylex"<<std::endl;
    yylex();
    std::cout<<"show tokens"<<std::endl;
    printTokens(token);
    return 0;
}
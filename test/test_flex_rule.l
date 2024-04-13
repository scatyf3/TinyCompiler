%{
#include "../src/tcc.hpp"
std::deque<Token> token;
%}

%option noyywrap
WORD		([^ \t\n\r\a]+)

%%
[int][[:space:]]+        { token.push_back(Token(yytext, "keyword") ); }
[return][[:space:]]+     { token.push_back(Token(yytext, "keyword") ); }
[;]                      { token.push_back(Token(yytext, "semicolon"));}
[a-zA-Z]+                 { token.push_back(Token(yytext, "identifier")); }
[0-9]+                   { token.push_back(Token(yytext, "constant")); }
[=|+|-|*|/]              { token.push_back(Token(yytext, "operator")); }
[[:space:]]+             ; // Ignore whitespace
.                        ; // Ignore unrecognized characters
<<EOF>>                  { return 0; }
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
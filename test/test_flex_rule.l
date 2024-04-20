%{
#include "../src/tcc.hpp"
std::deque<Token> token;
int cur_line_num = 1;
void lex_error(char* msg, int line);
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
[\n]                { cur_line_num++;                       }
[\t\r\a]+          { /* ignore all spaces */               }
<<EOF>>                  { return 0; }
%%


int main(){
    std::cout<<"processing IO"<<std::endl;
    yyin = fopen("../test/cases_2/e05.c", "r");
    //结论：使用c++风格的fileio会出事情
    std::cout<<"call yylex"<<std::endl;
    yylex();
    std::cout<<"show tokens"<<std::endl;
    printTokens(token);
    return 0;
}
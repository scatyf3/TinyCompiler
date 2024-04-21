%{
#include "../src/tcc.hpp"
std::deque<Token> token;
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
[ \n\t\r\a]+          { /* ignore all spaces */               }
<<EOF>>                  { return 0; }
%%


int main(){
    std::cout<<"processing IO"<<std::endl;
    yyin = fopen("../test/cases_2/e02.c", "r");
    //结论：使用c++风格的fileio会出事情
    printf("call yylex\n");
    yylex(); //会打印出额外的空格和换行？？？
    printf("show tokens\n");
    fflush(stdout);
    printTokens(token);
    return 0;
}
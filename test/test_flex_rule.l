%{
#define YYSTYPE char *
#include <iostream>
#include <fstream>
#include <string>
#include "../build/y.tab.h"
void unrecognized_char(char c);
void yyerror(const char* s);
int cur_line = 1;
%}


OPERATOR        [-/+*<>|^&,%!~]
INTEGER         [0-9]+
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
WHITESPACE      [ \n\t\r\a]+*


%%
{OPERATOR}          { return yytext[0]; }
"="                 { return T_assign;}
";"                 { return T_semicolon;}
"("                 { return yytext[0];}
")"                 { return yytext[0];}
"{"                 { return yytext[0];}
"}"                 { return yytext[0];}
"<="                { return T_Le;}
">="                { return T_Ge;}
"=="                { return T_Eq;}
"!="                { return T_Ne;}
"&&"                { return T_And;}
"||"                { return T_Or;}
"int"                     { return T_int; }
"void"                    { return T_void; }
"return"                 { return T_return; }
"main"                   { return T_main; }
"println_int"            { return T_std_function; }
"if"                     { return T_if; }
"else"                   { return T_else; }
"while"                  { return T_while; }
"continue"               { return T_continue; }
"break"                  { return T_break; }
{INTEGER}                { yylval = strdup(yytext); return T_IntConstant; }
{IDENTIFIER}             { yylval = strdup(yytext); return T_Identifier; }
"\n"                     {cur_line++;}
{WHITESPACE}             { /* ignore all spaces */               }
.                        {/*printf("未识别的字符 %c，ASCII 编码：%d\n", *yytext, *yytext); */ }
<<EOF>>                  { return 0; }
%%

int yywrap(void) { 
    return 1;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        yy_scan_string(line.c_str());
        int token;
        while ((token = yylex()) != 0) {
            std::cout << "Token: " << token << ", Value: " << yytext << std::endl;
        }
    }

    input_file.close();
    return 0;
}
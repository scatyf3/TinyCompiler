%{
#define YYSTYPE char *
#include <iostream>
#include <string>
#include "../build/y.tab.h"
int cur_line = 1;
void yyerror(const char *msg);
void unrecognized_char(char c);
%}


OPERATOR        [-/+*()=;<>(){}|^&,]
INTEGER         [0-9]+
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
WHITESPACE      [ \n\t\r\a]+*


%%
{OPERATOR}          { return T_operator; }
"<="                { return T_operator;}
">="                { return T_operator;}
"=="                { return T_operator;}
"!="                { return T_operator;}
"&&"                { return T_operator;}
"||"                { return T_operator;}
"int"                    { return T_keyword; }
"return"                 { return T_keyword; }
"main"                   { return T_keyword; }
"println_int"            { return T_std_function; }
{INTEGER}                { yylval = strdup(yytext); return T_IntConstant; }
{IDENTIFIER}             { yylval = strdup(yytext); return T_Identifier; }
{WHITESPACE}             { /* ignore all spaces */               }
.                        {/*printf("未识别的字符 %c，ASCII 编码：%d\n", *yytext, *yytext); */ }
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
    return 0;
}

int yywrap(void) { 
    return 1;
}

void unrecognized_char(char c) {
    char buf[32] = "Unrecognized character: ?";
    buf[24] = c;
    yyerror(buf);
}

void yyerror(const char *msg) {
    printf("Error at line %d:\n\t%s\n", cur_line, msg);
    exit(1);
}
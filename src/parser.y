%{
#include <stdio.h>
#include <stdlib.h>
#ifdef YYDEBUG
  yydebug = 1;
#endif
int yylex(void); // 声明 yylex 函数
void yyerror(const char*);
#define YYSTYPE char *
%}

%token T_IntConstant T_Identifier

%left '+' '-'
%left '*' '/'
%right U_neg

%%

//start
S   :   Stmt
    |   S Stmt
    ;
//statement
Stmt:   T_Identifier '=' E ';'  { printf("pop %s\n\n", $1); }
    ;
//expression
E   :   E '+' E                 { printf("add\n"); }
    |   E '-' E                 { printf("sub\n"); }
    |   E '*' E                 { printf("mul\n"); }
    |   E '/' E                 { printf("div\n"); }
    |   '-' E %prec U_neg       { printf("neg\n"); }
    |   T_IntConstant           { printf("push %s\n", $1); }
    |   T_Identifier            { printf("push %s\n", $1); }
    |   '(' E ')'               { /* empty */ }
    ;

%%

int main() {
    return yyparse();
}
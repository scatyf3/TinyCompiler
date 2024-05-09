%{
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include "../src/MIPS.h"
void yyerror(const char*);
int yylex(void);
#define YYSTYPE char *
std::vector<std::string> sign_table; //符号表
std::string asm_src; //生成的汇编码
int searchAndCalculateOffset(const char* symbol,std::vector<std::string> sign_table);
extern "C" FILE* yyin;
void printSignTable(const std::vector<std::string>& sign_table) {
    std::cout << "Symbol Table Elements:" << std::endl;
    for (const std::string& symbol : sign_table) {
        std::cout << symbol << std::endl;
    }
}
%}


%token T_Identifier T_IntConstant
%token T_std_function
%token T_keyword
%token T_operator
%token T_Type
%token T_return
%token T_assign
%token T_semicolon
%token T_main
%token T_Le T_Ge T_Eq T_Ne T_And T_Or

%left '='
%left T_Or
%left T_And
%left T_Eq T_Ne
%left '<' '>' T_Le T_Ge
%left '+' '-'
%left '*' '/' '%'
%left '!'

%%

S   :   EntryPoint '{' StmtList '}' { };

EntryPoint : T_Type T_main '(' MainArgList ')' { MAIN(); };

StmtList:  Stmt
         | StmtList Stmt
         | DeclStmt
         | StmtList DeclStmt
         | ReturnStmt
         | StmtList ReturnStmt
         | StdFuncStmt
         | StmtList StdFuncStmt
         ;


MainArgList: /* empty */
        | T_Type T_Identifier T_Type T_Identifier
        ;


DeclStmt:   T_Type T_Identifier T_semicolon  { 
    sign_table.push_back($2);//todo char* 2 std::string，但是好像发现打印出来是正常的，先不管了
    printf("sw $zero,%d($fp)\n",(sign_table.size()*-4)); //这里不能按warning操作，否则有问题
    //printSignTable(sign_table);
 }
    ;

Stmt:   T_Identifier T_assign E T_semicolon  { 
    //默认将E计算结果放到$v0
    int offset=searchAndCalculateOffset($2,sign_table);
    //加载栈顶元素，即右边表达式运算结果到$v0
    MIPS_POP("$v0");
    printf("sw $v0,%d($fp)\n",offset);
};


ReturnStmt: ReturnVar
          | ReturnConst
          ;

ReturnVar:   T_return T_Identifier T_semicolon  { 
    int offset = searchAndCalculateOffset($2,sign_table);
    printf("lw $v0, %d($fp)\n", offset);    
};

ReturnConst: T_return T_IntConstant T_semicolon { 
    printf("li $v0, %s\n", $2);
};


StdFuncStmt:   T_std_function ArgList T_semicolon  { 
    PRINT();
};

ArgList: MainArgList
       | FuncArgList
       ;

FuncArgList: '(' E ')' {
                MIPS_POP("$a0");
            }
           | '(' T_IntConstant ')' { printf("li $a0, %s",$1); }
           | '(' T_Identifier ')' {
            int offset = searchAndCalculateOffset($2,sign_table);
            printf("lw $a0, %d($fp)\n", offset); 
           }
           ;


E: E '+' E {
    EVAL_PRE();
    printf("add $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '-' E {
    EVAL_PRE();
    printf("sub $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '*' E {
    EVAL_PRE();
    printf("mul $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '/' E {
    EVAL_PRE();
    printf("div $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '%' E {
    EVAL_PRE();
    printf("rem $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '>' E {
    EVAL_PRE();
    printf("slt $t0, $t1, $t0\n");
    EVAL_AFTER();
}
| E '<' E {
    EVAL_PRE();
    printf("slt $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E T_Ge E {
    EVAL_PRE();
    printf("slt $t0, $t0, $t1\n");
    printf("xori $t0, $t0, 1\n");
    EVAL_AFTER();
}
| E T_Le E {
    EVAL_PRE();
    printf("slt $t0, $t1, $t0\n");
    printf("xori $t0, $t0, 1\n");
    EVAL_AFTER();
}
| E T_Eq E {
    EVAL_PRE();
    printf("seq $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E T_Ne E {
    EVAL_PRE();
    printf("sne $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E T_Or E {
    EVAL_PRE();
    printf("or $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E T_And E {
    EVAL_PRE();
    printf("and $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '^' E {
    EVAL_PRE();
    printf("xor $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '|' E {
    EVAL_PRE();
    printf("or $t0, $t0, $t1\n");
    EVAL_AFTER();
}
| E '&' E {
    EVAL_PRE();
    printf("and $t0, $t0, $t1\n");
    EVAL_AFTER();
}
    |   '-' E %prec '!'      { printf("\tneg "); /*暂时不用支持*/ }
    |   '!' E                { printf("\tnot "); /*暂时不用支持*/ }
    |   T_IntConstant            { 
            //push const not work?
            MIPS_PUSH_CONST($1);
        }
    |   T_Identifier             { 
            int offset=searchAndCalculateOffset($1,sign_table); 
            MIPS_PUSH_VARS(offset);
        }
    |   '(' E ')'                { /* empty */ }
;

%%


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }
    std::string filename = argv[1];  // 获取文件名
    yyin = fopen(filename.c_str(), "r");
    return yyparse();;
}

%{
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <stdlib.h>
#include <cstring>
#include "../src/MIPS.h"
void yyerror(const char*);
int yylex(void);
#define YYSTYPE char *
std::string asm_src; //生成的汇编码
int searchAndCalculateOffset(const char* symbol,std::vector<std::string> sign_table);
extern "C" FILE* yyin;
void printSignTable(const std::vector<std::pair<SymbolType, std::string>>& sign_table);
std::vector<std::pair<SymbolType, std::string>> sign_table;
std::map<std::string, std::vector<std::pair<SymbolType, std::string>>> frames; //全局的frame，可能解析符号表有用，但是也可能改成vector of string
std::stack<std::vector<std::pair<SymbolType, std::string>>> frame_stack;
std::vector<std::string> functions;
%}

%error-verbose



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
%left '!' '^' '|' '&'


%%




Program:
    /* empty */                     { /* empty */ }
|   Program FuncDef                 { /* empty */ }
;


FuncDef: T_Type _FuncDef {
        printf("%s:\n",$1);
        printf("addiu $sp, $sp, -4\n");
        printf("sw $ra, 0($sp)\n");
        printf("sw $fp, 4($sp)\n");
        printf("move $fp, $sp\n");
        printf("addiu $sp, $sp, -4\n");
        //functions.push_back($1);
        std::vector<std::pair<SymbolType, std::string>> sign_table;
        printSignTable(sign_table);
        frames.insert(std::make_pair(std::string($1),sign_table));
}
        | T_Type _FuncMain {
        //GLOBL($1);
        //functions.push_back(std::string($1));
        MAIN(); 
        std::vector<std::pair<SymbolType, std::string>> sign_table_main;
        printSignTable(sign_table_main);
        frames.insert(std::make_pair("main",sign_table_main));
        frame_stack.push(sign_table_main);
        sign_table = sign_table_main;
        }
;


_FuncDef : T_Identifier Args BeginFuncDef Stmts EndFuncDef{
    FUNC_RETURN();
    printf("# end of func %s def\n", $1);
}
;
_FuncMain : T_main Args BeginFuncDef Stmts EndFuncDef {
    MAIN_RETURN();
    printf("# end of func %s def\n", $1);
}
;


BeginFuncDef : '{' {}


Args:
    '(' ')'                         { /*printf("args empty");*/ }
|   '(' _Args ')'                   { /*printf("args full");*/ }
;

_Args:
    T_Type T_Identifier              {
        /*建立起参数和*/
        sign_table.push_back(std::make_pair(SymbolType::FUNC_ARG,std::string($2)));
        printSignTable(sign_table);
        printf("#end of sign_table def\n\n");
    }
    |   _Args ',' T_Type T_Identifier    { 
        sign_table.push_back(std::make_pair(SymbolType::FUNC_ARG,std::string($4)));
        printSignTable(sign_table);
    }
;


Stmts:
    /* empty */                     { /* empty */ }
|   Stmts Stmt                      { /* empty */ }
;

/*这个规则出现在奇怪的地方...*/

EndFuncDef:
    '}'                             {  }
;


Stmt:      AssignStmt 
         | DeclStmt
         | DeclAssignStmt
         | ReturnStmt 
         | StdFuncStmt 
         | FuncCallStmt
         ;


DeclStmt:   T_Type DeclList T_semicolon  { 
    printf("# this is an DeclStmt\n");
    //sign_table.push_back($2);//todo char* 2 std::string，但是好像发现打印出来是正常的，先不管了
    //printf("sw $zero,%d($fp)\n",(sign_table.size()*-4)); //这里不能按warning操作，否则有问题
    //printSignTable(sign_table);
    //printSignTable(sign_table);
    //交给DeclList处理
    printf("\n");
 };

DeclList:  T_Identifier  { 
    printf("# this is an DeclStmt\n");
    sign_table.push_back(std::make_pair(SymbolType::LOCAL_VAR,std::string($1)));
    printSignTable(sign_table);
    printf("sw $zero,%d($fp)\n",(sign_table.size()*-4));
    printf("#end of DeclList\n\n");
} 
|   DeclList ',' T_Identifier  { 
    printf("# this is an DeclStmt\n");
    sign_table.push_back(std::make_pair(SymbolType::LOCAL_VAR,std::string($3)));
    printSignTable(sign_table);
    printf("sw $zero,%d($fp)\n",(sign_table.size()*-4));
};

DeclAssignStmt:   T_Type DeclAssignList T_semicolon  { };

DeclAssignList:   T_Identifier T_assign E  { 
    sign_table.push_back(std::make_pair(SymbolType::LOCAL_VAR,std::string($1)));
    printSignTable(sign_table);
    int offset=searchAndCalculateOffset($1,sign_table);
    //MIPS_POP("$v0");->处理E不是单个变量或者const的情况->可能要统一e的返回值，到底在$v0还是stack顶
    MIPS_POP("$v0");
    printf("sw $v0,%d($fp)\n",offset);
    printf("\n");
    printf("#end of DeclAssignList\n\n");
} 
|   DeclAssignList ',' T_Identifier T_assign E  { 
    sign_table.push_back(std::make_pair(SymbolType::LOCAL_VAR,std::string($3)));
    printSignTable(sign_table);
    int offset=searchAndCalculateOffset($3,sign_table);
    //MIPS_POP("$v0");
    MIPS_POP("$v0");
    printf("sw $v0,%d($fp)\n",offset);
    printf("\n");
};


AssignStmt:   T_Identifier T_assign E T_semicolon  { 
    printf("# start of assign stmt\n");
    //默认将E计算结果放到$v0
    int offset=searchAndCalculateOffset($2,sign_table);
    //加载栈顶元素，即右边表达式运算结果到$v0
    MIPS_POP("$v0");
    printf("sw $v0,%d($fp)\n",offset);
    printf("\n");
    printf("# end of assign stmt\n");
};


ReturnStmt: ReturnVar
          | ReturnConst 
          ;

ReturnVar:   T_return T_Identifier T_semicolon  { 
    printf("# start of return stmt\n");
    int offset = searchAndCalculateOffset($2,sign_table);
    printf("lw $v0, %d($fp)\n", offset);   
    //sign_table = frame_stack.top(); 
    //frame_stack.pop();
    printSignTable(sign_table);
    printf("# end of return stmt\n");
};

ReturnConst: T_return T_IntConstant T_semicolon { 
    printf("li $v0, %s\n", $2);
    //sign_table = frame_stack.top(); 
    //frame_stack.pop();
    printSignTable(sign_table);
    printf("# end of return stmt\n");
};


StdFuncStmt:  T_std_function Actuals T_semicolon  { 
    /*从栈中获取参数*/
    MIPS_POP("$a0");
    PRINT();
};


FuncCallStmt:
    FuncCallExpr T_semicolon { 
        //printf("jal %s\n",$1); ->这里是不是$1是空的😨
        //std::vector<std::pair<SymbolType, std::string>> sign_table_main; //不确定
        //FUNC_RETURN();  这是函数定义里的return，而不是实际的return
        
        //std::string identifier = std::string("sign_table_") + $1;
        //sign_table = frames[identifier];
        //frame_stack.push(sign_table);
        //std::cout<<"# "<<identifier<<std::endl;
        printSignTable(sign_table);
        FUNC_CALL_RETURN();
    }
;

FuncCallExpr:    
        T_Identifier Actuals { 
        printf("jal %s\n",$1);
        std::vector<std::pair<SymbolType, std::string>> sign_table_main; //不确定
        //FUNC_RETURN();  这是函数定义里的return，而不是实际的return
        
        //std::string identifier = std::string("sign_table_") + $1;
        //sign_table = frames[identifier];
        //frame_stack.push(sign_table);
        //std::cout<<"# "<<identifier<<std::endl;
        printSignTable(sign_table);
        FUNC_CALL_RETURN();
    }
;


Actuals:    '(' ')'   {  }
       |   '(' _Actuals ')'   { }
       ;
_Actuals:
    E                  { 
        printf("### Passing the arguments %s\n\n",$1);
        MIPS_POP("$v0");
        printf("sw $v0, 0($sp)\n"); 
        printf("addiu $sp, $sp, -4\n"); 
        
     }
    |   _Actuals ',' E     { 
        printf("### Passing the arguments %s\n",$3); 
        MIPS_POP("$v0");
        printf("sw $v0, 0($sp)\n"); 
        printf("addiu $sp, $sp, -4\n"); 
        printf("### End of passing the arguments \n");
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
    | FuncCallExpr
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
    // 缓存yyparse的结果
    yyparse();
    return 0;
}

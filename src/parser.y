%{
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <set>
#include <stack>
#include <algorithm>
#include "../src/MIPS.h"
#include "../src/sign_table.hpp"
void yyerror(const char*);
int yylex(void);
#define YYSTYPE char *
std::string asm_src; //生成的汇编码
int searchAndCalculateOffset(const char* symbol,std::vector<std::string> sign_table);
extern "C" FILE* yyin;
std::set<SignTable *> functions;
SignTable* sign_table;
std::stack<int> loop_stack;
int loop_counter = 0;
int if_counter = 0;
%}

%error-verbose


%token T_Identifier T_IntConstant
%token T_std_function
%token T_keyword
%token T_operator
%token T_int T_void
%token T_return
%token T_assign
%token T_semicolon
%token T_main
%token T_Le T_Ge T_Eq T_Ne T_And T_Or
%token T_if T_else T_while T_continue T_break

%left '='
%left T_Or
%left T_And
%left T_Eq T_Ne
%left '<' '>' T_Le T_Ge
%left '|' '&' '^' 
%left '+' '-'
%left '*' '/' '%'
%left '!' 



%%




Program:
    /* empty */                     { /*end of program?*/ }
|   Program FuncDef                 { /* empty */ }
;


FuncDef:
    T_int FuncName Args '{' Stmts '}' { FUNC_RETURN();}
|   T_void FuncName Args '{' Stmts '}' { FUNC_RETURN(); }
;

FuncName:
    T_Identifier                    { 
        intermediate_code+= std::string($1)+":\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        intermediate_code += "sw $ra, 0($sp)\n";
        intermediate_code += "sw $fp, 4($sp)\n";
        intermediate_code += "move $fp, $sp\n";
        intermediate_code += "addiu $sp, $sp, -0x100\n"; //这里是多少其实不重要🤔，只要大于local var的数目就好
        sign_table = new SignTable(std::string($1));
        intermediate_code+=sign_table->printSignTable();
        functions.insert(sign_table);
        debug_log<<"FUNC @"<<std::string($1)<<":\n";
        }
    | T_main {
        MAIN(); 
        sign_table = new SignTable(std::string("main"));
        intermediate_code+=sign_table->printSignTable();
        functions.insert(sign_table);
    }
;



Args:
    '(' ')'                         { /*printf("args empty");*/ }
|   '(' _Args ')'                   { debug_log<<"ARGLIST:"<<" \n";}
;

_Args:
    T_int T_Identifier              {
        sign_table->addSymbol(Symbol(SymbolType::FUNC_ARG,std::string($2)));
        intermediate_code+=sign_table->printSignTable();
        debug_log<<" "<<std::string($2)<<" \n";
    }
    |   _Args ',' T_int T_Identifier    { 
        sign_table->addSymbol(Symbol(SymbolType::FUNC_ARG,std::string($4)));
        intermediate_code+=sign_table->printSignTable();
        debug_log<<" "<<std::string($4)<<" \n";
    }
;


Stmts:
    /* empty */                     { /* empty */ }
|   Stmts Stmt                      { /* empty */ }
;


Stmt:      DeclStmt
         | AssignStmt
         | ReturnStmt 
         | StdFuncStmt 
         | FuncCallStmt
         | BranchStmt
         | LoopStmt
         | BreakStmt
         | ContStmt
         ;


DeclStmt:   T_int DeclList T_semicolon  { 
    intermediate_code += "# this is a DeclStmt\n";
    //sign_table.push_back($2);//todo char* 2 std::string，但是好像发现打印出来是正常的，先不管了
    //printf("sw $zero,%d($fp)\n",(sign_table.size()*-4)); //这里不能按warning操作，否则有问题
    //printSignTable(sign_table);
    //交给DeclList处理
    intermediate_code += "\n";
};

DeclList:  T_Identifier  { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string($1)));
    intermediate_code+=sign_table->printSignTable();
    //通过类型转换避免错误😠
    intermediate_code += "sw $zero, " + std::to_string(-(static_cast<int64_t>(sign_table->size()) * 4)) + "($fp)\n";
    intermediate_code += "# end of DeclList\n\n";
    debug_log<<"var "<<std::string($1)<<"\n";
} 
|   T_Identifier T_assign E  { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string($1)));
    intermediate_code+=sign_table->printSignTable();
    int offset=sign_table->searchAndCalculateOffset(std::string($1));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    intermediate_code += "# end of DeclList\n\n";
    debug_log<<"assign "<<std::string($1)<<"=\n";
}
|   DeclList ',' T_Identifier  { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string($3)));
    intermediate_code+=sign_table->printSignTable();
    intermediate_code += "sw $zero, " + std::to_string(-(static_cast<int64_t>(sign_table->size()) * 4)) + "($fp)\n";
    debug_log<<"var "<<std::string($3)<<"\n";
    intermediate_code += "# end of DeclList\n\n";
}
|   DeclList ',' T_Identifier T_assign E  { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string($3)));
    intermediate_code+=sign_table->printSignTable();
    int offset=sign_table->searchAndCalculateOffset(std::string($3));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    debug_log<<"assign "<<std::string($3)<<"=\n";
    intermediate_code += "# end of DeclList\n\n";
};


AssignStmt:   T_Identifier T_assign E T_semicolon  { 
    intermediate_code += "# start of assign stmt\n";
    int offset=sign_table->searchAndCalculateOffset(std::string($2));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    intermediate_code += "\n";
    intermediate_code += "# end of assign stmt\n";
    debug_log<<"assign "<<std::string($1)<<"=\n";
};

ReturnStmt: T_return E T_semicolon {MIPS_POP("$v0");}
          ;

StdFuncStmt:  T_std_function Actuals T_semicolon  { 
    /*从栈中获取参数*/
    MIPS_POP("$a0");
    PRINT();
    debug_log<<"print"<<"\n";
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
        intermediate_code+=sign_table->printSignTable();
        debug_log<<"call";
    }
;

FuncCallExpr:    
    T_Identifier Actuals { 
        debug_log << "function " << std::string($1) << "\n";
        intermediate_code += "jal " + std::string($1) + "\n";
        intermediate_code += sign_table->printSignTable();

        // 计算被调用者参数的数目,计算 return 需要清理的 stack 空间
        int calleeParamCount = sign_table->get_nums_func_arg();
        
        // 查找上一个函数的 SignTable
        std::string prevFunctionName = std::string($1);
        bool found = false;
        SignTable* prev_sign_table = nullptr;
        for (auto it = functions.begin(); it != functions.end(); ++it) {
            if ((*it)->getIdentifier() == prevFunctionName) {
                prev_sign_table = *it;
                found = true;
                break;
            }
        }
        if (found) {
            int prevParamCount = prev_sign_table->get_nums_func_arg();
            
            intermediate_code += "# 生成清理 stack 的指令\n";
            intermediate_code += "addiu $sp, $sp, " + std::to_string(prevParamCount * 4) + "\n";
            //push ?
            intermediate_code += "sw $v0, 0($sp)\n";
            intermediate_code += "addiu $sp, $sp, -4\n";
        }
    }
;


Actuals:    '(' ')'   {  }
       |   '(' _Actuals ')'   { }
       ;

_Actuals:
    E   {
        intermediate_code += "### Passing the arguments " + std::string($1) + "\n\n";
        MIPS_POP("$v0");
        intermediate_code += "sw $v0, 0($sp)\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        debug_log<<std::string($1)<<"\n";
    }
    |   E ',' _Actuals     {
        intermediate_code += "### Passing the arguments " + std::string($1) + "\n";
        MIPS_POP("$v0");
        intermediate_code += "sw $v0, 0($sp)\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        intermediate_code += "### End of passing the arguments \n";
        debug_log<<std::string($1)<<"\n";
    }
;

//TODO j if end

BranchStmt : 
    T_if '(' TrueFalseExpressionIF ')' '{' Stmts '}' EndIf ElseStmts{ 
        debug_log<<"if stmt"<<"\n"; 
    }
    ;

EndIf: { intermediate_code+="j $if_end_"+ std::to_string(if_counter) + ";\n";};

ElseStmts : ElseDO EndElseStmt {/*else有可能为空，但是打tag的两个空推导不能删除🤔*/}
          |  T_else T_if '(' TrueFalseExpressionIF ')' '{' Stmts '}' ElseStmts {/*理论上分支语句的中间可以叠加无限的else if，但是先暂时不写这部分*/}
          |  T_else ElseDO '{' Stmts '}' EndElseStmt{ }
          ;


EndElseStmt : {
    intermediate_code+="#tag\n";
    intermediate_code += "$if_end_"+ std::to_string(if_counter) + ":\n";  
};
          

TrueFalseExpressionIF : E {
    //用栈顶数值判断if语句是否成立
    MIPS_POP("$t0");
    if_counter++;
    //if t0==0，即上面seq不相等，goto $if_else_1 else continue
    intermediate_code+="beq $t0, $zero, $if_else_"+ std::to_string(if_counter) + ";\n";
};


ElseDO : /*推导为空，打tag用*/{ 
    intermediate_code+="#tag\n";
    intermediate_code += "$if_else_"+ std::to_string(if_counter) + ":\n"; 
};

LoopStmt: T_while Cond WhileBody {
    debug_log<<"LoopCond"<<"\n"; 
};

Cond: { 
    loop_counter++;
    loop_stack.push(loop_counter);
    intermediate_code+="#tag\n";
    intermediate_code+="$while_cond_" + std::to_string(loop_counter) + ":\n"; 
};


TrueFalseExpressionLOOP : E {
    //用栈顶数值判断if语句是否成立
    MIPS_POP("$t0");
    //if t0==0，即上面seq不相等，goto $if_else_loop_counter else continue
    intermediate_code+="beq $t0, $zero, $while_end_" + std::to_string(loop_counter) + "\n";
};

WhileBody: '(' TrueFalseExpressionLOOP ')' '{' Stmts '}' { 
    debug_log<<"EndLoopBody"<<"\n"; 
    intermediate_code += "j $while_cond_" + std::to_string(loop_stack.top()) + "\n";
    
    intermediate_code+="#tag\n";
    intermediate_code += "$while_end_" + std::to_string(loop_stack.top()) + ":\n";
    loop_stack.pop();
} ;

BreakStmt: T_break T_semicolon {
    //check if is in loop
    if(loop_stack.empty()){
        intermediate_code +="Break error";
        std::exit(1);
    }else{
        intermediate_code+="# break stmt\n";
        intermediate_code += "j $while_end_" + std::to_string(loop_stack.top()) + ";\n";
    }
};

ContStmt: T_continue T_semicolon{
        //check if is in loop
    if(loop_stack.empty()){
        intermediate_code +="Continue error";
        std::exit(1);
    }else{
        intermediate_code+="# Continue stmt\n";
        intermediate_code += "j $while_cond_" + std::to_string(loop_stack.top()) + ";\n";
    }
};



E: E '+' E {
    EVAL_PRE();
    intermediate_code += "add $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tadd\n";
}
| E '-' E {
    EVAL_PRE();
    intermediate_code += "sub $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tsub\n";
}
| E '*' E {
    EVAL_PRE();
    intermediate_code += "mul $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tmul\n";
}
| E '/' E {
    EVAL_PRE();
    intermediate_code += "div $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tdiv\n";
}
| E '%' E {
    EVAL_PRE();
    intermediate_code += "rem $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\trem\n";
}
| E '>' E {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t1, $t0\n";
    EVAL_AFTER();
    debug_log << "\tgt\n";
}
| E '<' E {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tlt\n";
}
| E T_Ge E {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t0, $t1\n";
    intermediate_code += "xori $t0, $t0, 1\n";
    EVAL_AFTER();
    debug_log << "\tge\n";
}
| E T_Le E {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t1, $t0\n";
    intermediate_code += "xori $t0, $t0, 1\n";
    EVAL_AFTER();
    debug_log << "\tle\n";
}
| E T_Eq E {
    EVAL_PRE();
    intermediate_code += "seq $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\teq\n";
}
| E T_Ne E {
    EVAL_PRE();
    intermediate_code += "sne $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tne\n";
}
| E T_Or E {
    EVAL_PRE();
    intermediate_code += "or $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tor\n";
}
| E T_And E {
    EVAL_PRE();
    intermediate_code += "and $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tand\n";
}
| E '^' E {
    EVAL_PRE();
    intermediate_code += "xor $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\txor\n";
}
| '-' E  {
    MIPS_POP("$t0");
    intermediate_code += "sub $t0, $zero, $t0\n";
    //push t0 into stack
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tnegation\n";
}
| '!' E {
    MIPS_POP("$t0");
    intermediate_code += "sub $t0, $zero, $t0\n";
    //push t0 into stack
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tlogical not\n";
}
| '~' E {
    MIPS_POP("$t0");
    intermediate_code += "nor $t0, $t0, $zero\n";
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tbitwise not\n";
}
| T_IntConstant            { 
    MIPS_PUSH_CONST($1);
}
| T_Identifier             { 
    int offset = sign_table->searchAndCalculateOffset(std::string($1)); 
    MIPS_PUSH_VARS(offset);
}
| FuncCallExpr
| '(' E ')'                { /* empty */ } 
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

    // 打印符号表
    for (const auto& signTable : functions) {
        std::cout << ".globl " << signTable->getIdentifier() << std::endl;
    }
    //打印data字段
    std::cout<<".data\nnewline: .asciiz \"\\n\"\n.text\n";
    //删除最后五行，即main不使用和其他函数一样的return🤔 -> 所以return最好不要有注释？
    // 1. 找到最后 5 行的起始位置
    size_t start_pos = intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n") - 1) - 1) - 1);
    // 2. 删除最后 5 行
    intermediate_code.erase(start_pos);
    std::cout<<intermediate_code;
    //退出程序
    std::cout<<"\nli $v0, 10\nsyscall\n";
    return 0;
}
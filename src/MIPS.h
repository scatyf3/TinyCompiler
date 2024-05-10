int searchAndCalculateOffset(const char* symbol,std::vector<std::string> sign_table) {
    int offset = 0;
    int index = 114;
    
    for (int i = 0; i < sign_table.size(); i++) {
        const char* identifier = sign_table[i].c_str();
        
        if (strcmp(identifier, symbol) == 0) {
            index = i;
            break;
        }
    }
    
    offset = (index + 1) * -4;
    return offset;
}


#define MIPS_PUSH_CONST(val) \
    do { \
        printf("li $v0,%s\n",val);\
        printf("sw $v0, 0($sp)\n"); \
        printf("addiu $sp, $sp, -4\n"); \
    } while (0)


#define MIPS_PUSH_VARS(offset) \
    do { \
        printf("lw $v0,%d($fp)\n",offset);\
        printf("sw $v0, 0($sp)\n"); \
        printf("addiu $sp, $sp, -4\n"); \
    } while (0)

#define MIPS_POP(target_reg)\
    do{\
        printf("lw %s, 4($sp)\n", target_reg); \
        printf("addiu $sp, $sp, 4\n");\
    }while(0)


#define PRINT() \
    do { \
        printf("li $v0, 1 # 设置系统调用号为 1，即打印整数\n"); \
        printf("syscall # 系统调用\n"); \
        printf("li $v0, 4 # 设置系统调用号为 4，即打印字符串\n"); \
        printf("la $a0, newline # 准备系统调用参数\n"); \
        printf("syscall # 系统调用\n"); \
    } while (0)

#define MAIN() \
    do { \
        printf(".data\nnewline: .asciiz \"\\n\"\n.text\n.globl main\nmain:\nmove $fp, $sp\naddiu $sp, $sp, -0x100\n"); \
    } while (0)

#define EVAL_PRE()\
    do { \
       printf("lw $t1, 4($sp)\n");\
       printf("lw $t0, 8($sp)\n");\
    } while (0)

#define EVAL_AFTER()\
do{\
    printf("sw $t0, 8($sp)\n");\
    printf("addiu $sp, $sp, 4\n");\
}while(0);

#define FUNC_RETURN() \
    do { \
        printf("addiu $sp, $sp, 4\n"); \
        printf("move $sp, $fp\n"); \
        printf("lw $fp, 4($sp)\n"); \
        printf("lw $ra, 0($sp)\n"); \
        printf("addiu $sp, $sp, 4\n"); \
        printf("jr $ra\n"); \
    } while(0)

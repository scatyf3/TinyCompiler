enum SymbolType {
  FUNC_ARG,
  LOCAL_VAR
};
void printSignTable(const std::vector<std::pair<SymbolType, std::string>>& sign_table) {
    std::cout << "###" << std::endl;
    std::cout << "# Symbol Table Elements:" << std::endl;
    
    if (sign_table.empty()) {
        std::cout << "# 无符号" << std::endl;
    } else {
        for (const auto& entry : sign_table) {
            const std::string& symbol = entry.second;
            SymbolType symbolType = entry.first;
            std::string symbolTypeName;

            // Convert symbol type to string
            switch (symbolType) {
                case SymbolType::FUNC_ARG:
                    symbolTypeName = "FUNC_ARG";
                    break;
                case SymbolType::LOCAL_VAR:
                    symbolTypeName = "LOCAL_VAR";
                    break;
                // Add cases for other symbol types if needed
                default:
                    symbolTypeName = "Unknown";
            }

            std::cout << "# " << symbol << " (Type: " << symbolTypeName << ")" << std::endl;
        }
    }
    
    std::cout << "###" << std::endl;
}


int searchAndCalculateOffset(const char* symbol, std::vector<std::pair<SymbolType, std::string>> sign_table) {
    int offset = 0;
    int funcArgCounter = 0;
    int localVarCounter = 0;

    // Debug
    printf("# the symbol we find is: %s\n", symbol);
    
    for (int i = 0; i < sign_table.size(); i++) {
        const char* identifier = sign_table[i].second.c_str(); // Access the second element of the pair (the string value)
        
        if (strcmp(identifier, symbol) == 0) {
            if (sign_table[i].first == SymbolType::FUNC_ARG) {
                funcArgCounter++;
            } else if (sign_table[i].first == SymbolType::LOCAL_VAR) {
                localVarCounter++;
            }
        }
    }
    
    SymbolType symbolType;
    
    if (funcArgCounter > 0) {
        symbolType = SymbolType::FUNC_ARG;
        offset = (funcArgCounter+1) * 4; // 4($fp) 储存的是原有的栈帧

    } else if (localVarCounter > 0) {
        symbolType = SymbolType::LOCAL_VAR;
        offset = localVarCounter * -4; // 
    }
    
    printf("# offset is %d for symbol type: %d\n", offset, symbolType);
    return offset;
}

#define MIPS_PUSH_CONST(val) \
    do { \
        printf("# MIPS_PUSH_CONST\n");\
        printf("li $v0,%s\n",val);\
        printf("sw $v0, 0($sp)\n"); \
        printf("addiu $sp, $sp, -4\n"); \
        printf("# END OF MIPS_PUSH_CONST\n\n");\
    } while (0)


#define MIPS_PUSH_VARS(offset) \
    do { \
        printf("# MIPS_PUSH_VARS\n");\
        printf("lw $v0,%d($fp)\n",offset);\
        printf("sw $v0, 0($sp)\n"); \
        printf("addiu $sp, $sp, -4\n"); \
        printf("# END OF MIPS_PUSH_VARS\n\n");\
    } while (0)

#define MIPS_POP(target_reg)\
    do{\
        printf("# MIPS_POP\n");\
        printf("lw %s, 4($sp)\n", target_reg); \
        printf("addiu $sp, $sp, 4\n");\
        printf("# END OF MIPS_POP\n\n");\
    }while(0)


#define PRINT() \
    do { \
        printf("# PRINT\n");\
        printf("li $v0, 1 # 设置系统调用号为 1，即打印整数\n"); \
        printf("syscall # 系统调用\n"); \
        printf("li $v0, 4 # 设置系统调用号为 4，即打印字符串\n"); \
        printf("la $a0, newline # 准备系统调用参数\n"); \
        printf("syscall # 系统调用\n"); \
        printf("# END OF PRINT\n\n");\
    } while (0)

#define MAIN() \
    do { \
        printf("\nmain:\nmove $fp, $sp\naddiu $sp, $sp, -0x100\n"); \
    } while (0)

#define EVAL_PRE()\
    do { \
       printf("# START OF EVAL\n\n");\
       printf("lw $t1, 4($sp)\n");\
       printf("lw $t0, 8($sp)\n");\
    } while (0)

#define EVAL_AFTER()\
do{\
    printf("sw $t0, 8($sp)\n");\
    printf("addiu $sp, $sp, 4\n");\
    printf("# END OF EVAL\n\n");\
}while(0);

#define FUNC_RETURN() \
    do { \
        printf("move $sp, $fp\n"); \
        printf("lw $fp, 4($sp)\n"); \
        printf("lw $ra, 0($sp)\n"); \
        printf("addiu $sp, $sp, 4\n"); \
        printf("jr $ra\n"); \
    } while(0)


#define GLOBL(symbol)\
    do{\
    printf(".globl %s\n",symbol);\
    }while(0)

#define DATA()\
    do{\
    printf(".data\nnewline: .asciiz \"\\n\"\n.text\n");\ 
    }while(0)


# define PUSH_FUNC_ARGS(symbol)\
    do{\
    printf(".globl %s\n",symbol);\
    }while(0)


# define FUNC_CALL_RETURN()\
do{\
    printf("addiu $sp, $sp, 4 \n");\
    printf("sw $v0, 0($sp)\n");\
    printf("addiu $sp, $sp, -4\n");\
    }while(0)


//FUNC_CALL_RETURN 需要切换解析变量的符号表

# define MAIN_RETURN()\
do{\
    printf("li $v0, 10\n");\ 
    printf("syscall\n");\ 
    }while(0)


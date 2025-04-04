#include <fstream>
std::ofstream debug_log("debug.log"); // 创建文件输出流
std::string intermediate_code = "";//“中间码”，但是目前用的是一对一翻译，只有符号表和局部变量需要再处理一趟


#define MIPS_PUSH_CONST(val) \
    do { \
        debug_log<<"\tpush "<<std::string(val)<<"\n";\
        intermediate_code += "# MIPS_PUSH_CONST\n"; \
        intermediate_code += "li $v0," + std::string(val) + "\n"; \
        intermediate_code += "sw $v0, 0($sp)\n"; \
        intermediate_code += "addiu $sp, $sp, -4\n"; \
        intermediate_code += "# END OF MIPS_PUSH_CONST\n\n"; \
    } while (0)


#define MIPS_PUSH_VARS(offset) \
    do { \
        debug_log<<"\tpush var offset = "<<offset<<"\n";\
        intermediate_code += "# MIPS_PUSH_VARS\n"; \
        intermediate_code += "lw $v0," + std::to_string(offset) + "($fp)\n"; \
        intermediate_code += "sw $v0, 0($sp)\n"; \
        intermediate_code += "addiu $sp, $sp, -4\n"; \
        intermediate_code += "# END OF MIPS_PUSH_VARS\n\n"; \
    } while (0)

#define MIPS_POP(target_reg) \
    do { \
        debug_log<<"\tpop "<<"\n";\
        intermediate_code += "# MIPS_POP\n"; \
        intermediate_code += "lw " + std::string(target_reg) + ", 4($sp)\n"; \
        intermediate_code += "addiu $sp, $sp, 4\n"; \
        intermediate_code += "# END OF MIPS_POP\n\n"; \
    } while (0)


#define PRINT() \
    do { \
        debug_log<<"print"<<"\n";\
        intermediate_code += "# PRINT\n"; \
        intermediate_code += "li $v0, 1 # 设置系统调用号为 1，即打印整数\n"; \
        intermediate_code += "syscall # 系统调用\n"; \
        intermediate_code += "li $v0, 4 # 设置系统调用号为 4，即打印字符串\n"; \
        intermediate_code += "la $a0, newline # 准备系统调用参数\n"; \
        intermediate_code += "syscall # 系统调用\n"; \
        intermediate_code += "# END OF PRINT\n\n"; \
    } while (0)

#define MAIN() \
    do { \
        debug_log<<"FUNC @main:"<<"\n";\
        intermediate_code += "\nmain:\nmove $fp, $sp\naddiu $sp, $sp, -0x100\n"; \
    } while (0)

#define EVAL_PRE() \
    do { \
        debug_log<<"\teval exp"<<"\n";\
        intermediate_code += "# START OF EVAL\n\n"; \
        intermediate_code += "lw $t1, 4($sp)\n"; \
        intermediate_code += "lw $t0, 8($sp)\n"; \
    } while (0)

#define EVAL_AFTER() \
    do { \
        intermediate_code += "sw $t0, 8($sp)\n"; \
        intermediate_code += "addiu $sp, $sp, 4\n"; \
        intermediate_code += "# END OF EVAL\n\n"; \
    } while (0);

#define FUNC_RETURN() \
    do { \
        debug_log<<"func declare return"<<"\n";\
        intermediate_code += "move $sp, $fp\n"; \
        intermediate_code += "lw $fp, 4($sp)\n"; \
        intermediate_code += "lw $ra, 0($sp)\n"; \
        intermediate_code += "addiu $sp, $sp, 4\n"; \
        intermediate_code += "jr $ra\n"; \
    } while (0)


#define GLOBL(symbol) \
    do { \
        intermediate_code += ".globl " + std::string(symbol) + "\n"; \
        debug_log<<"@@@ function sign table wait to be process"<<"\n";\
    } while (0)

#define DATA() \
    do { \
        intermediate_code += ".data\nnewline: .asciiz \"\\n\"\n.text\n"; \
    } while (0)




#define MAIN_RETURN() \
    do { \
        debug_log<<"exit main"<<"\n";\
        intermediate_code += "li $v0, 10\n"; \
        intermediate_code += "syscall\n"; \
    } while (0)
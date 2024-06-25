.globl myprint
.globl main
.data
newline: .asciiz "\n"
.text
myprint:
addiu $sp, $sp, -4
sw $ra, 0($sp)
sw $fp, 4($sp)
move $fp, $sp
addiu $sp, $sp, -0x100
###
# Symbol Table Elements:
# 无符号
# Num Function Arguments: 0
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# a (Type: FUNC_ARG)
# Num Function Arguments: 1
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# a (Type: FUNC_ARG)
# b (Type: FUNC_ARG)
# Num Function Arguments: 2
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# a (Type: FUNC_ARG)
# b (Type: FUNC_ARG)
# c (Type: FUNC_ARG)
# Num Function Arguments: 3
# Num Local Variables: 0
###
# MIPS_PUSH_VARS
lw $v0,16($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments a

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
# MIPS_POP
lw $a0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

# PRINT
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用
# END OF PRINT

# MIPS_PUSH_VARS
lw $v0,12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments b

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
# MIPS_POP
lw $a0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

# PRINT
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用
# END OF PRINT

# MIPS_PUSH_VARS
lw $v0,8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments c

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
# MIPS_POP
lw $a0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

# PRINT
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用
# END OF PRINT

move $sp, $fp
lw $fp, 4($sp)
lw $ra, 0($sp)
addiu $sp, $sp, 4
jr $ra

main:
move $fp, $sp
addiu $sp, $sp, -0x100
###
# Symbol Table Elements:
# 无符号
# Num Function Arguments: 0
# Num Local Variables: 0
###
# MIPS_PUSH_CONST
li $v0,1
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# this is a DeclStmt
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 1
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-4($fp)
# end of DeclList

# MIPS_PUSH_CONST
li $v0,2
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# this is a DeclStmt
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# b (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 2
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-8($fp)
# end of DeclList

# this is a DeclStmt

# MIPS_PUSH_VARS
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_VARS
lw $v0,-8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
add $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# this is a DeclStmt
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# b (Type: LOCAL_VAR)
# c (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 3
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-12($fp)
# end of DeclList

# this is a DeclStmt

# MIPS_PUSH_VARS
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_VARS
lw $v0,-8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_VARS
lw $v0,-12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments c

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments b
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
### Passing the arguments a
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal myprint
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# b (Type: LOCAL_VAR)
# c (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 3
###
# 生成清理 stack 的指令
addiu $sp, $sp, 12
sw $v0, 0($sp)
addiu $sp, $sp, -4
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# b (Type: LOCAL_VAR)
# c (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 3
###
# MIPS_PUSH_CONST
li $v0,0
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

move $sp, $fp
lw $fp, 4($sp)
li $v0, 10
syscall

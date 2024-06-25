.globl test
.globl main
.data
newline: .asciiz "\n"
.text
test:
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
# arg1 (Type: FUNC_ARG)
# Num Function Arguments: 1
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# arg1 (Type: FUNC_ARG)
# arg2 (Type: FUNC_ARG)
# Num Function Arguments: 2
# Num Local Variables: 0
###
# MIPS_PUSH_VARS
lw $v0,12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_VARS
lw $v0,8($fp)
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

# MIPS_PUSH_VARS
lw $v0,12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
mul $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# MIPS_PUSH_VARS
lw $v0,8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
div $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# MIPS_PUSH_VARS
lw $v0,12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
and $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

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
li $v0,114
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
li $v0,514
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

# MIPS_PUSH_CONST
li $v0,1
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

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
mul $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

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

### Passing the arguments a

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments a
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal test
###
# Symbol Table Elements:
# a (Type: LOCAL_VAR)
# b (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 2
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
add $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

### Passing the arguments 1

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

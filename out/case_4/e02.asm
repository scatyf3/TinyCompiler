.globl main
.data
newline: .asciiz "\n"
.text

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
li $v0,0
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# this is a DeclStmt
###
# Symbol Table Elements:
# i (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 1
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-4($fp)
# end of DeclList

# this is a DeclStmt

#tag
$while_cond_1:
# MIPS_PUSH_VARS
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_CONST
li $v0,3
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
slt $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# MIPS_POP
lw $t0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

beq $t0, $zero, $while_end_1
# MIPS_PUSH_VARS
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments i

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
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_CONST
li $v0,1
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# START OF EVAL

lw $t1, 4($sp)
lw $t0, 8($sp)
add $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL

# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-4($fp)

# end of assign stmt
j $while_cond_1
#tag
$while_end_1:
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

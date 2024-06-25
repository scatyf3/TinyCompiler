.globl opplus
.globl opminus
.globl opmul
.globl opdiv
.globl opmod
.globl opand
.globl opxor
.globl opplus_114514
.globl opor
.globl main
.data
newline: .asciiz "\n"
.text
opplus:
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

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

move $sp, $fp
lw $fp, 4($sp)
lw $ra, 0($sp)
addiu $sp, $sp, 4
jr $ra
opminus:
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
sub $t0, $t0, $t1
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
opmul:
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
mul $t0, $t0, $t1
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
opdiv:
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
div $t0, $t0, $t1
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
opmod:
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
rem $t0, $t0, $t1
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
opand:
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
opor:
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
or $t0, $t0, $t1
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
opxor:
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
xor $t0, $t0, $t1
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
opplus_114514:
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
# _0 (Type: FUNC_ARG)
# Num Function Arguments: 1
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# Num Function Arguments: 2
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# _1 (Type: FUNC_ARG)
# Num Function Arguments: 3
# Num Local Variables: 0
###
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# _1 (Type: FUNC_ARG)
# _2 (Type: FUNC_ARG)
# Num Function Arguments: 4
# Num Local Variables: 0
###
# MIPS_PUSH_VARS
lw $v0,20($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# this is a DeclStmt
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# _1 (Type: FUNC_ARG)
# _2 (Type: FUNC_ARG)
# l_0 (Type: LOCAL_VAR)
# Num Function Arguments: 4
# Num Local Variables: 1
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-4($fp)
# end of DeclList

# MIPS_PUSH_VARS
lw $v0,12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# this is a DeclStmt
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# _1 (Type: FUNC_ARG)
# _2 (Type: FUNC_ARG)
# l_0 (Type: LOCAL_VAR)
# l_1 (Type: LOCAL_VAR)
# Num Function Arguments: 4
# Num Local Variables: 2
###
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-8($fp)
# end of DeclList

# MIPS_PUSH_VARS
lw $v0,8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# this is a DeclStmt
###
# Symbol Table Elements:
# _0 (Type: FUNC_ARG)
# arg (Type: FUNC_ARG)
# _1 (Type: FUNC_ARG)
# _2 (Type: FUNC_ARG)
# l_0 (Type: LOCAL_VAR)
# l_1 (Type: LOCAL_VAR)
# l_2 (Type: LOCAL_VAR)
# Num Function Arguments: 4
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
lw $v0,16($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

# MIPS_PUSH_CONST
li $v0,114514
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
# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 1
###
sw $zero, -4($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 2
###
sw $zero, -8($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 3
###
sw $zero, -12($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 4
###
sw $zero, -16($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 5
###
sw $zero, -20($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 6
###
sw $zero, -24($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 7
###
sw $zero, -28($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 8
###
sw $zero, -32($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 9
###
sw $zero, -36($fp)
# end of DeclList

# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
sw $zero, -40($fp)
# end of DeclList

# this is a DeclStmt

# MIPS_PUSH_CONST
li $v0,114
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-4($fp)

# end of assign stmt
# MIPS_PUSH_CONST
li $v0,514
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-8($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opplus
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-20($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opminus
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-12($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opmul
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-16($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opdiv
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-24($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opmod
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-28($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opand
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-32($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opor
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-36($fp)

# end of assign stmt
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

### Passing the arguments literal2

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments literal1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opxor
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 10
###
# 生成清理 stack 的指令
addiu $sp, $sp, 8
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-40($fp)

# end of assign stmt
# this is a DeclStmt
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# var (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 11
###
sw $zero, -44($fp)
# end of DeclList

# this is a DeclStmt

# MIPS_PUSH_CONST
li $v0,1
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# MIPS_PUSH_CONST
li $v0,2
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# MIPS_PUSH_CONST
li $v0,3
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

# MIPS_PUSH_CONST
li $v0,4
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_CONST

### Passing the arguments 4

# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### Passing the arguments 3
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
### Passing the arguments 2
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
### Passing the arguments 1
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0, 0($sp)
addiu $sp, $sp, -4
### End of passing the arguments 
jal opplus_114514
###
# Symbol Table Elements:
# literal1 (Type: LOCAL_VAR)
# literal2 (Type: LOCAL_VAR)
# vminus (Type: LOCAL_VAR)
# vmul (Type: LOCAL_VAR)
# vadd (Type: LOCAL_VAR)
# vdiv (Type: LOCAL_VAR)
# vmod (Type: LOCAL_VAR)
# vand (Type: LOCAL_VAR)
# vor (Type: LOCAL_VAR)
# vxor (Type: LOCAL_VAR)
# var (Type: LOCAL_VAR)
# Num Function Arguments: 0
# Num Local Variables: 11
###
# 生成清理 stack 的指令
addiu $sp, $sp, 16
sw $v0, 0($sp)
addiu $sp, $sp, -4
# start of assign stmt
# MIPS_POP
lw $v0, 4($sp)
addiu $sp, $sp, 4
# END OF MIPS_POP

sw $v0,-44($fp)

# end of assign stmt
# MIPS_PUSH_VARS
lw $v0,-4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments literal1

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
lw $v0,-8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments literal2

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
lw $v0,-20($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vadd

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
lw $v0,-12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vminus

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
lw $v0,-16($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vmul

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
lw $v0,-24($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vdiv

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
lw $v0,-28($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vmod

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
lw $v0,-32($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vand

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
lw $v0,-36($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vor

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
lw $v0,-40($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments vxor

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
lw $v0,-44($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
# END OF MIPS_PUSH_VARS

### Passing the arguments var

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

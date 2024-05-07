.data
newline: .asciiz "\n"
.text
.globl main
main:
move $fp, $sp
addiu $sp, $sp, -0x100
sw $zero,-4($fp)
sw $zero,-8($fp)
sw $zero,-12($fp)
sw $zero,-16($fp)
sw $zero,-20($fp)
li $v0, 114
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-4($fp)
li $v0, 514
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-8($fp)
lw $v0, -4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
lw $t0, 8($sp)
or $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-12($fp)
lw $v0, -4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
lw $t0, 8($sp)
and $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-16($fp)
lw $v0, -4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
lw $t0, 8($sp)
xor $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-20($fp)
lw $a0,-12($fp)
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用

lw $a0,-16($fp)
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用

lw $a0,-20($fp)
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 4 # 设置系统调用号为 4，即打印字符串
la $a0, newline # 准备系统调用参数
syscall # 系统调用

li $v0,0
move $v1, $v0
li $v0, 10
syscall


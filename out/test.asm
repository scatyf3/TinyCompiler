.text
.globl main # 声明 main 函数为全局符号，使得模拟器能识别程序的入口点
main:
move $fp, $sp # 设置帧指针
addiu $sp, $sp, -0x100 # 为局部变量分配栈空间
sw $zero,-4($fp)
sw $zero,-8($fp)
sw $zero,-12($fp)
li $v0, 1
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-4($fp)
li $v0, 2
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
add $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
lw $v0, 4($sp)
addiu $sp, $sp, 4
sw $v0,-12($fp)
lw $v0,-12($fp)
move $a0, $v0 # 将返回值（$v0）复制到$a0，作为打印整数的系统调用的参数
li $v0, 1 # 设置系统调用号为 1，即打印整数
syscall # 系统调用
li $v0, 10 # 设置系统调用号为 10，即退出程序
syscall # 系统调用
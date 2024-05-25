.globl main
.globl myprint
.data
.text
myprint:
addiu $sp, $sp, -4
sw $ra, 0($sp)
sw $fp, 4($sp)
move $fp, $sp
addiu $sp, $sp, -4
lw $v0, 8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($sp)
li $v0, 1
syscall
li $v0, 11
li $a0, 0x0A
syscall
addiu $sp, $sp, 4
lw $v0, 12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($sp)
li $v0, 1
syscall
li $v0, 11
li $a0, 0x0A
syscall
addiu $sp, $sp, 4
lw $v0, 16($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 4($sp)
li $v0, 1
syscall
li $v0, 11
li $a0, 0x0A
syscall
addiu $sp, $sp, 4
move $sp, $fp
lw $fp, 4($sp)
lw $ra, 0($sp)
addiu $sp, $sp, 4
jr $ra

main:
move $fp, $sp
addiu $sp, $sp, -16

# int a = 1, b = 2; ✅

li $v0, 1
sw $v0, 0($sp)
addiu $sp, $sp, -4

lw $t0, 4($sp)
sw $t0, -4($fp)
addiu $sp, $sp, 4

# ✅以上是对a赋值1

li $v0, 2
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $t0, 4($sp)
sw $t0, -8($fp)
addiu $sp, $sp, 4

# 对b赋值，但是这里我的实现好像是对a赋值了2（由idx可知）！

# int c = a + b ; ✅

lw $v0, -4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $t1, 4($sp)
lw $t0, 8($sp)
addiu $sp, $sp, 8
add $t0, $t0, $t1
sw $t0, 0($sp)
addiu $sp, $sp, -4
lw $t0, 4($sp)
sw $t0, -12($fp)
addiu $sp, $sp, 4


# push args 但是我觉得我执行的部分也正确？？
lw $v0, -12($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -8($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, -4($fp)
sw $v0, 0($sp)
addiu $sp, $sp, -4

jal myprint
addiu $sp, $sp, 12
li $v0, 0
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, 4($sp)
addiu $sp, $sp, 4
li $v0, 10
syscall
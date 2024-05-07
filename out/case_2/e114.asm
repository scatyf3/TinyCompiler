.data
newline: .asciiz "\n"
.text
.globl main
main:
move $fp, $sp
addiu $sp, $sp, -0x100
li $v0,0
move $v1, $v0
li $v0, 10
syscall


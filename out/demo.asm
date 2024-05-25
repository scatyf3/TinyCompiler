add10:

# ✅ 函数的调用规范，已经完成

addiu $sp, $sp, -4 # 为保存寄存器分配空间 
sw $ra, 0($sp) # 保存 ra
sw $fp, 4($sp) # 保存 fp
move $fp, $sp # 设置 fp, 便于访问局部变量
addiu $sp, $sp, -8 # 为局部变量分配空间


# int c = 10; ✅
# 没明白，为什么要同时进栈和frame呢

li $t0, 10 # 初始化局部变量
sw $t0, -4($fp)

## c = c+a

# push c into stack

lw $v0, -4($fp) # 将局部变量 c入栈
sw $v0, 0($sp)
addiu $sp, $sp, -4

# push a into stack
# 但是为什么a的索引是fp + 8 ??

lw $v0, 8($fp) # 将参数 a入栈
sw $v0, 0($sp)
addiu $sp, $sp, -4

# eval ✅ 我的比较繁琐，但是大抵也是计算，然后存到-4($fp)

lw $t1, 4($sp) # 从栈中取出参数 a
lw $t0, 8($sp) # 从栈中取出局部变量 c
addiu $sp, $sp, 8 # 清理栈
add $t0, $t0, $t1 # c = c+a
sw $t0, -4($fp) # 存储结果


# return c ✅
# 好像原来有的多了一行

lw $v0, -4($fp) # 返回值放入 v0
move $sp, $fp # 清理局部变量
lw $fp, 4($sp) # 恢复 fp
lw $ra, 0($sp) # 恢复 ra
addiu $sp, $sp, 4 # 清理为保存寄存器分配的空间，恢复栈指针
jr $ra # 返回

# int main
# 但是为什么栈帧-8，是不是要识别这个函数里有多少局部变量再操作
main:
move $fp, $sp # 设置 fp
addiu $sp, $sp, -8 # 给fp + 负数这部分局部变量留出空间（栈帧）

# int a; ✅
# 好像这里没操作，但是我把它置0应该没有问题 

# a = add10(1);

# 我这里为啥 push pop 再push，不懂

li $v0, 1 # 设置参数 ✅
sw $v0, 0($sp) # 参数入栈 ✅
addiu $sp, $sp, -4 # 为参数分配空间 ✅

jal add10 # 调用 add10
addiu $sp, $sp, 4 # 清理栈 -> 之前传的参数
sw $v0, 0($sp) # 将返回值压入栈
addiu $sp, $sp, -4 # 为返回值分配空间
lw $t0, 4($sp) # 从栈中取出返回值

## 为什么是0！这里似乎无法成功解析符号表

sw $t0, -4($fp) # 将返回值存入局部变量
addiu $sp, $sp, 4 # 清理栈

# return 0;

li $v0, 0 # 返回值

# end of main

li $v0, 10 # 退出
syscall
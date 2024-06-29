# complier

24春 北京师范大学 编译器作业



## 实验一: TinyComplier

初代编译器将 C 语言顺序语句序列翻译为等价的汇编程序，所输出的汇编 程序符合x86或MIPS汇编语言格式要求，能够被后续的汇编器翻译为可执行程 序运行。如果目标平台为 x86，则生成的可执行程序能够在目标机上执行和验证结果；如果目标平台为 MIPS，则生成的汇编程序可以在 MIPS 模拟器中运行和
验证结果。

详细的说明见`doc/Lab01WriteUp.md`

## 实验二：支持更复杂的文法处理和print

详细的说明见`doc/lab_02_write_up.md`

### 前端

- 将初代编译器的前端转化为flex
- 支持更多运算符
- 支持识别`(){}`括号嵌套
- 支持识别标准库函数`println_int`,`println_string`

### 后端

- 支持main函数作为程序入口
- 支持打印函数
- 支持更多复杂表达式求职

### 使用说明

在build文件夹下完成构建
- `make` 构建主程序
- `make test_tokenrizer` 从test文件夹下的`test_flex_rule.l`构建tokenrizer，打印解析的结果
- `make test_compile` 从test文件夹下的`test_compile.cpp`构建从给定的token编译程序的后端程序
- `sh run_cases_2.sh` 运行`test/cases_2/`文件夹下的八个测试用例，结果储存在`out/case_2`里

## 实验三

### 术语

- 调用者
- 被调用者

```sudocode
被调用者(){
    //一些定义
}

调用者(){
    被调用者();
}
```

### 我的工作

- 用bison改写后端，从c++迁移
- 支持函数定义和调用，为了支持这个功能，我们需要的工作有
    - 维护一个符号表栈和全部的符号表
        - 每当调用函数时，新建被调用者的符号表并push入符号表栈
        - 每当调用函数返回时，从符号表栈中弹出调用者的符号表
    - 创建一个enum，维护符号类型，
        - 如果是local var类型，从 fp-4n (n>0) ，即当前栈帧寻找值
        - 如果是func arg类型，从fp+4n (n>0)，即调用者压入栈，但是不在当前栈帧的地方寻找值
        ![alt text](image.png)
    - 在「后处理」阶段，判断每个栈帧应该有多大，增加每个函数的符号

- 增加「后处理」阶段
    - 对于每个栈帧，记录使用了多少局部变量，以维护一个合理的栈帧尺寸
    - 记录文件中出现的全部函数，在汇编程序的开始增加函数的`.globl <func name>`


    
#### fix 函数混合调用问题

```c
void myadd(int a,int b){
    return a+b;
}
int main(){
    println_int(1+myadd(114,514));
    return 0;
}

```

在这个示例程序里，我们期待的结果是629，但是

```sh
➜  build git:(main) ✗ spim -file ../out/test.asm
Loaded: /opt/homebrew/Cellar/spim/9.1.24/share/exceptions.s
742
```

感觉是由于传参规范的混乱造成的

函数调用前

```stack
- 1
- 114
- 514
```

push 114
push 514
pop push
pop push
感觉不如直接push...


push 返回值
eval add
结果在stack的顶部😠


在eval部分

```asm
# START OF EVAL

# 这里就是742了，奇怪
# t1:628
# t0:114
# 啊这，这里奇怪了
lw $t1, 4($sp)
lw $t0, 8($sp)
add $t0, $t0, $t1
sw $t0, 8($sp)
addiu $sp, $sp, 4
# END OF EVAL
```
发现传参的stack没有清理干净😠！

我们期待函数调用完的结果是

```stack
- 1
- 628
```

但是我们这里的结果是
```stack
- 1
- 114
- 628
```


#### fix 嵌套调用

据@Lucius同学说，e04和e07的问题是嵌套调用，如果`e09.c`work就能全对

```
Running testcase: ../test/cases_3/e09.c
Loaded: /opt/homebrew/Cellar/spim/9.1.24/share/exceptions.s
92
0
0
```

但是我本地的情况是e09 work？？


## 实验四

### 新功能

- 支持分支和循环关键字：if, else, while, continue, break
- 支持条件语句，分支语句
    - 条件语句 if ( condition6 ) { ... }
    - if ( condition6 ) { ... } else { ...  }
    - 循环语句 while ( condition) { ... }
    - 循环控制语句 continue; break;
- MISC: 优化？


### 支持分支-前端部分

先修改tokenrizer -> 很简单，很显然

#### 分支的语法

```
if
if (else if) x n else
```

一般必须有if，但是后面的部分都是可选的🤔

我们先迭代式修改，先支持纯if或者if-else再说，e01~e08里似乎并没有else if，所以我们简单修改parser

```
Stmt:      DeclStmt
         | AssignStmt
         | ReturnStmt 
         | StdFuncStmt 
         | FuncCallStmt
         | BranchStmt
         ;
BranchStmt : T_if '(' E ')' '{' Stmts '}' { debug_log<<"TODO: here is an if stmt"<<"\n"; }
           | T_if '(' E ')' '{' Stmts '}' T_else '(' E ')' '{' Stmts '}' { debug_log<<"TODO: here is an if stmt"<<"\n"; }
           ;
```

以e01为输入，发现输出的“伪三地址码”如下，说明简单的词法和语法识别work

```
FUNC @main:
	push 5
	pop 
assign a=
	push 3
	pop 
assign b=
	push var offset = -4
	push var offset = -8
	eval exp
	le
	push var offset = -4
	pop 
a
	pop 
print
print
TODO: here is an if stmt
	push var offset = -8
	pop 
b
	pop 
print
print
	push 0
	pop 
func declare return

```

### 支持分支-后端部分

对if语句的后端支持比较难🤔，我们以官方文档里的例子为例先研究一下应当如何支持分支语句

```c
int main() {
int i = 0;
while (i < 5) {
if (i % 2 == 0) {
println_int(i);
}
i = i + 1;
}
return 0;
}
```


```mips
.globl main
.data
.text
main:
# main的一些调用规范
move $fp, $sp
addiu $sp, $sp, -8
li $v0, 0
sw $v0, 0($sp)
# 声明i
addiu $sp, $sp, -4
lw $t0, 4($sp)
sw $t0, -4($fp)
addiu $sp, $sp, 4
# while loop
$while_cond_1:
# eval i < 5
    # load var i
    lw $v0, -4($fp)
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    # load const 5
    li $v0, 5
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    # slt
    lw $t1, 4($sp)
    lw $t0, 8($sp)
    addiu $sp, $sp, 8
    slt $t0, $t0, $t1
    # 结果入栈
    sw $t0, 0($sp)
    addiu $sp, $sp, -4
    lw $t0, 4($sp)
    addiu $sp, $sp, 4
    # if result = 0, aka $t0 >= $t1 goto $while_end_1 else continue
    beq $t0, $zero, $while_end_1
# loop body
    # if
    # load i
    lw $v0, -4($fp)
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    # load 2
    li $v0, 2
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    # eval % ==
    lw $t1, 4($sp)
    lw $t0, 8($sp)
    addiu $sp, $sp, 8
    div $t0, $t1
    # move from higher reg??
    mfhi $t0
    sw $t0, 0($sp)
    addiu $sp, $sp, -4
    li $v0, 0
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    lw $t1, 4($sp)
    lw $t0, 8($sp)
    addiu $sp, $sp, 8
    seq $t0, $t0, $t1
    sw $t0, 0($sp)
    addiu $sp, $sp, -4
    # end of eval

    # 用栈顶数值判断if语句是否成立
    lw $t0, 4($sp)
    addiu $sp, $sp, 4
    # if t0==0，即上面seq不相等，goto $if_else_1 else continue
    beq $t0, $zero, $if_else_1

    # if body
    # println_int(i);

    lw $v0, -4($fp)
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    lw $a0, 4($sp)
    li $v0, 1
    syscall
    li $v0, 11
    li $a0, 0x0A
    syscall
    addiu $sp, $sp, 4
    # end of if body

    j $if_end_1
    $if_else_1:
    $if_end_1:


    lw $v0, -4($fp)
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    li $v0, 1
    sw $v0, 0($sp)
    addiu $sp, $sp, -4
    lw $t1, 4($sp)
    lw $t0, 8($sp)
    addiu $sp, $sp, 8
    add $t0, $t0, $t1
    sw $t0, 0($sp)
    addiu $sp, $sp, -4
    lw $t0, 4($sp)
    sw $t0, -4($fp)
    addiu $sp, $sp, 4

    j $while_cond_1
$while_end_1:
li $v0, 0
sw $v0, 0($sp)
addiu $sp, $sp, -4
lw $v0, 4($sp)
addiu $sp, $sp, 4
li $v0, 10
syscall

```

特别地，在编码的过程中，我们发现为了更好的进行语法制导翻译，需要将括号中的表达式新建一个规则

```
TrueFalseExpression : E{
    //用栈顶数值判断if语句是否成立
    MIPS_POP("$t0");
    //if t0==0，即上面seq不相等，goto $if_else_1 else continue
    intermediate_code+="beq $t0, $zero, $if_end_1\n";
};
```

这样，在正常的expression推导之后，额外进行一个beq计算，完成条件判断，而跳转用的分支放置在Stmts parse结束之后即可

```
    T_if '(' TrueFalseExpression ')' '{' Stmts '}'{ 
        debug_log<<"if stmt"<<"\n"; 
        intermediate_code += "$if_end_1:\n";
    }
```


### 支持循环-后端

在循环的部分，比起if，我们还需要在while循环开始之前插入一个while condition的标签，需要加入两个“空推导,idea来自[这篇文章](https://pandolia.net/tinyc/ch16_tinyc_compiler.html)

```
LoopStmt: T_while Cond WhileBody {
    debug_log<<"LoopCond"<<"\n"; 
};

Cond: {intermediate_code+="$while_cond_1:"; };
```

截止到这里，e01和e02似乎都work了，开心😆

### 支持Else-后端

![if-else原理](image-1.png)

原理大抵如此，仿照这上面while的idea，写入了更好的加tag的方法，和向else if扩展的可能性


### 支持多个循环语句

正如e05，我们需要给tag编号以标识不同的分支和循环语句，一个朴素的方法是构建一个全局的条件语句和循环语句的计数器（但是如何处理else if 仍是TODO），我们先动手实现下这个朴素的idea

```
LoopStmt: T_while Cond WhileBody {
    debug_log<<"LoopCond"<<"\n"; 
};

Cond: { 
    loop_counter++;
    intermediate_code+="$while_cond_" + std::to_string(loop_counter) + ":\n"; 
};
```

但是loop_counter好像不对，在后面执行完毕循环体，返回条件的时候，两个while_cond_ tag都变成2了，明日再说吧！

---

感觉嵌套的while tag的结构应当是

```sudo code
while_cond_1:
while_cond_2:
j while_cond_2
j while_cond_1
```

这让我们想到了一个数据结构，stack🤔

看看别人怎么搞的

```
#define _BEG_WHILE  (wstack[++wtop] = ++ww)
#define _END_WHILE  (wtop--)
#define _w          (wstack[wtop])
```

好像还真是🤔，我真聪明🥺（呕呕）

---

还要处理end tag的问题

```sudo code
while_cond_1:
[cond 1]
while_cond_2:
[cond 2]
[code 2]
j while_cond_2
while_end_2
[code 1]
j while_cond_1
while_end_1

```

好像只是end和j共用一个stack的top就好

### 支持多个分支语句

同理，对分支语句也做这样的修改

## 一个迷你的编译器

北师大 2024春 编译原理实验

### 功能

#### 前端

- 关键字： int, return, main, void, if, else, while, continue, break
- 标识符： 符合C89 标准的标识符`[A-Za-z_][0-9A-Za-z_]*`
- 常量： 十进制整型，如1、223、10等
- 赋值操作符： =
- 运算符：
    - 一元运算符： - ! ~
    - 二元运算符： + - * / % < <= > >= == != & | ^ && ||
- 标点符号： ; { } ( )

#### 后端

- 变量声明 `int a, b=111, c=1+3;`
- 表达式赋值语句 `a = (d+b&1)/(e!=3^b/c&d); a = b+c;`
- return语句  `return a+b; return func(a);`
- 函数调用 `println_int(a+b);`
- 条件语句 `if ( condition6 ) { ...}`,`if ( condition6 ) { ...7 } else { ... 7 }`
- 循环语句 `while ( condition6 ) { ... }`
- 循环控制语句 `continue;` `break;`
- 函数
- 系统自带函数: `println_int`

### 项目结构

```
✗ tree -L 1
.
├── README.md 
├── bison_example //之前用来测试bison的小例子
├── build //构建相关，目前本地使用makefile
├── docs //实验要求和实验报告
├── log.md //开发碎碎念
├── out //输出结果
├── src //源代码
│   ├── MIPS.h //头文件，将一些常见的汇编，比如push，pop变成宏
│   ├── compilerlab1.cpp
│   ├── parser.y
│   ├── sign_table.cpp
│   ├── sign_table.hpp
│   ├── tcc
│   ├── tcc.hpp
│   └── tokenrizer.l
└── test //测试用例
```



### 依赖
- flex
- bison
- spim
- MacOS/Linux操作系统




### usage

```sh
cd build
make run
sh run_cases_<number>.sh
cd ../out/case_<number>
vim case_<number>.log #输出结果

```

### log
见`log.md`，开发碎碎念


### credit
- 这个实验由敬爱的[计老师](https://github.com/jiweixing)开发，这个实验非常酷，而且深刻的锻炼了我们的编译能力
    - 再带我们冲一次吧😭
    - 希望其他课程的实验也能如此良好的组织
- 这个实验的代码由我独立完成，但在有的idea实在匮乏的时候，我参考了下面的网站，获得了一些方向上的指引，具体的参考在`log.md`里提及
    - [自己动手写编译器](https://pandolia.net/tinyc/index.html)
    - [DoctorWkt/acwj](https://github.com/DoctorWkt/acwj)
- 感谢[LukeBriton](https://github.com/LukeBriton)同学


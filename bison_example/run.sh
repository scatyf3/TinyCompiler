## eg1：一个简单的计算器

bison -vdty calc.y
flex calc.l
gcc -o calc y.tab.c lex.yy.c
./calc


## eg2：一个简单的“编译器”


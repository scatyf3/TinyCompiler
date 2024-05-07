## bison example
这里用网上已经被证明正确的bison小demo以排除bug🤔

```sh
sh run.sh
```

### macos bison问题

以下文字由ai生成

在macOS上使用bison时遇到"implicit declaration of function 'yylex' is invalid in C99"错误，这是因为在C99标准中，隐式声明函数是无效的。在调用函数之前，必须提供函数的原型。

以下是解决这个问题的步骤：

1. 确保你的bison和flex版本是最新的。可以使用以下命令检查版本：
   ```
   bison --version
   flex --version
   ```
   如果版本过旧，可以考虑升级到最新版本。

2. 在你的bison文件（通常是以.y为扩展名）中，添加以下代码来声明yylex函数：
   ```
   %{
   int yylex(void);
   %}
   ```

3. 在你的bison文件中，将yylex函数的调用替换为yylex()函数的显式调用：
   ```
   yychar = yylex();
   ```

4. 重新编译你的代码。使用以下命令重新生成解析器和词法分析器：
   ```
   bison -d your_file.y
   flex your_file.l
   gcc -o your_program your_file.tab.c lex.yy.c -lfl
   ```

5. 运行你的程序，看看是否还有"implicit declaration of function 'yylex' is invalid in C99"错误。

这些步骤应该能够解决在macOS上使用bison时遇到"implicit declaration of function 'yylex' is invalid in C99"错误的问题。

---
Learn more:
1. [c++ - "yyparse/yylex/yyerror was not declared in this scope" - Flex/Bison - Stack Overflow](https://stackoverflow.com/questions/38143828/yyparse-yylex-yyerror-was-not-declared-in-this-scope-flex-bison)
2. [bison - Yacc errors error: ‘yylval’ undeclared (first use in this function) - Stack Overflow](https://stackoverflow.com/questions/31738786/yacc-errors-error-yylval-undeclared-first-use-in-this-function)
3. [implicit declaration of function 'yylex' is invalid in C99](https://lists.gnu.org/r/bug-bison/2022-01/msg00002.html)
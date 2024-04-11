run: tinyCompiler
	./tinyCompiler ../test/testcase3.minic > ../out/test.asm

lex.yy.cpp: ../src/tokenrizer.l
	flex -o $@ $^

tinyCompiler:  lex.yy.cpp
	g++ -o $@ $^ -std=c++14
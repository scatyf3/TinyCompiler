run: tinyCompiler
	./tinyCompiler < ../test/testcase3.minic > ../out/test.asm

lex.yy.cpp: ../src/tokenrizer.l
	flex -o $@ $^

calc.tab.cpp: ../src/parser.y
	bison -vdty -o $@ $^

tinyCompiler: calc.tab.cpp lex.yy.cpp
	g++ -o $@ $^
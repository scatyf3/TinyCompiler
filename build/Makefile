CC = g++
OUT = tcc
OBJ = lex.yy.o y.tab.o
SCANNER = ../src/tokenrizer.l
PARSER = ../src/parser.y
TEST_FLEX = ../test/test_flex.cpp

build: $(OUT) test_tokenrizer

run: $(OUT)
	./$(OUT)  ../test/testcase.minic > ../out/test.asm

clean:
	rm -f *.o lex.yy.cpp y.tab.cpp y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) -ll -lm -std=c++14

test_tokenrizer: lex.yy.o test_flex.o

y.tab.cpp y.tab.h: $(PARSER)
	bison -vdty -o y.tab.cpp -d $<

lex.yy.o: lex.yy.cpp
	$(CC) -c -o $@ $< -std=c++14

lex.yy.cpp: $(SCANNER)
	flex -o $@ $(SCANNER)

test_flex.o: $(TEST_FLEX)
	$(CC) -c -o $@ $(TEST_FLEX) -std=c++14

y.tab.o: y.tab.cpp
	$(CC) -c -o $@ $< -std=c++14



# https://stackoverflow.com/questions/28211952/y-tab-c-undefined-reference-to-yylex
# 一个更推荐的语法？
# flex -o tokenrizer.lex.c ../src/tokenrizer.l
# bison -o parser.tab.c -vd ../src/parser.y
# gcc -o calc3 tokenrizer.lex.c parser.tab.c -lm -ll


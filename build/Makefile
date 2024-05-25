CC = g++
OUT = tcc
OBJ = lex.yy.o y.tab.o sign_table.o
SCANNER = ../src/tokenrizer.l
PARSER = ../src/parser.y
SIGN_TABLE = ../src/sign_table.cpp
TEST_FLEX = ../test/test_flex.cpp
TEST_SIGN_TABLE = ../test/test_sign_table.cpp
CFLAGS = -std=c++14 -fsanitize=undefined

build: $(OUT) test_sign_table

run: $(OUT)
	./$(OUT) ../test/testcase.minic > ../out/test.asm

clean:
	rm -f *.o lex.yy.cpp y.tab.cpp y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) -ll -lm $(CFLAGS)


test_sign_table: test_sign_table.o sign_table.o
	$(CC) -o test_sign_table test_sign_table.o sign_table.o $(CFLAGS)

test_sign_table.o: $(TEST_SIGN_TABLE)
	$(CC) -c -o $@ $(TEST_SIGN_TABLE) $(CFLAGS)

sign_table.o: $(SIGN_TABLE)
	$(CC) -c -o $@ $(SIGN_TABLE) $(CFLAGS)

y.tab.cpp y.tab.h: $(PARSER)
	bison -vdty -o y.tab.cpp -d $<

lex.yy.o: lex.yy.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

lex.yy.cpp: $(SCANNER)
	flex -o $@ $(SCANNER)


y.tab.o: y.tab.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
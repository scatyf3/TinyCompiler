CC = g++
OUT = tcc
OBJ = lex.yy.o y.tab.o
SCANNER = ../src/tokenrizer.l
PARSER = ../src/parser.y

build: $(OUT)

run: $(OUT)
	./$(OUT) < test.c > test.asm

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) -ll


lex.yy.o: lex.yy.c y.tab.h
	$(CC) -c -o $@ $<

y.tab.o: y.tab.c
	$(CC) -c -o $@ $<

lex.yy.c: $(SCANNER) y.tab.h
	flex -o $@ $(SCANNER)

y.tab.c y.tab.h: $(PARSER)
	bison -vdty -o y.tab.c -d $<


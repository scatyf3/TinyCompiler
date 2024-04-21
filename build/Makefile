run: tinyCompiler
	./tinyCompiler ../test/testcase.minic 

test_compile:
	g++ ../test/test_compile.cpp -o test_compile -std=c++14 -fsanitize=address,undefined
	./test_compile
test_tokenrizer.cpp: ../test/test_flex_rule.l
	flex -o test_tokenrizer.cpp ../test/test_flex_rule.l
	g++ -o test_tokenrizer test_tokenrizer.cpp -std=c++14 -fsanitize=address,undefined
	./test_tokenrizer



lex.yy.cpp: ../src/tokenrizer.l
	flex -o $@ $^

tinyCompiler:  lex.yy.cpp
	g++ -o $@ $^ -std=c++14 -g

.PHONY: clean
clean:
	rm -f test_tokenrizer lex.yy.cpp tinyCompiler
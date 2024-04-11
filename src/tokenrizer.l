%{
#include "../src/tcc.hpp"
std::deque<std::deque<Token>> token;

//FOR TEST
#define T_WORD 1
int numChars = 0, numWords = 0, numLines = 0;
%}

%option noyywrap
WORD		([^ \t\n\r\a]+)

%%
\n			{ numLines++; numChars++; }
{WORD}		{ numWords++; numChars += yyleng; return T_WORD; }
<<EOF>>		{ return 0; }
.			{ numChars++; }
%%




int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }

    std::string sourceCodeFileName = argv[1];
    std::ifstream inputFile(sourceCodeFileName);

    if (inputFile.is_open()) {
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string sourceCode = buffer.str();
        sourceCode.erase(std::remove(sourceCode.begin(), sourceCode.end(), ';'), sourceCode.end());
        inputFile.close();
        yylex();
        //printTokens(token);
        std::string output = compile(token);
        std::cout << output << std::endl;
    } else {
        std::cout << "无法打开源代码文件." << std::endl;
    }

    return 0;
}


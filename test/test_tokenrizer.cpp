#include <iostream>
#include <fstream>
#include <string>
#include "../build/y.tab.h"

extern "C" int yylex();
extern "C" char* yytext;
extern "C" int yyparse();
extern "C" void yyerror(const char *s);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        yy_scan_string(line.c_str());
        int token;
        while ((token = yylex()) != 0) {
            std::cout << "Token: " << token << ", Value: " << yytext << std::endl;
        }
    }

    input_file.close();
    return 0;
}
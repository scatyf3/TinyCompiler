#include "tcc.hpp"

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
        inputFile.close();

        //std::deque<Token>> token = tokenize(sourceCode);
        //printTokens(token);
        std::string output = compile(token);
        std::cout << output << std::endl;
    } else {
        std::cout << "无法打开源代码文件." << std::endl;
    }

    return 0;
}


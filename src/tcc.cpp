
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>


std::string compile(std::string src);
std::string removeExtraSpaces(const std::string& str) {
    std::string result;
    std::istringstream iss(str);
    std::string line;

    while (std::getline(iss, line)) {
        line.erase(std::remove_if(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); }), line.end());
        result += line + "\n";
    }
    return result;
}


int main() {
    std::ifstream inputFile("source_code.txt");  // 输入源代码文件的名称
    std::string sourceCode;

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            sourceCode += line;
        }
        inputFile.close();
        std::string preprocessedCode = removeExtraSpaces(sourceCode);
        std::string output = compile(preprocessedCode);
        std::cout << output << std::endl;
    } else {
        std::cout << "无法打开源代码文件." << std::endl;
    }

    return 0;
}

std::string compile(std::string src){
    

}

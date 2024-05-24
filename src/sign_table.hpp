#include <vector>
#include <map>
#include <string>

enum SymbolType {
  FUNC_ARG,
  LOCAL_VAR
};

std::vector<std::vector<std::string>> sign_table;
std::map<std::string, std::vector<std::pair<SymbolType, std::string>>> frames; //全局的frame，可能解析符号表有用，但是也可能改成vector of string

typedef struct Symbol {
    SymbolType type;
    std::string name;
};

class SignTable {
public:
    void addSymbol(const Symbol& symbol) {
        symbols.emplace_back(symbol);
    }
    //display SignTable in intermeiate code
    std::string printSignTable() {
        std::string intermediate_code = "###\n";
        intermediate_code += "# Symbol Table Elements:\n";
        if (symbols.empty()) {
            intermediate_code += "# 无符号\n";
        } else {
            for (const auto& symbol : symbols) {
                std::string symbolTypeName;

                // Convert symbol type to string
                switch (symbol.type) {
                    case SymbolType::FUNC_ARG:
                        symbolTypeName = "FUNC_ARG";
                        break;
                    case SymbolType::LOCAL_VAR:
                        symbolTypeName = "LOCAL_VAR";
                        break;
                    // Add cases for other symbol types if needed
                    default:
                        symbolTypeName = "Unknown";
                }

                intermediate_code += "# " + symbol.name + " (Type: " + symbolTypeName + ")\n";
            }
        }

        intermediate_code += "###\n";
        return intermediate_code;
    }

    //usage
    //while parsing b = a + 1;
    //MIPS_PUSH_VAR(a); call offset = searchAndCalculateOffset(a);
    //here we don't known symbol type
    int searchAndCalculateOffset(const std::string& name)  {
        int funcArgOffset = 0;
        int localVarOffset = 0;
        int funcArgCounter = 0;
        int localVarCounter = 0;
        bool funcArgFound = false;
        bool localVarFound = false;
        SymbolType symbolType;

        for (const auto& symbol : symbols) {

            if (symbol.type == SymbolType::FUNC_ARG) {
                funcArgCounter++;
            } else if (symbol.type == SymbolType::LOCAL_VAR) {
                localVarCounter++;
            }

            if (symbol.name == name) {
                if (symbol.type == SymbolType::FUNC_ARG) {
                    funcArgFound = true;
                    break;
                } else if (symbol.type == SymbolType::LOCAL_VAR) {
                    localVarFound = true;
                    break;
                }
            }

            
        }

        if (funcArgFound) {
            symbolType = SymbolType::FUNC_ARG;
            funcArgOffset = (funcArgCounter + 1) * 4; // 4($fp) for the saved frame pointer
        } else if (localVarFound) {
            symbolType = SymbolType::LOCAL_VAR;
            localVarOffset = localVarCounter * -4; // Negative offsets for local variables
        } else {
            return -1; // Symbol not found
        }

        return symbolType == SymbolType::FUNC_ARG ? funcArgOffset : localVarOffset;
        }


    //int a = 1;
    //if we decl anythor a -> illagle sytax
    bool isInSignTable(const std::string& name) {
    for (const auto& symbol : symbols) {
        if (symbol.name == name) {
            return true;
        }
    }
    return false;
}

    private:
        std::vector<Symbol> symbols;
};


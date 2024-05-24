#include "sign_table.hpp"

void SignTable::addSymbol(const Symbol& symbol) {
    symbols.emplace_back(symbol);
}
// display SignTable in intermeiate code
std::string SignTable::printSignTable() {
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

            intermediate_code +=
                "# " + symbol.name + " (Type: " + symbolTypeName + ")\n";
        }
    }

    intermediate_code += "###\n";
    return intermediate_code;
}

// usage
// while parsing b = a + 1;
// MIPS_PUSH_VAR(a); call offset = searchAndCalculateOffset(a);
// here we don't known symbol type
int SignTable::searchAndCalculateOffset(const std::string& name) {
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
        funcArgOffset =
            (funcArgCounter + 1) * 4;  // 4($fp) for the saved frame pointer
    } else if (localVarFound) {
        symbolType = SymbolType::LOCAL_VAR;
        localVarOffset =
            localVarCounter * -4;  // Negative offsets for local variables
    } else {
        return -1;  // Symbol not found
    }

    return symbolType == SymbolType::FUNC_ARG ? funcArgOffset : localVarOffset;
}

// int a = 1;
// if we decl anythor a -> illagle sytax
bool SignTable::isInSignTable(const std::string& name) {
    for (const auto& symbol : symbols) {
        if (symbol.name == name) {
            return true;
        }
    }
    return false;
}

size_t SignTable::size(){
    return symbols.size();
}
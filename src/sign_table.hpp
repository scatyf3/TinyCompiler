#include <vector>
#include <map>
#include <string>

enum SymbolType {
  FUNC_ARG,
  LOCAL_VAR
};

struct Symbol {
    SymbolType type;
    std::string name;
    Symbol(SymbolType t, const std::string& n)
        : type(t), name(n) {}
};

class SignTable {
public:
    SignTable(const std::string& id) 
        : identifier(id), _nums_func_arg(0), _nums_local_var(0) {}
    void addSymbol(const Symbol& symbol);
    std::string printSignTable();
    int searchAndCalculateOffset(const std::string& name);
    bool isInSignTable(const std::string& name);
    size_t size();
    int get_nums_func_arg();
    std::string getIdentifier() const {
        return identifier;
    }

private:
    std::vector<Symbol> symbols;
    int _nums_func_arg;
    int _nums_local_var;
    std::string identifier;
};

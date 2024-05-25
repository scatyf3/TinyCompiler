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

class SignTable{
    public:
        void addSymbol(const Symbol& symbol);
        std::string printSignTable();
        int searchAndCalculateOffset(const std::string& name);
        bool isInSignTable(const std::string& name);
        size_t size();
    private:
        std::vector<Symbol> symbols;
        int _nums_func_arg;
        int _nums_local_var;
};




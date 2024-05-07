%{
#include <iostream>
#include <vector>
using namespace std;

extern "C" int yylex();
extern "C" FILE* yyin;
void yyerror(const char* s);

enum TokenType {
    IntConstant,
    Identifier,
    StdFunction,
    Keyword,
    Operator
};

struct Token {
    string lexeme;
    TokenType type;
    Token(const string& l, TokenType t) : lexeme(l), type(t) {}
};

vector<Token> tokens;

%}

%union {
    char* lexeme;
}

%token<lexeme> T_IntConstant
%token<lexeme> T_Identifier
%token<lexeme> T_std_function
%token<lexeme> T_keyword
%token<lexeme> T_operator

%type<lexeme> program
%type<lexeme> statement
%type<lexeme> operator
%type<lexeme> constant
%type<lexeme> identifier
%type<lexeme> std_function
%type<lexeme> keyword

%%

program:
    /* empty */
    |
    program statement
    ;

statement:
    operator { tokens.push_back(Token($1, Operator)); }
    |
    constant { tokens.push_back(Token($1, IntConstant)); }
    |
    identifier { tokens.push_back(Token($1, Identifier)); }
    |
    std_function { tokens.push_back(Token($1, StdFunction)); }
    |
    keyword { tokens.push_back(Token($1, Keyword)); }
    ;

operator:
    T_operator { $$ = $1; }
    ;

constant:
    T_IntConstant { $$ = $1; }
    ;

identifier:
    T_Identifier { $$ = $1; }
    ;

std_function:
    T_std_function { $$ = $1; }
    ;

keyword:
    T_keyword { $$ = $1; }
    ;

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            cerr << "Error opening file" << endl;
            return 1;
        }
        yyin = file;
    }

    yyparse();

    for (const auto& token : tokens) {
        cout << "Token: " << token.lexeme << ", Type: ";
        switch (token.type) {
            case IntConstant:
                cout << "IntConstant";
                break;
            case Identifier:
                cout << "Identifier";
                break;
            case StdFunction:
                cout << "StdFunction";
                break;
            case Keyword:
                cout << "Keyword";
                break;
            case Operator:
                cout << "Operator";
                break;
        }
        cout << endl;
    }

    return 0;
}

void yyerror(const char* s) {
    cerr << "Parser error: " << s << endl;
}
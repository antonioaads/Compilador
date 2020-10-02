#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

namespace TokenTypes{
    enum{
        PROGRAM = 1,
        IS,
        IF,
        IN,
        INT,
        INIT,
        CHAR,
        DO,
        DECLARE,
        END,
        ELSE,
        FLOAT,
        OUT,
        REPEAT,
        THEN,
        UNTIL,
        WHILE,
        IDENTIFIER,
        RELOP,
        ADDOP,
        MULOP
    };
}


using namespace std;

#include "Token.cpp"
#include "LexicalAnalyzer.cpp"

int main(int argc, char** argv) {


    LexicalAnalyzer a1("exemplo.txt");

    Token teste = a1.getNextToken();
    cout << teste.lexema;

    teste = a1.getNextToken();
    cout << teste.lexema << endl;
    teste = a1.getNextToken();
    cout << teste.lexema << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;


    return 0;
}
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "Token.cpp"
#include "LexicalAnalyzer.cpp"

int main(int argc, char** argv) {

    if (argc < 2){
        cout << "lilito: fatal error: no input files" << endl 
        << "compilation terminated." << endl;
        return 1;
    }
    else if (argc > 2){
        cout << "lilito: fatal error: more 1 input files" << endl 
        << "compilation terminated." << endl;
        return 1;
    }

    LexicalAnalyzer a1(argv[1], true, false);

    Token token;

    do {
        token = a1.getNextToken();
    } while(token.type != TokenTypes::ENDOFFILE && token.type != TokenTypes::ERROR);

    cout << "Token final: " << token.lexema << endl;
    return 0;
}
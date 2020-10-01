#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "Token.cpp"
#include "LexicalAnalyzer.cpp"

int main(int argc, char** argv) {


    LexicalAnalyzer a1("exemplo.txt");

    cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;
    // cout << a1.getNextToken() << endl;

    return 0;
}
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Token{
    private:
    public:
        int type;
        string lexema;
        Token();
        Token(int type, string lexema){
            this->type = type;
            this->lexema = lexema;
        }
};
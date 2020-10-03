#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Token{
    private:
    public:
        int type = 0;
        string lexema;
        
        Token(){
            this->type = 0;
        }
        Token(int type, string lexema){
            this->type = type;
            this->lexema = lexema;
        }

        bool isNotNull(){
            return type != 0;
        }
};
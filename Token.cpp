#include <cstdlib>
#include <string>
#include <iostream>

namespace TokenTypes{
    enum{
        ERROR = 0,
        PROGRAM,
        IS,
        IF,
        IN,
        INT,
        INIT,
        CHAR,
        DO,
        DECLARE,
        END,
        ENDDOT,
        ENDOFFILE,
        ELSE,
        FLOAT,
        OUT,
        REPEAT,
        THEN,
        UNTIL,
        WHILE,
        IDENTIFIER,
        RELOP,      // == > >= < <= !=
        ADDOP,      // + -
        MULOP,      // * /
        SEMICOLON,  // ;
        COLON,      // :
        COMMA,      //,
        EQUAL,      // =
        READ,       // <<
        WRITE,      // >>
        NOT,        // !
        PARENTHESES,// ( )
        QUOTES      // " " ' 
    };
}

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
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

class Line{
    public:
    
    string name, type;
    int lineNumber, level;
    //para saber se e a ultima linha
    Line* next;
    
    Line(){
        next = NULL;
    };

    Line(string name, int level, string type, int increment){
        this->name = name;
        this->level = level;
        this->type = type;
        this->lineNumber = lineNumber + increment;
        next = NULL;
    };
};
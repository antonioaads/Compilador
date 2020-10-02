#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;



class Line{
    string name, level, type;
    int lineNumber;
    Line* next = NULL;

    public:
    Line(string name, int level, string type, int increment){
        this->name = name;
        this->level = level;
        this->type = type;
        this->lineNumber = lineNumber + increment;
    }
};
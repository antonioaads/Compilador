#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;



class Line{
    string id, level, type;
    int lineNumber;
    Line* next = NULL;

    public:
    Line(string id, int level, string type, int increment){
        this->id = id;
        this->level = level;
        this->type = type;
        this->lineNumber = lineNumber + increment;
    }
};
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

#include "Line.cpp"

class SymbolTable{

Line* lines[20];


    public:
    SymbolTable(){
        for(Line i: lines){
            i = NULL;
        }
    }

    int insertName(string id, int level, string type){
        int index = 0;
        Line* line = new Line(id, level, type, 1);
    }    

    bool searchForName(){
        return true;   
    }

    string getAttributes(){
        return "";
    }

    bool removeName(){
        return true;
    }


};

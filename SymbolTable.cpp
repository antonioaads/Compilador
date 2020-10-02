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
        //TODO pegar esse index
        int i = 0;
        Line* line = new Line(id, level, type, 1);

        if(lines[i] == NULL) {
            lines[i] = line;
            //TODO pegar a posição de lines
            return true;
        }
        else{
            Line* first = lines[i];
            while(first->next != NULL){
                first = first->next;
            }
            first->next = line;
            //TODO pegar a posição de lines
            return true
        }
        return false;
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

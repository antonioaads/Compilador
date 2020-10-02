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


    bool searchForName(string id, int level, string type){
        //TODO pegar esse index (buscando pelo id?)
        int i = 0;    
        Line* first = lines[i];

        if(first == NULL){
            return false;
        }

        while(first != NULL){
            if(first->id == id && first->level == level){
                //retorna a linha, TODO
                return i;
            }
            first = first->next;
        }

        return false;
    }

    string getAttributes(){
        return "";
    }

    bool removeName(){
        return true;
    }

};













// Function to modify an identi
// Function to delete an identifier 
bool SymbolTable::deleteRecord(string id) 
{ 
    int index = hashf(id); 
    Node* tmp = head[index]; 
    Node* par = head[index]; 
  
    // no identifier is present at that index 
    if (tmp == NULL) { 
        return false; 
    } 
    // only one identifier is present 
    if (tmp->identifier == id && tmp->next == NULL) { 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
  
    while (tmp->identifier != id && tmp->next != NULL) { 
        par = tmp; 
        tmp = tmp->next; 
    } 
    if (tmp->identifier == id && tmp->next != NULL) { 
        par->next = tmp->next; 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
  
    // delete at the end 
    else { 
        par->next = NULL; 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
    return false; 
} 
  
// Function to find an identifier 
string SymbolTable::find(string id) 
{ 
    int index = hashf(id); 
    Node* start = head[index]; 
  
    if (start == NULL) 
        return "-1"; 
  
    while (start != NULL) { 
  
        if (start->identifier == id) { 
            start->print(); 
            return start->scope; 
        } 
  
        start = start->next; 
    } 
  
    return "-1"; // not found 
} 
  
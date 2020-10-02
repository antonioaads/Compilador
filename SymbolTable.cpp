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
    },

    int insertName(string name, int level, string type){
        //TODO pegar esse index
        int i = 0;
        Line* line = new Line(name, level, type, 1);

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
    },    

    bool searchForName(string name, int level, string type){
        //TODO pegar esse index (buscando pelo name?)
        int i = 0;    
        Line* first = lines[i];

        if(first == NULL){
            return false;
        }

        while(first != NULL){
            if(first->name == name){
                return true;
            }
            first = first->next;
        }

        return false;
    },

    string getAttributes(string name){ 
        int i = 1; 
        Line* line = lines[i]; 
        //se não tiver linhas    
        if (line == NULL) { 
            return "NotFound"; 
        }
        //busca pelo nome que queremos os atributos
        do{
            tmp = tmp->next; 
        }while (line->name != name line->next != NULL) {  
        //se encontrou retorna o atributo
        if (line->name == name) {             
            return line->type; 
        }
        //se saiu do while sem encontrar
        return "NotFound";
    },

    bool removeName(string name){
        int i = 1; 
        Line* tmp = lines[i]; 
        Line* par = lines[i]; 
    
        //sem nome
        if (tmp == NULL) { 
            return false; 
        } 
        //só um nome, apaga o mesmo
        if (tmp->name == name && tmp->next == NULL) { 
            tmp->next = NULL; 
            delete tmp; 
            return true; 
        } 
    
        //buscar as ocorrências do nome e apagar elas, puxando as linhas que estão depois da linha apagada
        while (tmp->name != name && tmp->next != NULL) { 
            par = tmp; 
            tmp = tmp->next; 
        } 
        if (tmp->name == name && tmp->next != NULL) { 
            par->next = tmp->next; 
            tmp->next = NULL; 
            delete tmp; 
            return true; 
        } 
    
        // Deleta no final se for o último
        else { 
            par->next = NULL; 
            tmp->next = NULL; 
            delete tmp; 
            return true; 
        } 
        return false; 
    }, 
};

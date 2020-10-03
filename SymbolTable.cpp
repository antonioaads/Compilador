#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

#include "Line.cpp"
const int SIZE = 20;

class SymbolTable{

Line* lines[SIZE];


    public:
    SymbolTable(){
        for(int i = 0; i < SIZE; i++){
            lines[i] = NULL;
        }
    };

    int insertName(string name, int level, string type){
        int i = 0;
        Line* line = new Line(name, level, type, 1);
        //se ainda nao existem linhas, adiciona na primeira
        if(lines[i] == NULL) {
            lines[i] = line;
            return true;
        }
        //passa as linhas ate chegar no final e adiciona
        else{
            Line* first = lines[i];
            while(first->next != NULL){
                first = first->next;
            }
            first->next = line;
            return true;
        }
        return false;
    };    

    bool searchForName(string name, int level, string type){
        Line* first = lines[0];
        //retorna se nao existem linhas ainda
        if(first == NULL){
            return false;
        }
        //passa as linhas ate encontrar o nome
        while(first != NULL){
            if(first->name == name){
                return true;
            }
            first = first->next;
        }

        return false;
    };

    string getAttributes(string name){ 
        Line* line = lines[0]; 
        //se não tiver linhas    
        if (line == NULL) { 
            return "NotFound"; 
        }
        //busca pelo nome que queremos os atributos
        do{
            line = line->next; 
        }while (line->name != name && line->next != NULL);
        //se encontrou retorna o atributo
        if (line->name == name) {             
            return line->type; 
        }
        //se saiu do while sem encontrar
        return "NotFound";
    };

    bool removeName(string name){
        Line* tmp = lines[0]; 
        Line* par = lines[0]; 
    
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
    };
};

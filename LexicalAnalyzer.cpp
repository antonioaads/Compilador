#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class LexicalAnalyzer{
    public:
        LexicalAnalyzer();
        LexicalAnalyzer(string fileName){
            this->line = 0;
            this->fileName = fileName;
            
            FILE *file; 
            
            file = fopen("exemplo.txt", "r");
            
            if(file == NULL)
            {
                throw "Deu erro";
            }
            
            this->file = file;
        }

        char getNextToken(){
            int state = 1;
            int i = 0;
            while(!feof(file)){
            ++i;
            // for(int i = 0; i< 5; i++){
                if(getNewChar){
                    c = getc(file);
                }
                else getNewChar = true;

                switch(state) {
                    // Nó de entrada
                    case 1:
                        log(1);
                        // Tratando início de palavras reservadas
                        if(c == 'p') state = 171;
                        else if(c == 'i') state = 11;
                        else if(c == 'c') state = 61;
                        else if(c == 'd') state = 161;
                        else if(c == 'e') state = 81;
                        else if(c == 'f') state = 101;
                        else if(c == 'o') state = 111;
                        else if(c == 'r') state = 121;
                        else if(c == 't') state = 131;
                        else if(c == 'u') state = 141;
                        else if(c == 'w') state = 151;

                        // Tratando identificadores
                        else if(isLetter(c)) state = 182;

                        break;
                    
                    case 11:
                        log(11);
                        // Tratando palavras reservadas
                        if(c == 's') state = 12;
                        else if(c == 'f') state = 22;
                        else if(c == 'n') state = 32; 

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN IDENTIFICADOR
                        }  

                        break;

                    case 12:
                        log(12);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN IS
                        } 

                        break;

                    case 22:
                        log(22);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN IF
                        } 

                        break;
                    
                    case 32:
                        log(32);
                        // Tratando palavras reservadas
                        if(c == 't') state = 43;
                        else if(c == 'i') state = 53;

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN IN
                        } 

                        break;

                    case 43:
                        log(43);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN INT
                        } 

                        break;

                    case 53:
                        log(53);
                        // Tratando palavras reservadas
                        if(c == 't') state = 54;

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN IDENTIFICADOR
                        } 

                        break;

                    case 54:
                        log(54);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) state = 182;   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            //AQUI LÓGICA DE ENCONTROU TOKEN INIT
                        } 

                        break;
                    
                    
                    default:
                        break;

                }
            }

            return c;
        }
    private:
        string fileName;
        FILE *file;
        int line;
        bool getNewChar = true;
        char c;

        string primaryLimiter = " <>=!,";

        bool isLetter(char c){
            return (int)c >= (int)'A' && (int)c <= (int)'Z' || (int)c >= (int)'a' && (int)c <= (int)'z';
        }

        bool isNumber(char c){
            return (int)c >= (int)'0' && (int)c <= (int)'9';
        }

        bool isCharIdentifier(char c){
            return isLetter(c) || isNumber(c) || c == '_';
        }

        bool isPrimaryLimiter(char c){
            for(int i = 0; i < primaryLimiter.length(); i++){
                if(c == primaryLimiter[i]) return true;
            }
            return false;
        }

        void log(int state){
            cout << "Entrou no estado: " << state << "Com o caracter: " << c << endl;
        }

};
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

            char c = getc(file);


            switch(state) {
                // Nó de entrada
                case 1:
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

                    // Tratar variáveis e sinais
                    else if((int)c == 1) state = 0;
                
                case 11:
                    if(c == 's') state = 12;
                    else if(c == 'f') state = 22;
                    else if(c == 'n') state = 32;     
                
                default:
                    break;

            }


            return c;
        }
    private:
        string fileName;
        FILE *file;
        int line;
};
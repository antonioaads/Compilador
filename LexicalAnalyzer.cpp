#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class LexicalAnalyzer{
    public:
        LexicalAnalyzer();
        LexicalAnalyzer(string fileName, Node nodes[], Way *ways[]){
            this->line = 0;
            this->fileName = fileName;
            this->nodes = nodes;
            this->ways = ways;

            structure = Structure();

            FILE *file; 
            
            file = fopen("exemplo.txt", "r");
            
            if(file == NULL)
            {
                throw "Deu erro";
            }
            
            this->file = file;
        }

        Token getNextToken(){
            state = 1;
            leitura = "";
            token = Token(TokenTypes::IDENTIFIER, leitura);
            
            Way teste = structure.getWay(0, 0);
            cout << "testex" << nodes[0].number << endl;
            
            //while(1){
            for(int i = 0; i< 10; i++){
                cout << "entrou" << endl;
                if(getNewChar){
                    c = getc(file);
                }
                else getNewChar = true;

                // Nó de entrada
                if(state == 1) {
                    log();
                    // Tratando início de palavras reservadas
                    if(c == 'p') matchChar(171);
                    else if(c == 'c') matchChar(61);
                    else if(c == 'd') matchChar(161);
                    else if(c == 'e') matchChar(81);
                    else if(c == 'i') matchChar(11);
                    else if(c == 'f') matchChar(101);
                    else if(c == 'o') matchChar(111);
                    else if(c == 'r') matchChar(121);
                    else if(c == 't') matchChar(131);
                    else if(c == 'u') matchChar(141);
                    else if(c == 'w') matchChar(151);

                    // Tratando identificadores
                    else if(isLetter(c)) matchChar(182);
                    
                    // Tratando excecoes
                    else if(c == ' ') state = 1;
                }
                else {
                    for(int i = 0; i < structure.getSize(); i++){
                        if(state == structure.getNode(i).number){
                            log();
                            bool matchCharDone = false;

                            for(int j = 0; j < structure.getNode(i).quantWays; j++){
                                Way teste = structure.getWay(0, 0);
                                cout << teste.destiny;
                                cout << "i: " << i << " j " << j << " Numero node " << structure.getNode(i).number << " way: " << ways[0] << endl;
                                if(c == structure.getWay(i,j).matchChar) {
                                    matchChar(structure.getWay(i,j).destiny);
                                    matchCharDone = true;
                                    break;
                                }
                            }

                            // Tratando Nodo final
                            if(!matchCharDone) {
                                finalNodeStandartWord(structure.getNode(i).finalToken);
                                if(token.isNotNull()){
                                    logToken();    
                                    return token;
                                } 
                            }  
                            break;
                        }
                    }
                }
                
            };

            return Token(123, "Defalt error");
        };
    private:
        string fileName;
        FILE *file;
        int line;
        bool getNewChar = true;
        char c;
        int state = 1;
        string leitura;
        Token token = Token(TokenTypes::IDENTIFIER, leitura);
        string primaryLimiter = " <>=!,\n\t";
        Structure structure;
        Node *nodes; 
        Way **ways;

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
            if(c == EOF) return true;
            return false;
        }

        void log(){
            cout << "Entrou no estado: " << state << " Com o caracter: " << c << endl;
        }

        void logToken(){
            cout << "Enviou o token: " << token.lexema << endl;
        }

        void matchChar(int newState){
            cout << "matchChar" << newState << " " << c << endl;
            state = newState;
            leitura += c;
        }

        void cacheAsterisk(){
            getNewChar = false;
        }

        void finalNodeStandartWord(int tokenType){
            token = Token();

            // Tratando identificadores
            if(isCharIdentifier(c)) matchChar(182);

            // Tratando fim de token
            else if(isPrimaryLimiter(c)){
                // Função asterisco
                cacheAsterisk();

                //ENCONTROU TOKEN CHAR
                token = Token(tokenType, leitura); 
            }
        }

};
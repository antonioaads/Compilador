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

        Token getNextToken(){
            int state = 1;
            string leitura;
            Token token = Token(TokenTypes::IDENTIFIER, leitura);
            //while(1){
            for(int i = 0; i< 5; i++){
                if(getNewChar){
                    c = getc(file);
                }
                else getNewChar = true;

                switch(state) {
                    // Nó de entrada
                    case 1:
                        log(1);
                        // Tratando início de palavras reservadas
                        if(c == 'p') matchChar(171, 'p', &state, &leitura);
                        else if(c == 'c') matchChar(61, 'c', &state, &leitura);
                        else if(c == 'd') matchChar(161, 'd', &state, &leitura);
                        else if(c == 'e') matchChar(81, 'e', &state, &leitura);
                        else if(c == 'i') matchChar(11, 'i', &state, &leitura);
                        else if(c == 'f') matchChar(101, 'f', &state, &leitura);
                        else if(c == 'o') matchChar(111, 'o', &state, &leitura);
                        else if(c == 'r') matchChar(121, 'r', &state, &leitura);
                        else if(c == 't') matchChar(131, 't', &state, &leitura);
                        else if(c == 'u') matchChar(141, 'u', &state, &leitura);
                        else if(c == 'w') matchChar(151, 'w', &state, &leitura);

                        // Tratando identificadores
                        else if(isLetter(c)) matchChar(182, c, &state, &leitura);
                        
                        // Tratando excecoes
                        else if(c == ' ') state = 1;

                        break;
                    
                    case 11:
                        log(11);
                        // Tratando palavras reservadas
                        if(c == 's') matchChar(12, 's', &state, &leitura);
                        else if(c == 'n') matchChar(32, 'n', &state, &leitura);
                        else if(c == 'f') matchChar(22, 'f', &state, &leitura);

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);  

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN IDENTIFICADOR
                            token = Token(TokenTypes::IDENTIFIER, leitura);
                            logToken(token); 
                            return token;
                        }  

                        break;

                    case 12:
                        log(12);
 
                        // Tratando identificadores
                        if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN IS
                            token = Token(TokenTypes::IS, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;

                    case 22:
                        log(22);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //AQUI LÓGICA DE ENCONTROU TOKEN IF
                            token = Token(TokenTypes::IF, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;
                    
                    case 32:
                        log(32);
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(43, 't', &state, &leitura);
                        else if(c == 'i') matchChar(53, 'i', &state, &leitura);

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);   

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN IN
                            token = Token(TokenTypes::IN, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;

                    case 43:
                        log(43);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN INT
                            token = Token(TokenTypes::INT, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;

                    case 53:
                        log(53);
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(54, 't', &state, &leitura);

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN IDENTIFICADOR
                            token = Token(TokenTypes::IDENTIFIER, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;

                    case 54:
                        log(54);
                        // Tratando identificadores
                        if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN INIT
                            token = Token(TokenTypes::INIT, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;
                    
                    case 61:
                        log(53);
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(54, 't', &state, &leitura);

                        // Tratando identificadores
                        else if(isCharIdentifier(c)) matchChar(182, c, &state, &leitura);

                        // Tratando fim de token
                        else if(isPrimaryLimiter(c)){
                            // Função asterisco
                            cacheAsterisk();

                            //ENCONTROU TOKEN IDENTIFICADOR
                            token = Token(TokenTypes::IDENTIFIER, leitura);
                            logToken(token); 
                            return token;
                        } 

                        break;

                    default:
                        break;

                }
            }

            return Token(123, leitura);;
        }
    private:
        string fileName;
        FILE *file;
        int line;
        bool getNewChar = true;
        char c;

        string primaryLimiter = " <>=!,\n\t";

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

        void log(int state){
            cout << "Entrou no estado: " << state << " Com o caracter: " << c << endl;
        }

        void logToken(Token token){
            cout << "Enviou o token: " << token.lexema << endl;
        }

        void matchChar(int state, char c, int* stateRef, string* leituraRef){
            *stateRef = state;
            *leituraRef += c;
        }

        void cacheAsterisk(){
            getNewChar = false;
        }

};
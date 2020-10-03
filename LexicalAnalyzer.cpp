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
            state = 1;
            leitura = "";
            token = Token(TokenTypes::IDENTIFIER, leitura);
            while(1){
            //for(int i = 0; i< 10; i++){
                if(getNewChar){
                    c = getc(file);
                }
                else getNewChar = true;

                switch(state) {
                    // Nó de entrada
                    case 1:
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

                        // Tratando pontuações únicas
                        else if(c == ':'){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::COLON, ":");
                        }
                        else if(c == ';'){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::SEMICOLON, ";");
                        }
                        else if(c == ','){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::COMMA, ",");
                        }
                        else if(c == '+'){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::ADDOP, "+");
                        }
                        else if(c == '-'){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::ADDOP, "-");
                        }
                        else if(c == '*'){
                            matchChar(1);
                            logToken();
                            return Token(TokenTypes::MULOP, "*");
                        }

                        break;
                    
                    case 11:
                        log();
                        // Tratando palavras reservadas
                        if(c == 's') matchChar(12);
                        else if(c == 'n') matchChar(32);
                        else if(c == 'f') matchChar(22);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }  
                        break;

                    case 12:
                        log();
                        finalNodeStandartWord(TokenTypes::IS);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        } 
                        break;

                    case 22:
                        log();
                        finalNodeStandartWord(TokenTypes::IF);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        } 
                        break;
                    
                    case 32:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(43);
                        else if(c == 'i') matchChar(53);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IN);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        } 
                        break;

                    case 43:
                        log();
                        finalNodeStandartWord(TokenTypes::INT);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        } 
                        break;

                    case 53:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(54);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        } 
                        break;

                    case 54:
                        log();
                        finalNodeStandartWord(TokenTypes::INIT);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;
                    
                    case 61:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'h') matchChar(62);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        } 
                        break;

                    case 62:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'a') matchChar(63);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        } 
                        break;

                    case 63:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'r') matchChar(64);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;
                    
                    case 64:
                        log();
                        finalNodeStandartWord(TokenTypes::CHAR);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 161:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'o') matchChar(162);
                        else if(c == 'e') matchChar(72);

                        // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        } 
                        break;

                    case 162:
                        log();
                        finalNodeStandartWord(TokenTypes::DO);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;
                    
                    case 72:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'c') matchChar(73);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;
                    
                    case 73:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'l') matchChar(74);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 74:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'a') matchChar(75);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 75:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'r') matchChar(76);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 76:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(77);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 77:
                        log();
                        finalNodeStandartWord(TokenTypes::DECLARE);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 81:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'n') matchChar(82);
                        else if(c == 'l') matchChar(92);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 82:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'd') matchChar(83);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 83:
                        log();
                        finalNodeStandartWord(TokenTypes::END);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 92:
                        log();
                        // Tratando palavras reservadas
                        if(c == 's') matchChar(93);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 93:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(94);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 94:
                        log();
                        finalNodeStandartWord(TokenTypes::ELSE);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 101:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'l') matchChar(102);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 102:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'o') matchChar(103);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 103:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'a') matchChar(104);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 104:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(105);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 105:
                        log();
                        finalNodeStandartWord(TokenTypes::FLOAT);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 111:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'u') matchChar(112);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 112:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(113);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 113:
                        log();
                        finalNodeStandartWord(TokenTypes::OUT);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 121:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(122);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 122:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'p') matchChar(123);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 123:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(124);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 124:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'a') matchChar(125);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 125:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(126);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 126:
                        log();
                        finalNodeStandartWord(TokenTypes::REPEAT);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 131:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'h') matchChar(132);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 132:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(133);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 133:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'n') matchChar(134);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 134:
                        log();
                        finalNodeStandartWord(TokenTypes::THEN);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 141:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'n') matchChar(142);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 142:
                        log();
                        // Tratando palavras reservadas
                        if(c == 't') matchChar(143);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 143:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'i') matchChar(144);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 144:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'l') matchChar(145);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 145:
                        log();
                        finalNodeStandartWord(TokenTypes::UNTIL);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 151:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'h') matchChar(152);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 152:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'i') matchChar(153);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 153:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'l') matchChar(154);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 154:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'e') matchChar(155);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 155:
                        log();
                        finalNodeStandartWord(TokenTypes::WHILE);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 171:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'r') matchChar(172);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 172:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'o') matchChar(173);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 173:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'g') matchChar(174);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 174:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'r') matchChar(175);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 175:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'a') matchChar(176);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;

                    case 176:
                        log();
                        // Tratando palavras reservadas
                        if(c == 'm') matchChar(177);

                       // Tratando Nodo final
                        else {
                            finalNodeStandartWord(TokenTypes::IDENTIFIER);
                            if(token.isNotNull()){
                                logToken();    
                                return token;
                            } 
                        }
                        break;
                        
                    case 177:
                        log();
                        finalNodeStandartWord(TokenTypes::PROGRAM);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 182:
                        log();
                        finalNodeStandartWord(TokenTypes::IDENTIFIER);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    case 191:
                        log();
                        finalNodeStandartWord(TokenTypes::IDENTIFIER);
                        if(token.isNotNull()){
                            logToken();    
                            return token;
                        }
                        break;

                    default:
                        break;

                }
            }

            return Token(123, "Defalt error");;
        }
    private:
        string fileName;
        FILE *file;
        int line;
        bool getNewChar = true;
        char c;
        int state = 1;
        string leitura;
        Token token = Token(TokenTypes::IDENTIFIER, leitura);
        string primaryLimiter = " <>=!,:;+-*/\n\t";

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
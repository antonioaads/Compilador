#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Token{
    private:
        string nome;
    public:
        void setNome(string nome){
            this->nome = nome;
        }
        string getNome(){
            return nome;
        }
};
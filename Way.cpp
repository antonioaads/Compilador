#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

struct Way {
    int destiny;
    char matchChar;

    Way(char MatchChar, int Destiny){
        this->destiny = Destiny;
        this->matchChar = MatchChar;
    };
};

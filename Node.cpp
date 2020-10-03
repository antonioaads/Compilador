#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    int number;
    int type;
    int quantWays;
    int finalToken;

    Node(int number, int quantWays, int finalToken, int type){
        this->number = number;
        this->quantWays = quantWays;
        this->finalToken = finalToken;
        this->type = type;
    };
};
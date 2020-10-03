#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Structure {
    private:
        static const int structureSize = 7;

        Way ways11[3] = {Way('s', 12), Way('f',5), Way('n',32)};
        Node node11 = Node(11, 3, TokenTypes::IDENTIFIER, NodeTypes::INTERMEDIATE);

        Node node12 = Node(12, 0, TokenTypes::IS, NodeTypes::FINALY);

        Node node22 = Node(22, 0, TokenTypes::IF, NodeTypes::FINALY);

        Way ways32[2] = {Way('t',43), Way('i',53)};
        Node node32 = Node(32, 2, TokenTypes::IN, NodeTypes::INTERMEDIATE);

        Node node43 = Node(43, 0, TokenTypes::INT, NodeTypes::FINALY);

        Way ways53[1] = {Way('t',54)};
        Node node53 = Node(53, 1, TokenTypes::IDENTIFIER, NodeTypes::INTERMEDIATE);
        
        Node node54 = Node(54, 0, TokenTypes::INIT, NodeTypes::FINALY);

        Node nodes[structureSize] = {
            node11,
            node12,
            node22,
            node32,
            node43,
            node53,
            node54
        }; 
        Way *wayList[structureSize] = {
            ways11,
            {},
            {},
            ways32,
            {},
            ways53,
            {}
        }; 
    public:
        Node getNode(int i){
            return nodes[i];
        }

        Way getWay(int i, int j){
            Way teste = wayList[i][j];
            return teste;
        }

        int getSize() {
            return structureSize;
        }
};

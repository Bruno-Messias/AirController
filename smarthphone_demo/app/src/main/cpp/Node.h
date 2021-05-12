//
// Created by bruno on 12/05/2021.
//

#ifndef HELLO_CMAKE_NODE_H
#define HELLO_CMAKE_NODE_H

#include <string>
using namespace std;

class Node {
    string log;
    Node* next;
public:
    Node(string log, Node* next);

    string getVal();
    Node* getNext();
    void setNext(Node* nxt);
};

#endif //HELLO_CMAKE_NODE_H

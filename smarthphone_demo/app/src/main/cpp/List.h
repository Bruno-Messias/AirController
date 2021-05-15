//
// Created by bruno on 12/05/2021.
//

#ifndef HELLO_CMAKE_LIST_H
#define HELLO_CMAKE_LIST_H

#include "Node.h"
#include <tuple>

class List {
    Node* head;
public:
    List();
    ~List();
    void insertAfterLast(string newLog);
    string listLogs();
    string printLog(Node * aux);
    string displayTotalTime();
    tuple<int, int, int, int, int, int , int, char> convertLog(string log);
};


#endif //HELLO_CMAKE_LIST_H

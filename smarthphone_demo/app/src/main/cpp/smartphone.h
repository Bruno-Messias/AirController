//
// Created by bruno on 11/05/2021.
//
#ifndef HELLO_CMAKE_SMARTPHONE_H
#define HELLO_CMAKE_SMARTPHONE_H

#include "List.h"

class DataLog {
    string log;
    List lista;

public:
    void addEvent();
    string listEvents();
    string totalTime();
};

#endif //HELLO_CMAKE_SMARTPHONE_H


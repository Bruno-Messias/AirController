//
// Created by bruno on 11/05/2021.
//
#include "smartphone.h"

string DataLog::listEvents()
{
    string info;
    info = lista.listLogs();
    return info;
}

string DataLog::totalTime()
{
    string info;
    info = lista.displayTotalTime();
    return info;
}

void DataLog::addEvent() {
    lista.insertAfterLast("1/21:5:12:12:10:0/b");
    lista.insertAfterLast("1/21:5:12:12:20:0/a");
    lista.insertAfterLast("1/21:5:12:12:30:0/b");
    lista.insertAfterLast("1/21:5:12:12:40:0/a");
}
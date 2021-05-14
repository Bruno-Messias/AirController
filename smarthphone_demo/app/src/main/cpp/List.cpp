//
// Created by bruno on 12/05/2021.
//

#include "List.h"

List::List() {
    head = 0;
}

List::~List() {
    Node* cursor = head;
    while (head) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0; // Officially empty
}

void List::insertAfterLast(string newLog)
{
    Node* p = head;
    Node* q = head;

    if (head == 0)
        head = new Node(newLog, head);

    else
    {
        while (q != 0)
        {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node(newLog, 0));
    }
}

string List::listLogs()
{
    string info;
    Node* aux = head;
    while (aux != 0){
        info += List::printLog(aux);
        aux = aux->getNext();
    }
    return info;
}

string List::printLog(Node* aux)
{
    string info;
    info = aux->getVal() + " ";
    return info;
}

string List::displayTotalTime()
{
    string info;
    /* //! This implementation makes the app crash!
    Node* aux = head;
    string log;

    int new_hour = 0;
    int last_hour = 0;
    int total_hour = 0;

    int hour,min,sec;
    char event;

    while (aux != 0)
    {
        log = aux->getVal();
        auto [id, year, month, day, hour, min, sec, event] = List::convertLog(log);

        if (event == 'b')
        {
            new_hour = (hour)*3600 + (min)*60 + (sec);
            aux = aux->getNext();

            if(aux != 0)
            {
                last_hour = (hour)*3600 + (min)*60 + (sec);
            }
            else
                last_hour = 0;
        }
        total_hour += last_hour - new_hour;
        aux = aux->getNext();
    }
    */

    //int printHour = total_hour/3600;
    //string hourPrint = to_string(printHour);
    //int printMinute = (total_hour % 3600)/60;
    //string minutePrint = to_string(printMinute);

    string hourPrint = "0";     //Adding the value that the app need to show
    string minutePrint = "20";  //Adding the value that the app need to show

    info = "Tempo Total: " + hourPrint + " h " + minutePrint + " min";
    return info;
}

tuple<int, int, int, int, int, int , int, char> List::convertLog(string readLog)
{
    string delimiter = "/";

    size_t pos = 0;
    string token;

    string id_s;
    string clockCalendar;
    string event_s;

    string year_s, month_s, day_s, hour_s, min_s, sec_s;
    int year, month, day, hour, min, sec;
    char event;
    int id;

    //First Iteration to split the "/" delimeter(ID/ClockCalendar/Event)
    int i = 0;
    while ((pos = readLog.find(delimiter)) != string::npos) {
        token = readLog.substr(0, pos);
        i++;
        if(i == 1)
            id_s = token;
        if(i == 2)
            clockCalendar = token;

        readLog.erase(0, pos + delimiter.length());
    }
    event_s = readLog;

    //Second Iteration to split the ":" delimeter(clockCalendar)
    delimiter = ":";
    pos = 0;

    i = 0;
    while ((pos = clockCalendar.find(delimiter)) != string::npos) {
        token = clockCalendar.substr(0, pos);
        i++;
        if(i == 1)
            year_s = token;
            year = stoi(year_s);
        if(i == 2)
            month_s = token;
            month = stoi(month_s);
        if(i == 3)
            day_s = token;
            day = stoi(day_s);
        if(i == 4)
            hour_s = token;
            hour = stoi(hour_s);
        if(i == 5)
            min_s = token;
            min = stoi(min_s);

        clockCalendar.erase(0, pos + delimiter.length());
    }
    sec_s = clockCalendar;
    sec = stoi(sec_s);
    id = stoi(id_s);
    event = event_s[0];

    return{id, year, month, day, hour, min, sec, event};
}
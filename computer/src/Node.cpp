#include "Node.h"

// Constructor - initializes the node
Node::Node(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent ,Node* nxt) {
    year = newYear;
    month = newMonth;
    day = newDay;
    hour = newHour;
    min = newMin;
    sec = newSec;
    event = newEvent;
    next = nxt;
}

int Node::getYear()
{
    return year;
}

int Node::getMonth()
{
    return month;
}

int Node::getDay()
{
    return day;
}

int Node::getHour()
{
    return hour;
}

int Node::getMin()
{
    return min;
}

int Node::getSec()
{
    return sec;
}

char Node::getEvent()
{
    return event;
}

// getNext returns a pointer for the next node in the linked list
Node* Node::getNext() {
    return next;
}

// setNext stores the pointer to the next node in the list in the "next" field
void Node::setNext(Node* nxt) {
    next = nxt;
}
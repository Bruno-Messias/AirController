#include "Node.h"
#include "Headers.h"

class List {
    Node* head;
public:
    List();
    ~List();
    void insertAfterLast(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent);
    char* removeNode(char* dat);
    void listLogs(int max_day, int min_day, int year, int month);
    void printLog(Node *aux);
    void displayTotalTime();
};
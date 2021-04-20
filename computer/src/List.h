#include "Node.h"
#include "Headers.h"

class List {
    Node* head;
public:
    List();
    ~List();
    void insertAfterLast(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent);
    void removeFirst();
    char* removeNode(char* dat);
    void listAll();
    void listLogs(int max_day, int min_day);
    void printLog(Node *aux);
    float displayTotalTime();
    void mostUsedDay();
};
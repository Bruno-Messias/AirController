

using namespace std;

class Node {
    int id,year,month,day,hour,min,sec;
    char event;
    Node* next;
public:
    Node(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent ,Node* nxt);

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMin();
    int getSec();
    char getEvent();

    Node* getNext();
    void setNext(Node* nxt);
};
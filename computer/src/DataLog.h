
#include "List.h"
#include "kbhit.h"

#include <string>

class DataLog {
    string log;        
    keyboard key;
    List lista;
    int serial_port;
public:
    bool flag;

    DataLog() {}
    ~DataLog() {}

    int setInit();
    int readLog();
    void conversionLog(string read_log);
    void addLog(int id, string year_s, string month_s, string day_s, string hour_s, string min_s, string sec_s, char event);
    void listEvents();
    void displayMenu();
    void interruptFunction();
    void totalTime();
    void mostUsedDay();
};
#include "DataLog.h"

int DataLog::setInit()
{
    // Open the serial port
    serial_port = open("/dev/ttyACM0", O_RDWR);

    // Create new termios struc for termios handle
    struct termios tty;

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port, &tty) != 0) 
    {
        cout <<"Error " << errno << " from tcsetattr: " << strerror(errno) << endl;
        return 1;
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity 
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication 
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
    tty.c_cflag |= CS8; // 8 bits per byte 
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control 
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    tty.c_oflag &= ~OPOST;  // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR;  // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 10;   // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 23;    // Wait for 23 bytes of the string for the log 

    // Set in/out baud rate to be 9600
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        cout <<"Error " << errno << " from tcsetattr: " << strerror(errno) << endl;
        return 1;
    }

    return 0;
}

int DataLog::readLog() 
{
    char read_buf[24];

    memset(&read_buf, '\0', sizeof(read_buf));      //Allocating memory for the buffer receiver

    //Getting number of bytes received to check if is something to read
    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));

    if (num_bytes < 0)                              //Check For error in receiver
    {
        cout << "Error reading: " << strerror(errno) << endl;;
        return 1;
    }

     if(num_bytes > 0)                              //Check If is something tho read
     {
        log = read_buf;
        DataLog::conversionLog(log);
     }

    return 0;
}

void DataLog::conversionLog(string readLog)
{
    string delimiter = "/";

    size_t pos = 0;
    string token;
    
    string id_s;
    string clockCalendar;
    string event_s;

    string year_s, month_s, day_s, hour_s, min_s, sec_s;
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
        if(i == 2)
            month_s = token;
        if(i == 3)
            day_s = token;
        if(i == 4)
            hour_s = token;
        if(i == 5)
            min_s = token;

        clockCalendar.erase(0, pos + delimiter.length());
    }
    sec_s = clockCalendar;

    //Handle Parse data Error convertion ID
    try{
        id = stoi(id_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        id = -1;
    }

    //Handle Parse data Error convertion Event
    try{
        event = event_s[0];
    }
    catch(exception &err){
        cout <<"Conversion failure: "<< err.what() << endl;
        event = '0';
    }
    
    //Test receiver elements
    if((id != 1) || (event == '0'))
    {
        cout << "Data Corrupted - Log doest stored!" << endl; 
    }
    else if ((event == 'a')||(event =='b'))
    {
        DataLog::addLog(id, year_s, month_s, day_s, hour_s, min_s, sec_s, event);
    }
    else
    {
        cout << "Data Corrupted - Log doest stored!" << endl; 
    }
}

void DataLog::addLog(int id, string year_s, string month_s, string day_s, string hour_s, string min_s, string sec_s, char event)
{
    int year, month, day, hour, min, sec;
    bool error = false;

    // -------- Year Error handle
    try
    {
       year = stoi(year_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }

    // -------- Month Error handle
    try
    {
       month = stoi(month_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }

     // -------- Day Error handle
    try
    {
       day = stoi(day_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }

    // -------- Hour Error handle
    try
    {
       hour = stoi(hour_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }

    // -------- Minute Error handle
    try
    {
       min = stoi(min_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }

    // -------- Sec Error handle
    try
    {
       sec = stoi(sec_s);
    }
    catch(exception &err)
    {
        cout <<"Conversion failure: "<< err.what() << endl;
        error = true;
    }
    
    if(error) //Checks for conversion Errors
    {
        cout << "Data Corrupted - Log doest stored!" << endl; 
    }
    else
    {
        cout << "Log Stored!" << endl;
        lista.insertAfterLast(year,month,day,hour,min,sec,event);
    }
    
}

void DataLog::listEvents()
{
    int min_day, max_day;
    cout << "Select the Minimun day: " << endl;
    cin >> min_day;
    cout << "Select the Maximun day: " << endl;
    cin >> max_day;
    
    lista.listLogs(max_day, min_day);
}

void DataLog::totalTime()
{
    cout << "Total Time used: "  << lista.displayTotalTime() << endl;
}

void DataLog::mostUsedDay()
{
    cout << "Most Used day is: "<< endl;
    lista.mostUsedDay();
}

void DataLog::displayMenu()
{
    cout << endl;
    cout << "------------ Welcome to the Datalog System --------------------" << endl;
    cout << "Press 1 to list the logs" << endl;
    cout << "Press 2 to the total time the system turned on" << endl;
    cout << "Press 3 to the most used day" << endl;
    cout << "Press 4 to exit the program" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

void DataLog::interruptFunction()
{
    int key_nb;

    if(key.kbhit())
        {
            system("clear");
            key_nb = key.getch(); 
            flag = true;

            switch (key_nb)
            {
            case 49:
                DataLog::listEvents();  //Return the list of day in the range from the user
                break;
            case 50:
                DataLog::totalTime();   //Return the total time that the system is on
                break;
            case 51:
                DataLog::mostUsedDay(); //Return the most used day
                break;
            case 52:
                close(serial_port);
                exit(0);
            default:
                cout << "Invalid Selection, try again" << endl;
                break;
            }
        }
}
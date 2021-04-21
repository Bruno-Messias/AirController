

#include "DataLog.h"

using namespace std;

int main()
{
    DataLog host;
    host.setInit();                     //Initiate control to Read Serial Port
    
    //Output Loop to control the print system
    while(1)
    {   
        host.displayMenu();             //Display Menu with the functions for the admin

        //Inner Loop for the system read Logs
        while (1)
        {
            host.readLog();             //Read Logs form Serial Port
            host.interruptFunction();   //Interrupt Functions to select funcion menu
            
            //Check if the keyboar is pressed
            if (host.flag)          
            {
                host.flag = false;
                break;
            }
        }
    }

    return 0;
}
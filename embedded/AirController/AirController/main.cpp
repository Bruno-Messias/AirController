/*
 * AirController.cpp
 *
 * Created: 17/04/2021 18:14:41
 * Author : Bruno
 */ 

#include <avr/io.h>
#include "air_controler_atmega.cpp"


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

/*
 * PoolControler_AVR.cpp
 *
 * Created: 21/03/2021 16:20:44
 * Author : Bruno C. Messias 
 */ 

//bool flag = false; //flag interrupt, global variable
//
//#include "pool_controler_atmega.cpp"
	//
//int main(void)
//{
	//PoolControlerAtmega Controler;
//
	//while (1)
	//{
		//Controler.inputSW(); //Check for config of the administrator
		//Controler.FSM();
		//if (flag) //Check for interrupt at Reset button
		//{
			//Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer
			//flag = false;
		//}
		//Controler.checkLog(); //Check of event for create log
		//Controler.sendlog(); //Send the log via UART Interrupt based
	//}
	//
	//return 0;
//}

/*
 * AirController.cpp
 *
 * Created: 17/04/2021 18:14:41
 * Author : Bruno
 */ 

bool flag = false; //flag interrupt, global variable

#include "air_controler_atmega.cpp"
	
int main(void)
{
	AirControllerAtmega Controler;

	while (1)
	{
		Controler.FSM(); //Control and change for the next estate
		if (flag) //Check for interrupt at button press
		{
			Controler.estate = 3;  //If interrupt occur the next estate is ON
			flag = false;
		}
		Controler.checkLog(); //Check of event for create log
		Controler.sendLog(); //Send the log via UART Interrupt based	
		
	}
	
	return 0;
}

/*
 * AirController.cpp
 *
 * Created: 17/04/2021 18:14:41
 * Author : Bruno
 */ 

#include "air_controler_atmega.cpp"
	
int main(void)
{
	AirControllerAtmega Controler;

	while (1)
	{
		Controler.FSM(); //Control and change for the next estate
		Controler.checkLog(); //Check of event for create log
		Controler.sendLog(); //Send the log via UART Interrupt based	
		
	}
	
	return 0;
}

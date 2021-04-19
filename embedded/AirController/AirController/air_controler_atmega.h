#ifndef AIR_CONTROLER_ATMEGA_H
#define AIR_CONTROLER_ATMEGA_H

#include <string.h>
#include <stdlib.h>

#include "air_controler.cpp"
#include "ClockCalendar.h"
#include "List.cpp"
#include "USART.cpp"

class AirControllerAtmega : public AirController
{
	List data;
	ClockCalendar cc;
	
	int value, counter;
	
	public:
		AirControllerAtmega();
		void checkLog();
		void createLog(char*);
		void sendLog();
};

#endif // !AIR_CONTROLER_ATMEGA_H

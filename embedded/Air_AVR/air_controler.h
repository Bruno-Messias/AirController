#ifndef AIR_CONTROLER_H
#define AIR_CONTROLER_H

#include "pins_atmega328p.h"
#include "ClockCalendar.h"

class AirController
{
	public:
		int estate;
		
		AirController();
		void FSM();
		virtual void checkLog() = 0;
		virtual void createLog(char*) = 0;
		virtual void sendLog() = 0;
		
	protected:
		ClockCalendar cc;
		bool init, stop;
};

#endif // !AIR_CONTROLER_H


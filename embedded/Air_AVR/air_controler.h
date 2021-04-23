#ifndef AIR_CONTROLER_H
#define AIR_CONTROLER_H

#include "pins_atmega328p.h"

class AirController
{
	int estate;
		
	public:
		AirController();
		void FSM();
		bool getInit();
		bool getStop();
		virtual void checkLog() = 0;
		virtual void createLog(char*) = 0;
		virtual void sendLog() = 0;
		
	protected:
		bool init, stop;
};

#endif // !AIR_CONTROLER_H


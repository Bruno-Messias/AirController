#include "air_controler.h"

//-------------------------------------------------------
extern "C" void __cxa_pure_virtual() { while (1); } //Exception handler function that C++ needs when compiling classes with virtual functions not defined in GCC-AVR
//-------------------------------------------------------

AirController::AirController()
{
	estate = 0;		//Control the actual estate
	stop = false;	//Control for logs
	init = false;	//Control for logs
	
	//-- Define in's and out's --
	set_bit(DDRB, system_bit);
	set_bit(DDRB, led_bit);
	rst_bit(DDRB, aberture_bit);
	rst_bit(DDRB, button_bit);
	
	// -- Initiate Out bits --
	rst_bit(PORTB, system_bit);
	rst_bit(PORTB, led_bit);
}

void AirController::FSM() //Logic for next estate
{
	bool control = false;
	
	switch (estate)
	{
	case 0: //INIT

		estate = 1;
	
	case 1: //OFF
		
		stop = false;
		
		/* Setting estate output */
		set_bit(PORTB, led_bit);
		rst_bit(PORTB, system_bit);

		//Next Estate:
		while(!test_bit(PINB, aberture_bit))
		{
<<<<<<< Updated upstream
			estate = 1;
			break;
		}
		else
		{
			estate = 2;
			break;
		}
=======
			
		}
		estate = 2;
		break;
>>>>>>> Stashed changes

	case 2: //Standby
	
	/* Setting estate output */
	rst_bit(PORTB, led_bit);
	
	//Next Estate:
<<<<<<< Updated upstream
	if (test_bit(PINB, button_bit))
	{
		estate = 3;
		init = true;
		break;
	}
	else if (test_bit(PINB, aberture_bit))
=======
	while (test_bit(PINB, aberture_bit))
	{
		if (test_bit(PINB, button_bit))
		{
			control = true;
			break;
		}
	}

	if(control)
>>>>>>> Stashed changes
	{
		init = true;
		estate = 3;
		break;
	}
<<<<<<< Updated upstream
	else
	{
		estate = 2;
		break;
	}
=======
	
	estate = 1;
	break;
	
>>>>>>> Stashed changes

	case 3: //ON
	
	init = false;
	
	/* Setting estate output */
	set_bit(PORTB, system_bit);	
	
	//Next Estate:
<<<<<<< Updated upstream
	if(test_bit(PINB, aberture_bit))
	{
		estate = 1;
		stop = true;
		break;
	}
	else
	{
		estate = 3;
		break;
	}
=======
	
	while(test_bit(PINB,aberture_bit))
	{
		
	}
	stop = true;
	estate = 1;
	break;
>>>>>>> Stashed changes

	default:
		estate = 0;
		break;
	}
}

bool AirController::getInit()
{
	return init;
}

bool AirController::getStop()
{
	return stop;
}
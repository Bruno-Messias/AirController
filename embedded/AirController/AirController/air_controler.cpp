﻿#include "air_controler.h"

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
		if (test_bit(PINB, aberture_bit))
		{
			estate = 1;
			break;
		}
		else
		{
			estate = 2;
			break;
		}

	case 2: //Standby
	
	/* Setting estate output */
	rst_bit(PORTB, led_bit);
	
	//Next Estate:
	if (test_bit(PINB, button_bit))
	{
		estate = 3;
		init = true;
		break;
	}
	else if (test_bit(PINB, aberture_bit))
	{
		estate = 1;
		break;
	}
	else
	{
		estate = 2;
		break;
	}

	case 3: //ON
	
	init = false;
	
	/* Setting estate output */
	set_bit(PORTB, system_bit);	
	
	//Next Estate:
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

	default:
		estate = 0;
		break;
	}
}
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
	
	//-- Disable Interrupts --
	rst_bit(PCMSK0, PCINT0);				//Disable interrupt of reset_bit
	rst_bit(PCICR, PCIE0);					// Disable Interrupt
	
	//Set ClockCalendar for 1/4/2021 00:00:00
	cc.setCalendar(2021,4,1,0,0,5);
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
		while(!test_bit(PINB, aberture_bit))
		{
			_delay_ms(1000);
			cc.advance();
		}
		estate = 2;
		break;

	case 2: //Standby
	
		/* Setting estate output */
		rst_bit(PORTB, led_bit);
	
		//Next Estate:
		while (test_bit(PINB, aberture_bit))
		{
			//-- Setting the interrupt
			set_bit(PCMSK0, PCINT0);		//Enable interrupt of button_bit
			set_bit(PCICR, PCIE0);			// Need to enable for interrupt
		
			sei();							//Initiate check service routine
			
			_delay_ms(1000);
			cc.advance();
		
			if(flag)						//Adding flag to stop Timer
			{
				init = true;
				break;
			}
		}
		//-- Disable Interrupts --
		rst_bit(PCMSK0, PCINT0);				//Disable interrupt of reset_bit
		rst_bit(PCICR, PCIE0);					// Disable Interrupt
		estate = 1;
		break;
	
	case 3: //ON
	
	init = false;
	
	/* Setting estate output */
	set_bit(PORTB, system_bit);	
	
	//Next Estate:
	while(test_bit(PINB,aberture_bit))
	{
		_delay_ms(1000);
		cc.advance();
	}
	stop = true;
	estate = 1;
	break;

	default:
		estate = 0;
		break;
	}
}

ISR(PCINT0_vect) //Interrupt Service Routine of reset button(PORTB0)
{
	flag = true;
}

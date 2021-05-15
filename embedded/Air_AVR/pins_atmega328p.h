#ifndef PINS_H
#define PINS_H

//Pins Avr
#include <avr/io.h>
#include <avr/interrupt.h>

//#define F_CPU 1000000 // frequency oscillator for Simulation
#define F_CPU 16000000

#include <util/delay.h>

/* -- Defining Macros for pins -- */
#define set_bit(reg,bit)	(reg |= (1<<bit)) //set a bit in a register
#define rst_bit(reg,bit)	(reg &= ~(1<<bit)) // reset a bit in a register
#define test_bit(reg,bit)	(reg & (1<<bit)) // test a bit

/*-- Defining IO pins --*/
#define button_bit PORTB0		//Arduino: D8
#define led_bit PORTB1			//Arduino: D9
#define aberture_bit PORTB2		//Arduino: D10(SS)
#define system_bit PORTB3		//Arduino: D11(MOSI)

#endif //PINS_H 

//#ifndef PINS_H
//#define PINS_H
//
////Pins Avr
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
////#define F_CPU 1000000 // frequency oscillator for simulationK
//#define F_CPU 16000000
//
//#include <util/delay.h>
//
///* -- Defining Macros for pins -- */
//#define set_bit(reg,bit)	(reg |= (1<<bit)) //set a bit in a register
//#define rst_bit(reg,bit)	(reg &= ~(1<<bit)) // reset a bit in a register
//#define test_bit(reg,bit)	(reg & (1<<bit)) // test a bit
//
////Change pins name
//
///*-- Defining IO pins --*/
//#define pump_bit PORTD6		//Arduino: D6
//#define heater_bit PORTD7	//Arduino: D7
//#define reset_bit PORTB0	//Arduino: D8
//#define sw_bit PORTB4		//Arduino: D12
//#define low_bit PORTB1		//Arduino: D9
//
///*-- Defining SPI pins --*/
//#define PIN_SCK PORTB5		//Arduino: D13(SCK)
//#define PIN_MOSI PORTB3		//Arduino: D11(MOSI)
//#define PIN_SS PORTB2		//Arduino: D10(SS)
//
//#endif //PINS_H
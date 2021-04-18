#include "air_controler_atmega.h"
//
//PoolControlerAtmega::PoolControlerAtmega()
//{
	//estate = 0; // control the actual estate
	//counter = 0; //Control the minute advance timer
	//
	//sw = false; //in
	//init = false; //for check log
	//
	////-- Define in's and out's --
	//set_bit(DDRD, pump_bit);
	//set_bit(DDRD, heater_bit);
	//set_bit(DDRB, low_bit);
	//rst_bit(DDRB, sw_bit);
	//rst_bit(DDRB, reset_bit);
	//
	//// -- Initiate Out bits --
	//rst_bit(PORTD, pump_bit);
	//rst_bit(PORTD, heater_bit);
	//rst_bit(PORTB, low_bit);
	//
	////-- Disable Interrupts --
	//rst_bit(PCMSK0, PCINT0);				//Disable interrupt of reset_bit
	//rst_bit(PCICR, PCIE0);					// Disable Interrupt
	//
	//led.MAX7219_INIT();						//Initiate MAx7239
	//cc.setCalendar(2021,4,1,0,0,5);			//Set ClockCalendar for 1/4/2021 00:00:00
	//
	///* -- Initiate with 9600 BaudRate --*/
	//USART0_Init(MYUBBR);
	//sei();
//}
//
//void PoolControlerAtmega::inputSW() //Test for Admin choose
//{
	//if(test_bit(PINB, sw_bit))
	//{
		//sw = true;
	//}
	//else sw = false;
//}
//
//void PoolControlerAtmega::FSM() //Logic for next estate
//{
	//switch (estate)
	//{
		//case 0: //RESET
//
		///* Setting estate output */
		//rst_bit(PORTD, pump_bit);
		//rst_bit(PORTD, heater_bit);
		//rst_bit(PORTB, low_bit);
		//
		////-- Setting the interrupt
		//set_bit(PCMSK0, PCINT0);		//Enable interrupt of reset_bit
		//set_bit(PCICR, PCIE0);			// Need to enable for interrupt
		//
		//sei();						//Initiate check service routine
		//
		//while(1)
		//{
			//if(flag)
			//{
				//init = true;
				//break;
			//}
			//cc.advance();				// Advance Clock
			//_delay_ms(secs);
		//}
		//
		//case 1: //INIT
//
		//init = false;
		//
		//rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		//rst_bit(PCICR, PCIE0);			//Disable Interrupt
		//
		///* Setting estate output */
		//set_bit(PORTD, pump_bit);
		//set_bit(PORTD, heater_bit);
		//rst_bit(PORTB, low_bit);
//
		////Next Estate:
		//if (sw)
		//{
			//estate = 3;
			//break;
		//}
		//else
		//{
			//estate = 2;
			//break;
		//}
		//
		//case 2: //ON1 - 60min config
		//
		//counter = 0;				//Control for minute advance
		//time.setTimer(60);			//Set timer for 60 minutes
		//
		////Next Estate:
//
		//while (time.getTime() > 0 )
		//{
			//
			//if (time.getTime() < 5)
			//{
				//set_bit(PORTB, low_bit);			//Enable Low Signal
			//}
			//
			//if(counter >= 60)						//Control for minute advance
			//{
				//time.coutTimer();					//Advance Timer
				//counter = 0;
			//}
			//
			//cc.advance();							// Advance Clock
			//PoolControlerAtmega::displayTimer();	//Send Timer via SPI for display
			//_delay_ms(secs);
			//counter++;
			//
			////-- Setting the interrupt
			//set_bit(PCMSK0, PCINT0);	//Enable interrupt of reset_bit
			//set_bit(PCICR, PCIE0);		//Need to enable for interrupt
			//
			//sei();						//Initiate check service routine
			//
			//if(flag)					//Check for interrupt
			//{
				//break;
			//}
			//
		//}
		//rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		//rst_bit(PCICR, PCIE0);			//Disable Interrupt
		//rst_bit(PORTB, low_bit);		//Disable low signal
		//estate = 4;
		//break;
//
		//case 3: //ON2 - 30min config
		//
		//counter = 0;			//Control for minute advance
		//time.setTimer(30);		//Set timer for 30 minutes
		//
		////Next Estate:
		//while (time.getTime() > 0)
		//{
			//if (time.getTime() < 5)					//Check for low timer alert
			//{
				//set_bit(PORTB, low_bit);			//Enable low signal
			//}
			//
			//if(counter >= 60)						//Control for minute advance
			//{
				//time.coutTimer();					//Advance Timer
				//counter = 0;
			//}
			//
			//cc.advance();							//Advance Clock
			//PoolControlerAtmega::displayTimer();	//Send Timer via SPI for display
			//_delay_ms(secs);
			//counter++;
			//
			////-- Setting the interrupt
			//set_bit(PCMSK0, PCINT0);		//Enable interrupt of reset_bit
			//set_bit(PCICR, PCIE0);			// Need to enable for interrupt
			//
			//sei();							//Initiate check service routine
			//
			//if(flag)						//Adding flag to stop Timer
			//{
				//break;
			//}
			//
		//}
		//rst_bit(PORTB, low_bit);		//Disable low signal
		//rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		//rst_bit(PCICR, PCIE0);			// Disable Interrupt
		//estate = 4;
		//break;
		//
		//case 4: //OFF1
//
		///* Setting estate output */
		//rst_bit(PORTD, heater_bit);
//
		////Next Estate
		//estate = 5;
		//break;
		//
		//case 5: //OFF2
//
		////Next Estate:
		//time.setTimer(60);				//Set Timer for 1 minute
		//while (time.getTime() > 0)
		//{
			//time.coutTimer();			//Advance Timer
			//cc.advance();				//Advance Clock
			//_delay_ms(secs);
		//}
		//
		///* Setting estate output */
		//rst_bit(PORTD, pump_bit);
		//estate = 0;
		//break;
//
		//default:
		//estate = 0;
		//break;
	//}
//}
//
//void PoolControlerAtmega::setEstate(int newEstate) //Set a new state of the Controller
//{
	//estate = newEstate;
//}
//
//void PoolControlerAtmega::displayTimer() //Send information to the log
//{
	//value = time.getTime();				//Get time  for display in max7219 driver
	//led.MAX7219_displayNumber(value);	//Send Value to MAX7219 driver via SPI
	//
//}
//
//void PoolControlerAtmega::checkLog() //Check for Event to store a log
//{
	//char event[3];
	//
	//if(estate == 5)					//Check for timeout
	//{
		//event[0] = '/';
		//event[1] = 'a';
		//event[2] = '\0';
		//
	//}
	//else if(estate == 0 && flag)	//Check reset timer
	//{
		//event[0] = '/';
		//event[1] = 'c';
		//event[2] = '\0';
	//}
	//else if(init)					//Check for initialization of system
	//{
		//event[0] = '/';
		//event[1] = 'b';
		//event[2] = '\0';
	//}
	//
	//PoolControlerAtmega::createLog(event);
//}
//
//void PoolControlerAtmega::createLog(char* event)
//{
	//char log[] = "1/";
	//char ano_s[5], mes_s[3], dia_s[3], hora_s[3], min_s[3], sec_s[3];
	//char doublepoints[] = ":";
	//char slash[] = "/";
	//char null[] = "0";
	//
	//char mes_c,dia_c,hora_c,min_c,sec_c;
	//
	//int mes_aux, dia_aux, hora_aux, min_aux, sec_aux = 0;
	//
	////TODO: add a better function to concatenate information
	//
	///* -- Getting ClockCalendar Information -- */
	//itoa(cc.getAno(), ano_s, 10);
	//
	//
	//mes_aux = cc.getMes();
	//if (mes_aux <= 9)
	//{
		//mes_c = '0' + mes_aux;
		//mes_s[0] = '0';
		//mes_s[1] =  mes_c;
		//mes_s[2] = '\0';
	//}
	//else
	//{
		//itoa(mes_aux,mes_s,10);
	//}
	//
	//dia_aux = cc.getDia();
	//if (dia_aux <= 9)
	//{
		//dia_c = '0' + dia_aux;
		//dia_s[0] = '0';
		//dia_s[1] =  dia_c;
		//dia_s[2] = '\0';
	//}
	//else
	//{
		//itoa(dia_aux,dia_s,10);
	//}
	//
	//hora_aux = cc.getHora();
	//if (hora_aux <= 9)
	//{
		//hora_c = '0' + hora_aux;
		//hora_s[0] = '0';
		//hora_s[1] =  hora_c;
		//hora_s[2] = '\0';
	//}
	//else
	//{
		//itoa(hora_aux,hora_s,10);
	//}
	//
	//min_aux = cc.getMinuto();
	//if (min_aux <= 9)
	//{
		//min_c = '0' + min_aux;
		//min_s[0] = '0';
		//min_s[1] =  min_c;
		//min_s[2] = '\0';
	//}
	//else
	//{
		//itoa(min_aux,min_s,10);
	//}
	////
	//sec_aux = cc.getSegundo();
	//
	//if (sec_aux <= 9)
	//{
		//sec_c = '0' + sec_aux;
		//sec_s[0] = '0';
		//sec_s[1] =  sec_c;
		//sec_s[2] = '\0';
	//}
	//else
	//{
		//itoa(sec_aux,sec_s,10);
	//}
	//
	///* -- Concatenating the string to store */
	//strcat(log, ano_s);
	//strcat(log, doublepoints);
	//strcat(log, mes_s);
	//strcat(log, doublepoints);
	//strcat(log, dia_s);
	//strcat(log, doublepoints);
	//strcat(log, hora_s);
	//strcat(log, doublepoints);
	//strcat(log, min_s);
	//strcat(log, doublepoints);
	//strcat(log, sec_s);
	//strcat(log,slash);
	//strcat(log, event);
	//strcat(log,null);
	//
	//data.insertAfterLast(log); //Store the log in the data structure
//}
//
//void PoolControlerAtmega::sendlog() //Send LOG via UART
//{
	//USART_putstring(data.removeFirst());
//}
//
//
//ISR(PCINT0_vect) //Interrupt Service Routine of reset button(PORTB0)
//{
	//flag = true;
//}
//
//
//

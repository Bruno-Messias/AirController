#include "air_controler_atmega.h"

AirControllerAtmega::AirControllerAtmega()
{
	//Set ClockCalendar for 1/4/2021 00:00:00
	cc.setCalendar(2021,4,1,0,0,5);			
	
	/* -- Initiate USART with 9600 BaudRate --*/
	USART0_Init(MYUBBR);
	sei();
}

void AirControllerAtmega::checkLog() //Check for Event to store a log
{
	char event[3];
	
	if(stop)					//Check for stop Signal
	{
		event[0] = '/';
		event[1] = 'a';
		event[2] = '\0';
		
	}
	else if(init)				//Check for initialization of system
	{
		event[0] = '/';
		event[1] = 'b';
		event[2] = '\0';
	}
	
	AirControllerAtmega::createLog(event);
}

void AirControllerAtmega::createLog(char* event)
{
	char log[] = "1/";
	char ano_s[5], mes_s[3], dia_s[3], hora_s[3], min_s[3], sec_s[3];
	char doublepoints[] = ":";
	char slash[] = "/";
	char null[] = "0";
	
	char mes_c,dia_c,hora_c,min_c,sec_c;
	
	int mes_aux, dia_aux, hora_aux, min_aux, sec_aux = 0;
	
	//TODO: add a better function to concatenate information
	
	/* -- Getting ClockCalendar Information -- */
	itoa(cc.getAno(), ano_s, 10);
	
	
	mes_aux = cc.getMes();
	if (mes_aux <= 9)
	{
		mes_c = '0' + mes_aux;
		mes_s[0] = '0';
		mes_s[1] =  mes_c;
		mes_s[2] = '\0';
	}
	else
	{
		itoa(mes_aux,mes_s,10);
	}
	
	dia_aux = cc.getDia();
	if (dia_aux <= 9)
	{
		dia_c = '0' + dia_aux;
		dia_s[0] = '0';
		dia_s[1] =  dia_c;
		dia_s[2] = '\0';
	}
	else
	{
		itoa(dia_aux,dia_s,10);
	}
	
	hora_aux = cc.getHora();
	if (hora_aux <= 9)
	{
		hora_c = '0' + hora_aux;
		hora_s[0] = '0';
		hora_s[1] =  hora_c;
		hora_s[2] = '\0';
	}
	else
	{
		itoa(hora_aux,hora_s,10);
	}
	
	min_aux = cc.getMinuto();
	if (min_aux <= 9)
	{
		min_c = '0' + min_aux;
		min_s[0] = '0';
		min_s[1] =  min_c;
		min_s[2] = '\0';
	}
	else
	{
		itoa(min_aux,min_s,10);
	}
	sec_aux = cc.getSegundo();
	
	if (sec_aux <= 9)
	{
		sec_c = '0' + sec_aux;
		sec_s[0] = '0';
		sec_s[1] =  sec_c;
		sec_s[2] = '\0';
	}
	else
	{
		itoa(sec_aux,sec_s,10);
	}
	
	/* -- Concatenating the string to store */
	strcat(log, ano_s);
	strcat(log, doublepoints);
	strcat(log, mes_s);
	strcat(log, doublepoints);
	strcat(log, dia_s);
	strcat(log, doublepoints);
	strcat(log, hora_s);
	strcat(log, doublepoints);
	strcat(log, min_s);
	strcat(log, doublepoints);
	strcat(log, sec_s);
	strcat(log,slash);
	strcat(log, event);
	strcat(log,null);
	
	data.insertAfterLast(log); //Store the log in the data structure
}

void AirControllerAtmega::sendLog() //Send LOG via UART
{
	USART_putstring(data.removeFirst());
}








#include "List.h"

List::List() {
	head = 0;
}

List::~List() {
	Node* cursor = head;
	while (head) {
		cursor = cursor->getNext();
		delete head;
		head = cursor;
	}
	head = 0; // Officially empty
}

void List::insertAfterLast(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent)
 {
	Node* p = head;
	Node* q = head;

	if (head == 0)
		head = new Node(newYear,newMonth, newDay, newHour, newMin, newSec, newEvent, head);
		
	else 
	{
		while (q != 0) 
		{
			p = q;
			q = p->getNext();
		}
		p->setNext(new Node(newYear,newMonth, newDay, newHour, newMin, newSec, newEvent, 0));
	}
}

void List::listLogs(int max_day, int min_day, int year, int month)
{
	Node* aux = head;
	int check_day;

  	while (aux != 0)
	{
		if (aux->getYear() == year)
		{
			if(aux->getMonth() == month)
			{
				check_day = aux->getDay();
				if (check_day <= max_day && check_day >= min_day)
				{
					List::printLog(aux);
				}
				aux = aux->getNext();
			}
		}
  	}
}

void List::printLog(Node* aux)
{
	cout << aux->getDay() << "/"<< aux->getMonth()<< "/" << aux->getYear() << " " 
	<< aux ->getHour()  << ":" << aux->getMin() << ":" << aux->getSec() 
	<< " Event: " << aux->getEvent() << endl;
}

void List::displayTotalTime() 
{
  	Node* aux = head;

	int hour = 0;
	int last_hour = 0;
	int total_hour = 0;

	while (aux != 0)
	{
		if ((aux->getEvent()) == 'b')
		{
			hour = (aux->getHour())*3600 + (aux->getMin())*60 + (aux->getSec());
			aux = aux->getNext();

			if(aux != 0)
			{
				last_hour = (aux->getHour())*3600 + (aux->getMin())*60 + (aux->getSec());
			}
			else
				last_hour = 0;	
		}
		total_hour += last_hour - hour;
		aux = aux->getNext();
	}

	int printHour = total_hour/3600;
	int printMinute = (total_hour % 3600)/60;

	cout << "Tempo toral de uso: " << printHour << " horas e " << printMinute << " minutos" << endl; 
}

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

void List::removeFirst() 
{
	if (head != 0) {
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
}

void List::listLogs(int max_day, int min_day)
{
	Node* aux = head;
	int check;

  	while (aux != 0)
	{
		check = aux->getDay();
		if (check <= max_day && check >= min_day)
		{
			List::printLog(aux);
		}
     	aux = aux->getNext();
  	}
}

void List::printLog(Node* aux)
{
	cout << aux->getDay() << "/"<< aux->getMonth()<< "/" << aux->getYear() << " " 
	<< aux ->getHour()  << ":" << aux->getMin() << ":" << aux->getSec() 
	<< " Event: " << aux->getEvent() << endl;
}

float List::displayTotalTime() 
{
  	Node* aux = head;

	float hour = 0;
	float last_hour = 0;
	float total_hour = 0;

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

	return total_hour;
}
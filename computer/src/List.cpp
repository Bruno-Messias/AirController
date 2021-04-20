
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
		if (check < max_day && check > min_day)
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

	while (aux != 0){
		if (aux->getEvent() == 'a')
		{
			hour = aux->getHour();
			hour += (aux->getMin())/60;
			hour += (aux->getSec())/3600;

			while (aux->getEvent() != 'b')
			{
				aux = aux->getNext();
			}

			last_hour = aux->getHour();
			last_hour += (aux->getMin())/60;
			last_hour += (aux->getSec())/3600;
			
			total_hour += hour - last_hour;
		}

		aux = aux->getNext();
	}

	return total_hour;
}

void List::mostUsedDay() {
	Node* aux = head;
	Node* actual;
	Node* most_used;

	int counter = 0;
	int compare = 0;

	while (aux != 0)
	{
		if ((aux->getEvent() == 'c') || (aux->getEvent() == 'b'))	//compare if an event occur
		{
			if (counter == 0)										//Initialization of the counter
			{
				most_used = aux;
				counter++;
			}
			else
			{
				if ((aux->getMonth() != most_used->getMonth()) || (aux->getDay() != most_used->getDay())) //Compare for the actual date
				{
					if (compare == 0)								//Initialization of compare and actual date
					{
						actual = aux;
						compare++;
					}
					else
					{
						if ((aux->getMonth() != actual->getMonth()) || (aux->getDay() != actual->getDay()))	//Compare the change of the actual date
						{
							actual = aux;
							compare = 1;
						}
						else
						{
							compare++;

							if (compare > counter)			//Update the most used day
							{
								counter = compare;
								most_used = actual;
							}
						}
					}
				}
				else 
				{
					counter++;
				}
			}
		}
		aux = aux->getNext();
	}

	cout << most_used->getDay() << "/" << most_used->getMonth() << "/" << most_used->getYear() << endl;
}
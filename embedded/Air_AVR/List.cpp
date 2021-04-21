
#include "List.h"

/*------------------- Implementation of operator new and delete to AVR-GCC ----------------*/
using std::new_handler;
extern "C" void *malloc (std::size_t);
extern "C" void free(void *);
extern void abort() __attribute__((noreturn));
new_handler __new_handler;

void *
operator new (std::size_t sz) throw()
{
	void *p;
	if (sz == 0)
	sz = 1;
	p = (void*) malloc(sz);

	while (p == 0)
	{
		new_handler handler = __new_handler;
		if (! handler)
		return 0;
		handler();
		p = (void *) malloc(sz);
	}

	return p;
}

void*
operator new[] (std::size_t sz) throw()
{
	return ::operator new(sz);
}

void
operator delete (void *ptr) throw ()
{
	if (ptr)
	free (ptr);
}

void
operator delete[] (void *ptr) throw ()
{
	::operator delete (ptr);

}
/*----------------------------------------------------------------------------------*/

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

void List::insertAfterLast(char* dat) {
	Node* p = head;
	Node* q = head;

	if (head == 0)
	head = new Node(dat, head);
	
	else {
		while (q != 0) {
			p = q;
			q = p->getNext();
		}
		p->setNext(new Node(dat, 0));
	}
}

char* List::removeFirst() {
	char *retval = 0;
	if (head != 0) {
		retval = head->getVal();
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
	return retval;
}

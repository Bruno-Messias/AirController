
#include "Node.h"

// Constructor - initializes the node
//
Node::Node(char* dat, Node* nxt) {
	val = dat;
	next = nxt;
}

// getVal returns the integer value stored in the node
//
char* Node::getVal() {
	return val;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext() {
	return next;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt) {
	next = nxt;
}
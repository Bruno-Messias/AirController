
#include "Node.h"

// Constructor - Initializes the node
Node::Node(char* dat, Node* nxt) {
	val = dat;
	next = nxt;
}

// getVal - Returns the integer value stored in the node
char* Node::getVal() {
	return val;
}

// getNext - Returns a pointer for the next node in the linked list
Node* Node::getNext() {
	return next;
}

// setNext - Stores the pointer to the next node in the list in the "next" field
void Node::setNext(Node* nxt) {
	next = nxt;
}
//
// Created by bruno on 12/05/2021.
//

#include "Node.h"

// Constructor - initializes the node
Node::Node(string newLog, Node* nxt) {
    log = newLog;
    next = nxt;
}

string Node::getVal() {
    return log;
}

// getNext returns a pointer for the next node in the linked list
Node* Node::getNext() {
    return next;
}

// setNext stores the pointer to the next node in the list in the "next" field
void Node::setNext(Node* nxt) {
    next = nxt;
}
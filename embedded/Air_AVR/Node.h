
class Node {
	char *val;
	Node* next;
	public:
	Node(char* val, Node* nxt);
	char* getVal();
	Node* getNext();
	void setNext(Node* nxt);
};
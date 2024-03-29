
#include "Node.cpp"


/*------------------- Adding operator new and delete to AVR-GCC ----------------*/
extern "C++" {
	namespace std
	{
		typedef unsigned int size_t;
		typedef void (*new_handler)();
		new_handler set_new_handler(new_handler) throw();
	}

	void operator delete(void*) throw();
	void operator delete[](void*) throw();
	void* operator new(std::size_t) throw();
	void* operator new[](std::size_t) throw();
	void operator delete(void*) throw();
	void operator delete[](void*) throw();
	// Default placement versions of operator new.
	inline void* operator new(std::size_t, void* __p) throw() { return __p; }
	inline void* operator new[](std::size_t, void* __p) throw() { return __p; }
	// Default placement versions of operator delete.
	inline void  operator delete  (void*, void*) throw() { }
	inline void  operator delete[](void*, void*) throw() { }
}
/*-------------------------------------------------------------------------------*/

class List {
	
	public:
	Node* head;
	
	List();
	~List();
	void insertAfterLast(char* dat);
	char* removeFirst();
	char* removeNode(char* dat);
};
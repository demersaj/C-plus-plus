//Stack class declaration

#ifndef Stack_hpp
#define Stack_hpp

#include "Character.hpp"

struct StackNode
{
	StackNode(Character *c);
	
	Character* toon; //Character the specific Node contains
	StackNode* next; //pointer to the next Node object
	StackNode* prev; //pointer to the previous Node object
};


class Stack
{
public:
	~Stack();
	void addBack(Character* c);
	void printStack();
	void clearStack();
private:
	StackNode *head; //List head pointer
	StackNode *tail; //Marks the end of the doubly-linked list
};

#endif /* Stack_hpp */

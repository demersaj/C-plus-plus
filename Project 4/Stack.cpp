//Stack class definition

#include "Stack.hpp"

//Constructor
StackNode::StackNode(Character *c)
{
	toon = c;
	next = NULL;
	prev = NULL;
}

//Destructor
Stack::~Stack()
{
	clearStack();
}

void Stack::addBack(Character *c)
{
	StackNode *curr = new StackNode(c);
	if (!tail)
	{
		//Empty stack
		head = curr;
		tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		tail = tail->next;
	}
}

void Stack::clearStack()
{
	StackNode *nodePtr = head; //To traverse the list
	head = NULL;
	tail = NULL;
	
	//While nodePtr is not at the end of the list:
	while(nodePtr != NULL)
	{
		if (nodePtr->prev)
		{
			//Deletes the previous node
			delete nodePtr->prev;
		}
		//Deletes next node
		if (nodePtr->next)
			nodePtr = nodePtr->next;
		else
			break;
	}
	//Deletes current node
	delete nodePtr;
}

void Stack::printStack()
{
		std::cout << "The losers are: ";
		for (StackNode *c = head; c; c = c-> next)
		{
			std::cout << "Type: " << c->toon->getType() << " Name: " << c->toon->getName() << ((c == tail) ? ".\n" : ", ");
		}
}

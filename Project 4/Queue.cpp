//Queue class definition

#include "Queue.hpp"
#include <cstdlib>
#include <iostream>

//Constructor
Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

//Destructor
Queue::~Queue()
{
	QueueNode *garbage = front;
	while (garbage != NULL)
	{
		front = front->next;
		garbage->next = NULL;
		delete garbage;
		garbage = front;
	}
}

//QueueNode constructor
QueueNode::QueueNode(Character *c)
{
	this->toon = c;
	this->next = NULL;
	this->prev = NULL;
}

//isEmpty - checks if the queue is empty If so, returns true;
bool Queue::isEmpty() const
{
	return (front == NULL);
}

//addBack -  Takes a user-inputted integer, creates a QueueNode with user-inputted integer, and appends it to the back of the list (enqueue)
void Queue::addBack(Character *c)
{
	if (isEmpty())
	{
		front = new QueueNode(c);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(c);
		rear = rear->next;
	}
}

//getFront - Returns the value of the node at the front of the queue
Character* Queue::getFront()
{
	if (isEmpty())
		return NULL;
	else
		return front->toon;
}

//removeFront - removes the front QueueNode of the queue and free the memory (dequeue)
void Queue::removeFront()
{
	QueueNode *temp = NULL;
	
	if (!isEmpty())
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Queue::clearQueue()
{
	QueueNode *nodePtr = front; //To traverse the list
	front = NULL;
	rear = NULL;
	
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

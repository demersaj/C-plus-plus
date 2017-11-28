//Queue class declaration

#ifndef Queue_hpp
#define Queue_hpp

#include "Character.hpp"

struct QueueNode
{
	QueueNode(Character*);
	Character* toon; //Character the specific Node contains
	QueueNode* next; //pointer to the next Node object
	QueueNode* prev; //pointer to the previous Node object
};

class Queue
{
public:
	Queue();
	~Queue();
	
	//Member functions
	bool isEmpty() const;
	void addBack(Character *c);
	Character* getFront();
	void removeFront();
	void clearQueue();
	
private:
	QueueNode *front;
	QueueNode *rear;
};


#endif /* Queue_hpp */

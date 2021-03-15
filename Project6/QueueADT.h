//This is the header file for A Queue ADT using a sequential implementation 

//File: QueueADT.h
//Class provided Queue - A FIFO sequence of data items 

#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <cstdlib> //for size_t


class Queue
{
public:
	typedef int Item;	//typdef for the data member held inside the queue 
	//MEMBER CONSTANT
	static const std::size_t CAPACITY = 42; // Capacity is the maximum size of the queue, currently 42

	//CONSTRUCTOR  
	Queue(); 
	//Postcondition: Initialized an empty queue 

	//MODIFICATION MEMBER FUNCTIONS 
	void enqueue(const Item& entry); //function to add an item to the queue (Adds to rear of queue/back of line)
	//Precondition: Queue is not full (size < capacity) 
	//Postconditon: An item with value entry was added to the rear of the queue; count incremented 
	Item dequeue();					 //function to return an item from the queue (Removes the item from front of the queue) 
	//Precondition: Queue is not empty (size > 0)
	//Postcondition: The front item of the queue was removed from the queue and returned; count decremented
		
	//CONSTANT MEMBER FUNCTIONS
	std::size_t size() const { return count; }		//INLINE: returns the current size of the queue
	//Postcondition: Count returned which signifies the number of items in the queue
	bool isEmpty() const { return count == 0; }		//INLINE: returns whether queue is empty (TRUE) or has items (FALSE)
	//Postcondition: returns state of items in queue; empty queue is TRUE or queue with items is FALSE 

	//FRIEND FUNCTION
	friend std::ostream& operator <<(std::ostream& out_s, Queue q); 

private:

	//DATA MEMBERS 
	Item data[CAPACITY];	//Holds the queue's items 
	std::size_t front;		//Index of the front of the queue
	std::size_t rear;		//Index for the back of the queue
	std::size_t count;		//Current length of the queue

	//PRIVATE MEMBER FUNCTION
	std::size_t NextIndex(std::size_t i) const { return (i + 1) % CAPACITY; } //this function allows elements of the array to be reused treating it like a sequential circle
	//Precondition: 0 <= i <= CAPACITY 
	//Postcondition: Returns the value of the next element in the queue 
};
#endif
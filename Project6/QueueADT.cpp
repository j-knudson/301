//File: QueueADT.cpp
//This is the implementation file for the QueueADT
//See QueueADT.h for documentation 

//Invariant for the Queue Implementation 
/*
	1.) The member variable count holds the quantity of items in the queue
	2.) The array data[] holds the Items in the queue, in positions 0 through CAPACITY-1. 
	3.) The first item in the queue is front, and the last item is rear 
*/

#include <iostream>
#include <cstdlib>
#include "QueueADT.h"

//Default Constructor 
Queue::Queue()				//creates an empty Queue
{
	front = 0;				//first item in the queue
	rear = CAPACITY - 1;	//last item in the queue 
	count = 0;				//number of items in the queue
}

//////////////
//Modification Member Functions 
void Queue::enqueue(const Item& entry)
{
	if (count < CAPACITY)		//check if there is room in the queue
	{
		rear = NextIndex(rear); //advance rear to the next element in the array
		data[rear] = entry;		//add entry to the array
		++count;				//increment count to maintain current count of items in the queue
	}
}

Queue::Item Queue::dequeue()
{
	if (count > 0)			//check if there is an item in the Queue
	{
		Item deqValue = data[front];	//get the value from the front of the queue
		front = NextIndex(front);		//advance front to next element in array
		--count;						//decrement count of items in queue
		return deqValue;				//return retrieved value 
	}
}

////////////
//Friend Function 

std::ostream& operator << (std::ostream& out_s, Queue q)
{
	std::size_t i, index; 
	index = q.front;		//set index to the front of the queue
	for (i = 0; i < q.count; ++i)		//count holds number of items in the queue; start at front and advance until quantity of count elements visited
	{
		out_s << q.data[index] << ' ';	//print the value of the element and a space
		index = q.NextIndex(index);		//advance to the next element 
	}
	return out_s; //return the ostream
}
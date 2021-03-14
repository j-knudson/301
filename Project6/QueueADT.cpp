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

void Queue::enqueue(const Item& entry)
{
	if (count < CAPACITY)		//check if there is room in the queue
	{
		rear = NextIndex(rear); //advance rear to the next element in the array
		data[rear] = entry;		//add entry to the array
		++count;				//increment count to maintain current count of items in the queue
	}
}


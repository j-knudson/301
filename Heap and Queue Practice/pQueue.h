//Header file for the Priority Queue ADT with array based implementation

//File - pQueue.h
//Class provided - priority Queue 
#include <iostream>
#ifndef PQUEUE
#define	PQUEUE

class pQueue
{
public: 
	typedef int Item; 
	static const int CAPACITY = 5000; //current max size for the queue 

	//constructor 
	pQueue() { count = 0; }	//generate an empty list 

	//Modification member functions
	void makeEmpty() { count = 0; }
	void enqueue(Item entry);
	Item dequeue();

	//constant member functions
	int size() { return count;  }
	bool isEmpty() { return count == 0; }  //if empty return TRUE; if not empty return FALSE

private:
	//Data Members

	Item data[CAPACITY];	//Primary data member
	int count; 

	//Private member functions
	void exchange(Item& x, Item& y);		//swap values 
	void reheapUP(int child);				//move an item up the tree
	void reheapDown(int parent);				//move an item down the tree

};

#endif
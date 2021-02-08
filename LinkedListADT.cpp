//File LinkedListADT.cxx
//This is the implementation file for the LinkedListADT
//See LinkedListADT.h for documentation 

//Invariant for the Linked List Implementation 
/*
	1.) The Items in a List are stored in a linked list, in ascending order
	2.) The member variable first points to the linked list's first node. If 
	the list is empty, first is NULL
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "LinkedListADT.h"

//Default constructor is inline

//Copy Constructor  

LinkedList::LinkedList(const LinkedList& source)		// source is the list to be copied from
{
	Node* sourceTPtr;	// Traveling pointer that will traverse the source list
	Node* last;		//points at the current last node in the new list 

	if (source.first == NULL)		//if source list is empty
		first = NULL;				//set first of invoking list to NULL  --> if source list is empty new list is also empty
	else
	{
		first = GetNode(source.first-> data, NULL);  //call GetNode and create an entry using value of the first node in the source list
		last = first;				//set invoking list traveling pointer to the starting point of the new list 
		sourceTPtr = source.first->next;		//set source list traveling pointer the the first node in the source list 
		while (sourceTPtr != NULL)				//source traveling pointer p will advance until it reaches the final node pointing at NULL 
		{
			last->next = GetNode(sourceTPtr->data, NULL);
			last = last->next;			//advance traveling pointer of invoking list to a new node
			sourceTPtr = sourceTPtr->next;				//advance traveling pointer of source list to the next node 
		}
	}

}
/////////////
///Destructor
LinkedList::~LinkedList()
{
	Node* temp;			//temporary node used to traverse the list and delete nodes
	while (first != NULL)		//traverse list until we reach the last node pointing to NULL
	{							//this loop uses a temp node so we can delete all nodes in the list without losing our connection to the list 
		temp = first;				//temp takes on value of the starting node 
		first = first->next;	//starting node points at the next node in the list
		delete temp;					//temp node is deleted 
	}
}
void LinkedList::makeEmpty()   //code is the same as ~LinkedList
{
	Node* temp;			//temporary node used to traverse the list and delete nodes
	while (first != NULL)		//traverse list until we reach the last node pointing to NULL
	{							//this loop uses a temp node so we can delete all nodes in the list without losing our connection to the list 
		temp = first;				//temp takes on value of the starting node 
		first = first->next;	//starting node points at the next node in the list
		delete temp;					//temp node is deleted 
	}
}
void LinkedList::insert(Item entry)
{
	Node* prev; 	//traveling pointer to find the Node in the list that is directly before the spot (value of entry) the new node should be placed 
	if (first == NULL || entry < first->data)  //check if the list is empty or if the new value (entry) is now the smallest value in the list and should be first
		first = GetNode(entry, first);	//call GetNode to create a new node at the first position by passing value of entry and location first 
	else			//ASSERT: list is not empty and entry is > the first value in the list
	{
		prev = first;		// set our traveling pointer prev to the start of the list 
		while (prev->next != NULL && prev->next->data < entry)		//until we are at the end of list (entry is new largest value) and the node after prev contains a value < entry
			prev = prev->next;		//advance prev to next node
		prev->next = GetNode(entry, prev->next);  //create a new node with the value of entry and connect it to the list by linking it with the pointer from prev->next 
	}
}
void LinkedList::Remove(Item target)
{
	Node* trvlPtrPrev;		//create a traveling pointer that will go to Node before target (Previous: Prev) value to be removed
	Node* temp;				//A second traveling pointer 
	assert(present(target)); //check the precondition that the target is in our list by calling our boolean present function that checks for a value
	trvlPtrPrev = first;	//start at first node in the list 
	if (trvlPtrPrev->data == target)	//if the first node is the target value to be removed
	{
		first = first->next;	//set the starting node to the next node in the list
		delete trvlPtrPrev;		//delete the previous starting node which is the target value 
	}
	else
	{
		while (trvlPtrPrev->next->data < target)  //check the data field of one node further along in the list to see if the traveling pointer should advance
		{
			trvlPtrPrev = trvlPtrPrev->next;
		}
		temp = trvlPtrPrev->next;			//assign temp to the pointer that is to be deleted, which is currently aimed at by trvlPtrPrev
		trvlPtrPrev->next = temp->next;		//this sets trvlPtrPrev to be pointed one node further in the list than the node we are removing  its next field leaps past temp and to the node after that
		delete temp;						//now that trvlPtrPrev is aimed to the node after target, the list integrity is preserved and we can delete temp which holds the target value
	}
}
void LinkedList::operator = (LinkedList source)
{	
	Node* p; Node* last; 
	if (&source != this)	//this line allows us to deal with self-assignment.  i.e. List1=List1  &source = address of source list "this" is reserve word that returns address of invoking object
	{
		makeEmpty();		
		//see copy constructor if needed for explanation of this code; it is the same with p == sourceTPtr
		if (source.first != NULL)
		{
			Node* p; Node* last; // traveling pointers
			first = GetNode(source.first->data, NULL);
			last = first; 
			p = source.first->next; 
			while (p != NULL)
			{
				last->next = GetNode(p->data, NULL);
				last = last->next; 
				p = p->next; 
			}
		}
	}
}
/////////////
//CONSTANT MEMBER FUNCTIONS

bool LinkedList::present(Item target) const
{
	Node* trvlPtr = first;			//create a traveling pointer that starts at first
	while (trvlPtr != NULL && trvlPtr->data != target)	//check as long as there are more nodes (!= NULL) lazy eval adds next check if trvlPtr found desired (target) value
	{
		trvlPtr = trvlPtr->next;	//if not found and more items advance travel pointer to the next node 
	}
	return trvlPtr != NULL;
}
std::size_t LinkedList::length() const
{
	Node* cursor;		//create a traveling pointer 
	size_t count = 0; //create a variable for counting size of list and initialize to zero
	for (cursor = first; cursor != NULL; cursor = cursor->next)
	{
		count++;
	}
	return count; 
}

LinkedList::Item LinkedList::kth(int k) const			
{
	Node* cursor;	//traveling pointer
	assert(1 <= k && k <= length());			//assert k is a value within the confines of the list size:   at least 1 item and less than total lenght of list 
	cursor = first;  //set travelign pointer to first node in list
	for (int count = 1; count < k; ++count)			//while trvling ptr is < target value advance trvling ptr
		cursor = cursor->next;						//advance the trvlingptr
	return cursor->data;							//return the data field of the target node 
}
///Friend Function
std::ostream& operator <<(std::ostream& out_s, LinkedList l)
{
	LinkedList::Node* trvlPtr; //traveling pointer
	trvlPtr = l.first;		//start the traveling pointer at first 
	while (trvlPtr != NULL)
	{
		out_s << trvlPtr->data << ' '; //This prints the data field of the node and a space to the output stream labelled out_s 
		trvlPtr = trvlPtr->next;		// advance the traveling node to the next position
	}

	return out_s; //returns the output stream enables chaining of << for output statements
}

/// Private Function
LinkedList::Node* LinkedList::GetNode(Item entry, Node* link)	//return type of a LinkedList Node*   entry is a value of item type that fills the data field of the node; link points to the next node in the list
{
	Node* temp; 

	temp = new Node;
	temp->data = entry; 
	temp->next = link;
	return temp; 
}


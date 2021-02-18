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
#include "rLinkedListADT.h"

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

//Recursive Public Functions
	//These functions all make a check on the validity of the user entered value, and if it complies
	//they then call their recursive counterpart to complete the desired task 
void LinkedList::Insert(Item entry)			//create a node with value entry and add it to the list in its ordered location
{
	if (present(entry) == true)	//first check to see if the value is in the list 
	{
		std::cout << "That value is already in the list" << std::endl;		//report to user duplicate value 
		std::cout << "Value NOT added. No duplicate values allowed" << std::endl; 
		return;
	}
	else                        //value not in the list and needs to be added
		rInsert(entry, first);			//make a call to private Insert to start recursive operation to add an entry to list 
}											//starts at the first node in the list 
void LinkedList::Remove(Item target)
{
	if (present(target) != true)			//first check to see if the value is in the list 
	{
		std::cout << "That value is not in list" << std::endl;
		return;
	}
	else                          //value is in the list and needs to be removed 
		rRemove(target, first);		//call private rRemove to remove target and starting at the first node in the list 
}
LinkedList::Item  LinkedList::kth(int k)
{
	if (empty() || k > length())		//check if k is within the range of elements in the list 
	{
		std::cout << k << " is outside the range of elements in the list\n";
		std::cout << "Returning -1 as an error value\n";
		return -1;
	}
	else
		return rKth(k, first);	//if in range call private recursive rKth to report data field of k, starting with the first node 
}


///Friend Function  
//This is public portion used to access the recursive write function 
std::ostream& operator << (std::ostream& out_s, LinkedList l)  //prints a list L with N elements in format (L1 L2 ... LN ) 
{
	out_s << '(';					//print a left paren 
	l.rWrite(out_s, l.first);		//calls the rWrite function which recursively prints all nodes in the list starting with first 
	out_s << ')';					//print a right paren to close the list 
	return out_s;					//return the output stream 
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
///Recursive Functions --> Private Portions  All of these functions are called by a matched public function which acts as the face 
	//these parts are all private to access the private fields and do the heavy lifting by calling themselves 
	//Most of the public portions are written INLINE   and just make a call to the private protion which have naming format r<Original Name> 

std::size_t LinkedList::rLength(Node* p)			//this function returns the length of the list
{
	if (p == NULL)									//if P is empty we've reached the end of the list 
		return 0;
	else
		return rLength(p->next)+1;					//this starts counting at the tail (nodes after first) so add 1 to account for first node 
}

void LinkedList::rWrite(std::ostream& out_s, Node* p)  //this function prints the contents of the list to the output stream 
{
	if (p != NULL)						//while there are still unempty nodes in the list 
	{
		out_s << p->data << ' ';		//send the data field (value) of the node to the output stream 
		rWrite(out_s, p->next);			//calls itself and advances to the next node in the list 
	}
}
void LinkedList::rInsert(Item entry, Node* &link)		//this function inserts a value into the list 
{
	if (link == NULL || entry < link->data)			//this is special case if the list is empty OR the normal connection case --> item to add is smaller than current value and new node should be added here  
		link = GetNode(entry, link);				//makes a new node, assigns the given value (entry) and points it to the next node in the list, which is link 
	else
		rInsert(entry, link->next);					//if the value to be added is larger than the node we are at: function calls itself to move down the list and check the value of the next node 
}
void LinkedList::rRemove(Item target, Node* &link)		//this function removes a value (target) from the list 
{
	Node* temp;		//create a temp node which will be used when deleting target node
	if (link->data == target)  // if our current node is the value we are wanting to remove
	{
		temp = link;	//assign link (which acts as a traveling node to get into postion)  to temp
		link = link->next;	//advance link to the next node   
		delete temp;	//delete temp which was the old link and value we wanted removed
	}
	else
		rRemove(target, link->next);   //if link->data is not value we want, call function again to advance down the list 
}

void LinkedList::GiveBack(Node* temp) //this fuction deletes nodes one at a time   it recursively moves all the way down the line and then comes back deleting nodes 
{
	if (temp != NULL)		//so long as the node has a value
	{	
		GiveBack(temp->next);		//move onto the next node   
		delete temp;				//delete the node 
	}
}

void LinkedList::rMakeEmpty(Node* temp)
{
	if (temp != NULL)		//so long as the node has a value
	{
		rMakeEmpty(temp->next);		//move onto the next node   
		delete temp;				//delete the node 
	}
	else
		first = NULL;		// this line is needed to give a starting point for the list so it can be used again  
}

bool LinkedList::rPresent(Item target, Node* trvlNode)
{
	if (trvlNode == NULL || trvlNode->data > target)	// if trvlNode == Null we've hit the end of the list without finding value,  list is ordered if Node->data > target 
															//we moved past where target would be and can stop searching
		return false;
	else if (trvlNode->data == target)					//if we find desired value
			return true;
	else
		rPresent(target, trvlNode->next);				//have not found value or fail condition, advance one node and try again 
}

LinkedList::Item LinkedList::rKth(int element, Node* cursor)
{
	if (element > 1)	//element is user entered value for spot in the list  if element is > 1 we need to keep moving down the list till we get to user's desired element							
		return rKth(element - 1, cursor->next);		//advance node forward one spot while counting elements   counting backward from element until element hits 1 advances the node forward element times 
	else
		return cursor->data;						//once we get to the desired element we return the value in that element which is the data field of type Item 
}

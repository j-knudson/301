/* 
	John Knudson
	CSCI 301- Julstrom
	Project 3 - Creating a Linked List
*/


//This is the Header File for an ADT ordered linked list currently using an int

//file LinkedListADT.h
//CLASS Provided: LinkedList - an ordered list of Items 

#include <cstdlib>		//provides size_t
#include <iostream>		//provides ostream


#ifndef LINKEDLIST
#define LINKEDLIST

class LinkedList		//This is a class for a list of linked nodes  referred to in commments as LinkedList or List 
{
	public:
		
		typedef int Item;			//item will be one primary field of our node stucture  node's data field can be easily changed by changing int to desired value
		
		/////////////
		//CONSTRUCTORS
		LinkedList() {first = NULL;}  //Inline: Invoking list is empty
		//Postcondition: Initialized an empty list
		LinkedList(const LinkedList& source);	  //copy constructor 
		//Precondition: source is a LinkedList
		//Postcondition: The invoking LinkedList is initialized as a copy of LinkedList source  
		
		/////////////
		//DESTRUCTOR
		~LinkedList();			//default destructor  deletes a list 

		/////////////
		//MODIFICATION MEMBER FUNCTIONS
		void makeEmpty();		//Convert an existing list into an empty list
		//Postcondition: The List has been re-initialized into an empty list
		void insert(Item entry);	//Adds a node with a value of entry; 
		//Precondition: entry is of Item type (currently an integer) and the list does not currently contain that value
		//Postcondition:  A node has been inserted into the list in its correct position (it is a numerically sequenced ordered list)
		void Remove(Item target);	//this function will remove a node from the List
		//Precondition: Target is of Item type (integer) and a member of the List
		//Postcondition: A node corresponding to value target has been removed from the List
		void operator = (LinkedList source);		//this function attaches the symbol = to the assignment operation 
		//Postcondition: The invoking list has been assigned a copy of the source list 

		/////////////
		//CONSTANT MEMBER FUNCTIONS
		bool empty() const {return first == NULL;}  //this function checks if the List is empty by checking if the value of the first node, first, is empty 
		//Precondition: there is a list 
		//Postcondition: the status of the emptiness has been determined --> If the invoking list is empty it returns TRUE; if it not empty it returns FALSE  
		std::size_t length() const;		//returns the length of the LinkedList
		//Precondition: A nonempty list exists
		//Postcondition: The total quantity of nodes in the list has been returned 
		bool present(Item target) const;		//reports whether a specific value exists within the list or not
		//Precondition: 
		//Postcondition: If the value target is found within the list it returns TRUE if it is not found in the list it returns FALSE
		Item kth(int k) const; 
		//Precondition: The typdef for the class remains an integer 
		 
		/////////////
		//FRIEND FUNCTION for the LinkedList class:
		friend std::ostream& operator <<(std::ostream& out_s, LinkedList l);

	private: 
		
		/////////////
		//Data Members
		struct Node				//Creating our new struct named node; will have two fields
		{	
			Item data;			//Item is our typedef; first field of a node used to hold data; currently an int 
			Node* next;			//A pointer of type Node; used to point to other nodes and form a list
		};
		
		Node* first;		//This will be the first node in the list; Our starting point 
		
		
		/////////////
		//PRIVATE Functions
		LinkedList::Node* GetNode(Item entry, Node* link);		//This function will generate and return a Node* with a data field value of entry; and pointer field value of link
		//Precondition: entry is a value of Item type (currently integer); link is a node
		//Postcondition: A node containing entry and pointed at link has been generated and returned



};




#endif // !LINKEDLIST

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
		
		
		//CONSTRUCTORS
		LinkedList() {first = NULL;}  //Inline: Invoking list is empty
		//Postcondition: Initialized an empty list
		LinkedList(const LinkedList& source);	  //copy constructor 
		//Precondition: source is a LinkedList
		//Postcondition: The invoking LinkedList is initialized as a copy of LinkedList source  
		
		
		//DESTRUCTOR			 
		~LinkedList() {GiveBack(first);}		//INLINE:  default destructor  deletes a list by calling recursive function GiveBack to delete nodes starting with the first one 
		
		//////////////////////////
		//MODIFICATION MEMBER FUNCTIONS
		void makeEmpty() {rMakeEmpty(first);}		//INLINE: Convert an existing list into an empty list   works by using the MakeEmpty function starting with the first node in the list 
		//Postcondition: The List has been re-initialized into an empty list
		void operator = (LinkedList source);		//this function attaches the symbol = to the assignment operation 
		//Postcondition: The invoking list has been assigned a copy of the source list 


		///**Modification Functions that call a Paired Private Recursive function
		
		void Insert(Item entry);
		//Precondition: Entry is not currently in the list 
		//Postcondition: A node has been generated in ordered position with a value of entry
		void Remove(Item target);	 //call private, recursive function rRemove to remove an item
		//Precondition: Target is of Item type (integer) and a member of the List
		//Postcondition: A node corresponding to value target has been removed from the List

		/////////////
		//CONSTANT MEMBER FUNCTIONS
		bool empty() const {return first == NULL;}  //this function checks if the List is empty by checking if the value of the first node, first, is empty 
		//Precondition: there is a list 
		//Postcondition: the status of the emptiness has been determined --> If the invoking list is empty it returns TRUE; if it not empty it returns FALSE  

		 
		///**Constant Functions that call a Paired Private Recursive function
		std::size_t length() { return rLength(first); }     //INLINE: uses rLength and reports the length of the list 
		//Postcondtion: The number of elements in the list have been reported
		bool present(Item target) { return rPresent(target, first); }		//INLINE: reports whether a specific value exists within the list or not, sends first to start at beginning of list
		//Precondition: first is the name of the starting/first node in the list 
		//Postcondition: If the value target is found within the list it returns TRUE if it is not found in the list it returns FALSE
		Item kth(int k);		//Call rKth to recursively find the value of k element in the list 
		//Precondition: K is a number within a range of 1 <= k <= length() 
		//Postcondition: The value in the kth element was returned

		/////////////
		//FRIEND FUNCTION for the LinkedList class:
		friend std::ostream& operator <<(std::ostream& out_s, LinkedList l);
		//Postcondition: The values in the List were printed to the output stream




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

		//Private Recursive Functions
		std::size_t rLength(Node* p);
		//Precondition: called with p as the first node in the list 
		//Postcondition: Returns the number of elements in the list 
		void rWrite(std::ostream& out_s, Node* p);
		//Precondition: called with p as the first node in the list
		//Postcondition: values of all nodes in the list have been printed to the output stream out_s
		void rInsert(Item entry, Node* &link); 
		//Precondition: called with link as the first node in the list
		//Postcondition: A node with a data value of entry was generated in the correct ordered-position
		void rRemove(Item target, Node*& link);
		//Precondition: called with link as the first node in the list
		//Postcondition: A node with a data value of entry was removed from the list 

		void GiveBack(Node* temp);		//this function is used by the default destructor and deletes nodes one at a time 
		//Precondition: Temp starts as the first node in the list 
		//Postcondtion: All elements in the list have been deleted and returned
		void rMakeEmpty(Node* temp);	//this function is used to empty a list of contents and return it to an initial state 
		//Precondition: Temp starts as the first node in the list 
		//Postcondtion: The list has been re-intialized to an empty state
		bool rPresent(Item target, Node* trvlNode);		//this function checks if a specific value is present and returns TRUE (is present) or FALSE (is NOT present)
		//Precondition: trvlNode starts as the first node in the list. 
		//Postcondition: All elements of the list were checked for data field value matching target. Returns TRUE if found or FALSE if not found
		Item rKth(int element, Node* cursor);		//this fuction returns the value of the kth element of the list 
		//Precondition: element is a value in the range of the list 1 <= element <= length(), cursor starts as the first node  
		//Postcondition: The data field of the node corresponding to a position in the list matching element has been returned
};




#endif // !LINKEDLIST

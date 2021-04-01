//This is the header file for an ordered list ADT using a Binary Search Tree 
//class provided: BST
//file: BST.h

#include <iostream>
#include <cstdlib>	//for size_t
#ifndef BST
#define BST

class bst
{
public:
	typedef int Item; //ADT  --> Item 

	//default constructor
	bst() { root = NULL; }		//initialize tree to empty
	//Postcondition: Initialize an empty list
	
	//copy constructor
	bst(const bst& source) { root = rCopy(source.root); }  //call recursive copy function starting with root
	//Postcondition: The invoking bst is initialized as a copy of the source bst


	//default destructor
	~bst();

	//constant member functions 
	bool empty() { return root == NULL; } //if empty return TRUE
	//Postcondition: The status of BST emptiness has been determined --> If the invoking list is empty it returns TRUE; if it is not empty it returns FALSE
	size_t length() { return findLength(root); }	//call private recurive paired funciton findLength to determine length of the list 
	//Precondition: A non-empty list exists
	//Postcondition: The total quantity of nodes in the BST has been returned
	

	//bool present(Item target);			//returns TRUE if target is a value contained in the list  
	bool present(Item target) { return rPresent(target, root); }				//another try at present using recursion 
	//Postcondition: If the value of target is found in the list it returns TRUE; if the value is not found it returns FALSE
	
	//assignment function: 
	void operator = (bst source); 
	//Postcondition: The invoking list has been assigned a copy of the source list

	//modification member function
	void makeEmpty() { destroy(root); root = NULL; }	//convert an existing list into an empty list
	//Postcondition: The list has been re-initialized to an empty list 
	void insert(Item entry);		//add entry to the list if it is not already present 
	//Precondition: Entry is not a value currently in the list 
	//Postcondition: Entry was added to an appropriate location in the tree
	void Remove(Item target);	//call paired recursive function to remove specified value target
	//Precondition: Target is a value in the list 
	//Postcondition: A node with the value target was removed from the tree, and its binary properties were restored

	//friend function
	friend std::ostream& operator << (std::ostream& out_s, bst& source);
	//Postconidtion: the contents of source were printed to the ostream out_s 

	



private:
	struct Node
	{
		Item data;
		Node* left;
		Node* right;
	};
	//Data Member
	Node* root;

	void destroy(Node* r);
	//Postcondition: Post-Order --> All nodes down the left and right branches of Node r were removed; afterwards r is removed
	void print(Node* t);
	//Postcondition: In-Order --> Contents of left branch are printed; then the Node; then the right branch is printed 
	size_t findLength(Node* r);
	//Precondition: r is the tree's root to return the total tree length
	//Postcondition: The length of the branch and the root node is returned
	void helpRemove(Node* &root, Item target); 
	//Precondition: target is a member of the tree
	//Postcondition: Target node is located and removeNode is called on target node to delete it 
	void removeNode(Node*& t);
	//Precondition: t is a node on the tree
	//Postcondition: T has been removed from the list and binary tree status restored
	Node* rCopy(Node* r); //used to make copies of the list 

	bool rPresent(Item target, Node* r);
	//Postcondition: Status of target as a member of tree is returns; If target is a member of the tree returns TRUE, if not returns FALSE

};
#endif

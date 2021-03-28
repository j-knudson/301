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
	//copy constructor
	bst(const bst& source) { root = rCopy(source.root); }  //call recursive copy function starting with root

	//default destructor
	~bst();

	//constant member functions 
	bool empty() { return root == NULL; } //if empty reutrn TRUE
	size_t length() { return findLength(root); }	//call private recurive paired funciton findLength to determine length of the list 
	bool present(Item target);			//returns TRUE if target is a value contained in the list  

	//assignment function: 
	void operator = (bst source); 


	//modification member function
	void makeEmpty() { destroy(root); }	//convert an existing list into an empty list 
	void insert(Item entry);		//add entry to the list if it is not already present 
	void Remove(Item target) { helpRemove(root, target); }	//call paired recursive function to remove specified value target

	//friend function
	friend std::ostream& operator << (std::ostream& out_s, bst& source);

	



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
	void print(Node* t);
	size_t findLength(Node* r);
	void helpRemove(Node* &root, Item target); 
	//precondition: target is a member of the list 
	void removeNode(Node*& t);
	Node* rCopy(Node* r); //used to make copies of the list 


};
#endif

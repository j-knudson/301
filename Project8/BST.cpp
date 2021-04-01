//File BST.cpp
//implementation file for Binary Search Tree 
//see BST.h for documentation 


#include <iostream>
#include <cstdlib>
#include "BST.h"


//Invariant for the Binary Search Tree
/*
	1.) The Items in the tree are stored in a linked Binary tree; Smaller values than a node are in a branch to its left and values larger in a branch to its right
	2.) The member variable root stores the first node, and if the tree is empty root is NULL 
*/


bst::~bst()
{
	destroy(root);		//call recursive function to do the work 
}

void bst::destroy(Node* r)
{
	if (r != NULL)	//if root already null there is nothing we need to do 
	{
		destroy(r->left); //recursively destroy the left branch
		destroy(r->right); //recursively destroy the right branch  
		delete r; 
	}
}
/* //function was retried recursively 
bool bst::present(Item target)
{
	Node* p; 
	p = root; 
	while (true)
	{
		if (p == NULL)				//if p == NULL we've reached the end of the tree and there are no more values to search
			return false;
		else if (target < p->data)	//BST values smaller than node are on left branch, if target is smaller than p-> data we must explore left branch
			p = p->left;
		else if (target == p->data) //we found target; return true
			return true;
		else						//target is > p->data and we must explore right path 
			p = p->right;
	}
}*/
void bst::insert(Item entry)		//iterative version of insert
{
	if (present(entry))
		return; 
	
	Node* ptr = root;	//traveling pointer to find value	
	Node* back = NULL; //traveling ptr to move and hold location one spot behind ptr
	Node* temp;
	
	while (ptr != NULL) //while there are still values to explore 
	{
		back = ptr; //advance back to ptr
		if (entry < ptr->data) //if entry is < data  we must explore left branch to try and find our spot 
			ptr = ptr->left;
		else                     //entry is > data and we need to move down right path 
			ptr = ptr->right; 
	}
	//allocate a new node and  put entry in it 
	temp = new Node;		
	temp->data = entry;		//place entry in the data field of temp 
	temp->left = NULL;		//ready left for a leaf
	temp->right = NULL;		//ready right for a leaf

	//now we need to attach the new node temp as a leaf in our tree
	if (back == NULL)	//Special case: Tree is empty 
		root = temp;	//back never needs to advance so root gets the values of temp
	else if (entry < back->data)	//use back to determine which branch temp goes
		back->left = temp;			//temp is now a leaf on the left branch
	else //entry > back->data
		back->right = temp;			//temp is now a leaf on the right branch 
}

void bst::Remove(Item target)
{
	if (present(target))
		helpRemove(root, target);
}


void bst::helpRemove(Node*& root, Item target)	//second of three functions needed to remove a node (find the node)
{
	if (root->data == target) //base case, we are at the target node and call remove node to delete it 
		removeNode(root);
	else if (target < root->data)
		helpRemove(root->left, target);		//target value is smaller and need to explore left branch
	else //target > t->data
		helpRemove(root->right, target);		//target value is larger and need to explore right branch 
}

void bst::removeNode(Node*& t)			//third function needed to remove a node (removes the node)
{
	Node* ptr; //traveling pointer
	Node* back; //traveling pointer to follow ptr and hold position 

		if (t->left == NULL && t->right == NULL)	//Case 1: this means it's a leaf, job is easy
		{
			delete t;
			t = NULL;
		}
		else if (t->left == NULL)				//Case 2: Has a right child only 
		{
			ptr = t;				//point traveling pointer at target
			t = t->right;			//aim t pointer around target to next node so branch not lost
			delete ptr;				//delete target 
		}
		else if (t->right == NULL)			//Case 2.5: Has a left child only
		{
			ptr = t;		//aim traveling pointer
			t = t->left;	//advance t to pointing around target
			delete ptr;		//delete target 
		}
		else //has both children; we will find leftmost node in right tree
		{
			back = t; 
			ptr = t->right;		//aim down right branch

			while (ptr->left != NULL) //find leftmost node
			{
				back = ptr;
				ptr = ptr->left; 
			}

			t->data = ptr->data; //set target to traveling pointer position 
			if (back == t)	//there was only one node on the right branch
				removeNode(back->right);	//function calls itself to hit Case1 and remove the node
			else
				removeNode(back->left);		//right subtree has more than one node in its left

		}
}

void bst::operator = (bst source)
{
	destroy(root); 
	root = rCopy(source.root);
}

std::ostream& operator << (std::ostream& out_s, bst& source)
{
	source.print(source.root);
	return out_s; 
}

void bst::print(Node* p)	//in order traversal printing
{
	if (p != NULL)			//if there are more elements	
	{
		print(p->left);			//start with smaller left branch 
		std::cout << p->data << ' ';		//print data element in p
		print(p->right);		//move down the larger right branch 
	}

}

size_t bst::findLength(Node* r)
{
	if (r == NULL)
		return 0;
	else
		return findLength(r->left) + 1 + findLength(r->right);
}

bst::Node* bst::rCopy(Node* r)
{
	Node* temp;		//make a temp node
	if (r == NULL)	//base case of an empty tree
		return NULL;
	else
	{
		temp = new Node;		//make a new node
		temp->data = r->data;	//assign node the value of r
		temp->left = rCopy(r->left); //function calls itself to move down left branch
		temp->right = rCopy(r->right); //move down the right branch
		return temp; 
	}
}

bool bst::rPresent(Item target, Node* r)
{
	if (r == NULL)	//not found
		return false;
	else if (target < r->data)
		rPresent(target, r->left);
	else if (target > r->data)
		rPresent(target, r->right);
	else
		return true; 
}

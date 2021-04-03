//Header file for a program that provides an Expression Tree 

//file ExpressionTree.h
//Class Provided: ExpressionTree

#include <iostream>


#ifndef EXPTREE
#define	EXPTREE

class ExpTree
{
public:
	//Copy constructor
	ExpTree() { root = NULL; }	
	//Postcondition: Initializes an empty tree
	
	~ExpTree(); 
	//Postcondition: Returns nodes
	
	void build(std::istream& infile); 

	
	void prefix(std::ostream& outfile);	//writes a prefix expression
	void infix(std::ostream& outfile);	//writes an infix expression
	void postfix(std::ostream& outfile);	//writes a postfix expression 
	int value(); //returns value of the expression 


private:
	struct Node
	{
		int operand;		//holds the operand 
		char optr;			//holds an operator
		Node* left;			//for the left branch --> Part of expression to the left of operator
		Node* right;		//for the right branch	--> Part of expressino to right of operator 
	};
	Node* root; 

	void destroy(Node* root); //Used to give back nodes
	Node* helpBuild(std::istream& infile);
	void printPrefix(std::ostream& outfile, Node* r);
	void printInfix(std::ostream& outfile, Node* r);
	void printPostfix(std::ostream& outfile, Node* r);
	int findValue(Node* r);
};

#endif; 
//Header file for a program that provides an Expression Tree 

//file ExpressionTree.h
//Class Provided: ExpressionTree

#include <iostream>
#include <cstring>


#ifndef EXPTREE
#define	EXPTREE

class ExpTree
{
public:
	//////
	//Default constructor
	ExpTree() { root = NULL; }	
	//Postcondition: Initializes an empty tree
	
	//////
	//Default Destructor 
	~ExpTree(); 
	//Postcondition: Returns nodes
	
	void build(std::istream& infile);
	//Preconditiion: Input stream is open and available for reading
	//Postcondition: An expression tree was built from the input file's expression 

	
	void prefix(std::ostream& outfile);	//writes a prefix expression
	//Postcondition: The prefix form of the expression was printed to the output stream
	void infix(std::ostream& outfile);	//writes an infix expression
	//Postcondition: The infix form of the expression was printed to the output stream
	void postfix(std::ostream& outfile);	//writes a postfix expression 
	//Postcondition: The postfix form of the expression was printed to the output stream
	int value(); //returns value of the expression 
	//Precondition: The expression has been built and stored in a tree 
	//Postcondition: Returns the resulting value from completing the expression computation 


private:
	struct Node
	{
		int operand;		//holds the operand 
		char optr;			//holds an operator
		Node* left;			//for the left branch --> Part of expression to the left of operator
		Node* right;		//for the right branch	--> Part of expression to right of operator 
	};
	Node* root; 

	void destroy(Node* root); //Used to give back nodes
	//Postcondition: All nodes in the tree have been deleted and returned 
	Node* helpBuild(std::istream& infile);
	//Precondition: An input stream is open from which values can be read 
	//Postcondition: A tree has been built from the expressions in the input stream 
	void printPrefix(std::ostream& outfile, Node* r);
	//Postcondition: The prefix form of the expression was printed to the output stream
	void printInfix(std::ostream& outfile, Node* r);
	//Postcondition: The infix form of the expression was printed to the output stream
	void printPostfix(std::ostream& outfile, Node* r);
	//Postcondition: The postfix form of the expression was printed to the output stream
	int findValue(Node* r);
	//Precondition: To find the value of the entire expression r needs to start as the root of the tree
	//Postcondition: Returns the resulting value from completing the expression computation 
};

#endif; 
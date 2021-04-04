//ExpTree.cpp

//Implementation file for the Expression Tree class
//see ExpressionTree.h for documentation

//Invariant for the ExpTree





#include <iostream>
#include <cctype>	//for isdigit
#include "ExpressionTree.h"



//default destructor 
ExpTree::~ExpTree()
{
	destroy(root); //calls paired recursive function to give back nodes	
}

void ExpTree::build(std::istream& infile)
{
	destroy(root); //first step is to make sure we are starting with a blank slate; call destroy to clear the tree
	root = helpBuild(infile); //now call the help build function to recursively build tree from root; infile is our input stream 
}

/// ///
/// Public functions that call recursive pair
void ExpTree::prefix(std::ostream& outfile)	//writes a prefix expression
{
	return printPrefix(outfile, root);
}
void ExpTree::infix(std::ostream& outfile)
{
	return printInfix(outfile, root);
}
void ExpTree::postfix(std::ostream& outfile)
{
	return printPostfix(outfile, root);
}
int ExpTree::value() //returns value of the expression 
{
	return findValue(root);
}


/// ///
/// Private Recursive functions 
void ExpTree::destroy(Node* root) //Used to give back nodes
{
	if (root != NULL)			//Check if the root has a value 
	{							//first check if there are children that need to be deleted
		destroy(root->left);	//delete left branch
		destroy(root->right);	//delete right branch
		delete root;			//Last step: Destroy the root 
	}
}
ExpTree::Node* ExpTree::helpBuild(std::istream& infile)
{
	char ch;
	Node* temp;			

	infile >> ch; //read character
	if (isdigit(ch))		//base case --> character read is a digit
	{
		temp = new Node;	//create a new node to hold the value
		temp->operand = ch - '0';  //using subtract ascii value 0 trick to store ch as an integer value 
		temp->left = NULL;	
		temp->right = NULL;
	}
	else // ch is '('	--> start of a subexpression only has choices betwee ( or a digit 
	{
		temp = new Node;
		temp->left = helpBuild(infile); //left paren was consumed now make recursive call to get digit or subexpression to left 
		infile >> temp->optr;			//read the operator and store it 
		temp->right = helpBuild(infile);	//recursive call to store the subexpression (or digit) to the right of operator 
		infile >> ch; // ')'			//last step to consume the right paren 
	}
	return temp;						//return the node to place it on the tree
}
void ExpTree::printPrefix(std::ostream& outfile, Node* r)	//preorder traversal 
{
	if (r->left == NULL)  //leaf?  if so print operand
		outfile << r->operand << ' ';
	else
	{
		outfile << r->optr << ' ';	//prefix   start by printing operator 
		printPrefix(outfile, r->left);
		printPrefix(outfile, r->right);
	}
}
void ExpTree::printInfix(std::ostream& outfile, Node* r) //print expression in Infix notation 
{
	if (r->left == NULL)  //leaf?  if so print operand
		outfile << r->operand << ' ';
	else
	{
		outfile << "( "; //fully parenethisized infix, so add left paren
		printInfix(outfile, r->left);
		outfile << r->optr << ' ';	//infix   place optr in the middle 
		printInfix(outfile, r->right);
		outfile << ") "; //fully parenethisized infix, so add right paren
	}
}
void ExpTree::printPostfix(std::ostream& outfile, Node* r)  //print expression in postfix notation 
{
	if (r->left == NULL)  //leaf?  if so print operand
		outfile << r->operand << ' ';
	else
	{ 
		printPostfix(outfile, r->left);
		printPostfix(outfile, r->right);
		outfile << r->optr << ' ';	//postfix   end with printing operator
	}
}
int ExpTree::findValue(Node* r) //function to return the result of the expression 
{
	if (r->left == NULL)  // Leaf--> operand
		return r->operand;
	else  //interior node -->operator
	{
		if (r->optr == '+')  //if the operator is  + add the left and right branches
			return findValue(r->left) + findValue(r->right);
		else if (r->optr == '-')	//if the operators is - subtract the right branch from the lef
			return findValue(r->left) - findValue(r->right);
		else if (r->optr == '*')	//if hte operator is * multiply both sides
			return findValue(r->left) * findValue(r->right);
		else //(r->optr == '/')   divide the left side by the right side 
			return findValue(r->left) / findValue(r->right);
	}
}
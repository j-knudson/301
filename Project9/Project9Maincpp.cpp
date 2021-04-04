//This program will read an input for a fully parenthized expression and store it in an expression tree

#include <iostream>
#include <fstream>  //for ifstream
#include <cstring>
#include <string>
#include "ExpressionTree.h"


//function prototypes
void OpenInputFile(std::ifstream& in_f);
//Postcondition: A file stream has been opened for input 

void printExpression(ExpTree t1);


int main()
{
    std::ifstream infile;   //create a input file stream
    OpenInputFile(infile);  //call OpenInputFile to prompt user for a filename and open it 

    ExpTree tree1; //create an expression tree
    int expResult;
    //int c = infile.peek();
    //std::cout << c; 
    
  while(!infile.eof())
    {
        tree1.build(infile);   //build the tree
        std::cout << "Preorder: ";
        tree1.prefix(std::cout); //print infix; 
        std::cout << "\nInorder: ";
        tree1.infix(std::cout);
        std::cout << "\nPostorder: ";
        tree1.postfix(std::cout);
        expResult = tree1.value();
        std::cout << "\nValue: " << expResult <<"\n\n";
        //c = infile.peek();
    }

    //printExpression(tree1);

    return EXIT_SUCCESS;
}

void OpenInputFile(std::ifstream& in_f)    //function to open an input file
{
    std::string input_filename;              //filename to be opened stored as string
    do {                                //do while to ensure file opens
        in_f.close();
        in_f.clear();
        std::cout << "Please enter an input file name: \n";
        std::cin >> input_filename;
        in_f.open(input_filename.c_str());
    } while (in_f.fail());
}
void printExpression(ExpTree t1)
{
    std::cout << "Preorder: ";
    t1.prefix(std::cout);
    std::cout << "\nInorder: ";
    t1.infix(std::cout);
    std::cout << "\nPostorder: ";
    t1.postfix(std::cout);
    int expResult = t1.value();
    std::cout << "\nValue = ";
    t1.value();
}
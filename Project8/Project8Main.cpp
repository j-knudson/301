//This is the main file to test our ordered list class
//it consists of a menu function used to test the features of our linked list class

#include <iostream>		//provides ostream
#include <cstdlib>		//provides size_t
#include "BST.h"
using namespace std;

//Function headers
void MakeEmptyList();
void InsertValue();
void RemoveValue();
void ReportListLength();
void IsValuePresent();
void ReportValue();
void PrintList();
void PrintMenu();

bst list1; //create a linked list 

int main()
{
	cout << "This program responds to the commands the user enters to " << endl		//Program greeting
		<< "manipulate an ordered list of integers, which is initially " << endl
		<< "empty. In the following commands, v is any integer, and p " << endl
		<< "is a position in the list." << endl << endl;



	PrintMenu();			//call menu function
	cout << "Please indicate your choice from the menu" << endl;  //prompt user for a menu selection

	char userMenuChoice;	//variable for menu selection
	cin >> userMenuChoice;  // get user input


	while (userMenuChoice != 'q' && userMenuChoice != 'Q')   //this loop operates the menu Q exits loop
	{
		switch (userMenuChoice)
		{
		case 'e':
		case 'E': MakeEmptyList(); break;
		case 'i':
		case 'I': InsertValue(); break;
		case 'l':
		case 'L': ReportListLength(); break;
		case 'r':
		case 'R': RemoveValue(); break;
		case 'p':
		case 'P': IsValuePresent(); break;
		case 'k':
		case 'K': ReportValue(); break;
		case 'w':
		case 'W': PrintList(); break;
		case 'm':
		case 'M': PrintMenu(); break;
		default: cout << "Not a valid choice" << endl;				  //Default if user makes a bad input 
		}


		cin.ignore(200, '\n'); cin.clear();							 //clear input in order to allow new seleciton from list
		cout << "Please indicate your choice from the menu (m to print menu)" << endl;  //prompt user for a menu selection
		cin >> userMenuChoice;

	}


}

void PrintMenu()
{
	cout << "e -- Re-initialize the list to be empty." << endl;
	cout << "i v -- Insert the value v into the list." << endl;
	cout << "r v -- Remove the value v from the list." << endl;
	cout << "l -- Report the length of the list." << endl;
	cout << "p v -- Is the value v present in the list?" << endl;
	cout << "k n -- Report the nth value of the list." << endl;
	cout << "w -- Write out the list." << endl;
	cout << "m -- see this menu." << endl;
	cout << "q -- quit" << endl;

}

void MakeEmptyList()
{
	//cout << "I'm in MakeEmptyList" << endl;
	list1.makeEmpty();
}
void InsertValue()
{
	int value; //
	cin >> value;
	//cout << "I'm in InsertValue" << endl;
	//cout << "v is " << value << endl; 
	list1.insert(value);
}
void ReportListLength()
{
	//cout << "I'm in ReportListLength" << endl;
	size_t listlength = list1.length();
	cout << "There are " << listlength << " elements in the list.\n";
}
void RemoveValue()
{
	//cout << "I'm in RemoveValue" << endl;
	int value;		//hold an integer to be removed
	cin >> value;	//get input from user
	list1.Remove(value);
}

void IsValuePresent()
{
	//cout << "I'm in IsValuePresent" << endl;
	int value;		//hold an integer 
	cin >> value;	//get input from user
	bool isPresent = list1.present(value);		//check if given value is found -> if found condition is TRUE 
	if (isPresent == true)						//if found report to terminal
	{
		cout << "The value " << value << " is present\n";
	}
	else                                      //if NOT found report to terminal
	{
		cout << "The value " << value << " is NOT present\n";
	}
}
void ReportValue()
{
	cout << "I'm in ReportValue" << endl;/*
	int userElementWanted;		//hold an integer representing an element in the list  
	cin >> userElementWanted;	//get input from user
	int elementData = list1.kth(userElementWanted);  //find the value of the data field of the element user wants
	cout << "The value of the " << userElementWanted << "th element of the list is " << elementData << endl; //display info to terminal 
	*/
}
void PrintList()
{
	//cout << "I'm in PrintList" << endl;
	cout << list1 << endl;		//through use of overload << function   we can use a normal cout expression to print the list 
}

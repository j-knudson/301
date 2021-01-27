#include <iostream>
#include <string>
#include <cstring>
using namespace std;


void reverse(char s[], int n);										//function returns an array of character in reverse 
//Precondition: s is a char array with a size of n; n is a non-negative integer 
//Postcondition: Characters of S were printed in reverse order 

int main()
{
	
	cout << "Please enter a string of characters and they will be returned in reverse order\n"; //prompt user for a string
	string userString;														//variable for users input
	cin >> userString;														//get string from user
	int stringLength = userString.length();												//calculate length of the user's input string	
	
	char* charArray = new char[stringLength+1];											//create a character array based on size of string (length+1 for null terminator)
	strcpy_s(charArray, stringLength+1, userString.c_str());									//copy contents of userString into our new array
	
	cout << "The reversed string is: ";												//report to user on terminal
	reverse(charArray, stringLength);												//call reverse function to print the array in reverse	

	return 0;
}

void reverse(char s[], int n)
{
	if (n == 0)					//base case, an array of a single element is printed
		cout << s[n];
	else                            		//ASSERT: n > 0   
	{
		cout << s[n];				//print last element in charArray[s]
		return reverse(s, n - 1);		//call reveerse function and pass array with one less element 
	}
}
	


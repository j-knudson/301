//This is the main file for Project 5 

//This program uses the StackADT to create two stacks and test whether a user entered string is or is not a palindrome

#include <iostream>			
#include <cstdlib>		//for size_t
#include "StackADT.h"


int main()
{
	std::cout << "Please enter a string with no more than 42 characters, and I will let you know if the letters of the string are a palindrome\n"; // prompt user for a string

	char ch; //variable to hold one letter of user string 
	Stack InputStack; //create first stack which holds all the values from the user string  
	std::cin.get(ch);	//read inputs one character at a time	

	while (ch >= ' ')		//as long as there is a character to read  
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))  //make sure user character falls within alpha character range  
			InputStack.push(ch);									//add all letters to the Input stack
		std::cin.get(ch);										//get the next character from the user string 
	}

	size_t userStringSize = InputStack.size(); //Calculate the length of the users string
	Stack PalindromeCheck; //Make the second stack to receive half the characters of the user's string 
	
	while (PalindromeCheck.size() < userStringSize/2)  // Remove the second half of the characters from the first stack and put them into the second stack working down to the midpoint
	{
		ch = InputStack.pop();						//removes the top character from the first stack
		PalindromeCheck.push(ch);					//adds that character to the second stack starting at the bottom and then adding on top of it 
	}

	if (!InputStack.empty())			// in case the stack had an odd number of characters and there is one character left 
		InputStack.pop();				//removes that character and empties the first stack 

	bool isPalindrome = true;			//create a bool flag used to see if the two stacks match
	while (!InputStack.empty() && !PalindromeCheck.empty() && isPalindrome)	//Compare the characters in the two stacks until they are empty or a mismatch is found 
	{
		ch = InputStack.pop();								//get the top character from the initial stack 
		char chComparison = PalindromeCheck.pop();			//get the top character from the second stack 
		if (ch != chComparison)								//compare them to see if they match
			isPalindrome = false; 
	}

	if (isPalindrome)										//report to terminal if the user's string was a palindrome 
		std::cout << "The string IS a palindrome\n"; 
	else
		std::cout << "The string IS NOT a palindrome \n";

	return EXIT_SUCCESS;
}

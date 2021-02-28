
//This is the main file for Project 5 

//This program uses the StackADT to create two stacks and test whether a user entered string is or is not a palindrome

#include <iostream>			
#include <cstdlib>		//for size_t
#include "StackADT.h"


int main()
{
	std::cout << "Please enter a string with no more than 100 characters, and I will let you know if the string is a palindrome\n"; // prompt user for a string

	char ch; //varialbe to hold one letter of user string 
	Stack InputStack; //create first stack which holds all the values from the user string  
	std::cin.get(ch);		

	while (ch >= ' ')
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			InputStack.push(ch); 
		std::cin.get(ch);
	}

	size_t userStringSize = InputStack.size(); //Calculate the length of the users string
	Stack PalindromeCheck; //Make the second stack to receive half the characters of the user's string 
	
	while (PalindromeCheck.size() < userStringSize/2)
	{
		ch = InputStack.pop(); 
		PalindromeCheck.push(ch);
	}

	if (!InputStack.empty())
		InputStack.pop(); 

	bool isPalindrome = true; 
	
	while (!InputStack.empty() && !PalindromeCheck.empty())
	{
		//std::cout << "Stack one value: " << InputStack.pop() << std::endl;
		//std::cout << "Stack two value: " << PalindromeCheck.pop() << std::endl;
		ch = InputStack.pop(); 
		char ChComparison = PalindromeCheck.pop(); 
		if (ch != ChComparison)
			isPalindrome = false; 
	}

	if (isPalindrome)
		std::cout << "The string IS a palindrome\n"; 
	else
		std::cout << "The string IS NOT a palindrome \n";

	return EXIT_SUCCESS;
}

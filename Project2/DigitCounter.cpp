/*
	John Knudson
	CSCI 301 - Julstrom
	Project 2 - File 1 - Number of digits in an integer
*/

//This program uses a recursive function to determine the number of digits in a given positive integer


#include <iostream>
using namespace std;

int IntegerDigits(int userInt);
//Precondition: userInt is a non-negative integer
//Postcondition: number of digits in userInt was calculated and returned as a value 

int main()
{
	//Get integer from user
	cout << "Enter a positive integer and I will tell you how many digits it has\n";	//prompt user for integer input
	int userInteger;																	//Variable to hold user integer 
	cin >> userInteger;																	//Get integer to count digits from user 	

	int digits = IntegerDigits(userInteger);											//call IntegerDigits to calculate number of digits in user's integer
	cout << "This integer contains " << digits << " digits.";							//Print number of digits to terminal 
	return 0;
}

int IntegerDigits(int userInt)
{
	static int intDigits = 0;				//variable to hold value for number of digits in the Integer
	if (userInt < 10) {						//ASSERT: userInt is a single digit
		intDigits += 1;						//Increment our digit count by 1
		return intDigits;					//Return intDigits which holds total of digits in userInt
	}
	else {									//ASSERT: userInt > 10 and contains more than one digit 
		intDigits++;
		return IntegerDigits(userInt/10);
	}
		
}

/*
	Recursion Practice
	Factorial Function
*/

/*
	What is a smaller solution?
		(N-1)!
	How to use smaller solution?
		If N > 1  N * (N-1)!
	What is the base case?
		If N == 0; N! = 1
		If N == 1; N! = 1
*/
#include <iostream>

int fact(int num);
int main()
{
	std::cout << "Enter a number and  I will tell you the value of its factorial\n";
	int userNum;
	std::cin >> userNum;
	float userFact = fact(userNum);
	std::cout << "The factorial of " << userNum << " is " << userFact;

	return 0;
}

int fact(int num)
{
	if (num == 0)
			return 1;
	else
			return num*fact(num-1);
}

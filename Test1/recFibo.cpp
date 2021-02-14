/*
	Recursion Practice
  Generate a Fibonacci Sequence
*/

/*
  what is the base case?
*/

#include <iostream>
int fib(int n);

int main()
{
    std::cout << "Enter an integer n to find the Fibonnaci of that number" << '\n';
    int userFib;
    std::cin >> userFib;

    int result = fib(userFib);
    std::cout << "Your result is: " <<result << '\n';
    return 0;

}

int fib(int n)
{
  if (n == 1 || n == 0)
    return n;
  else
    return fib(n-1)+fib(n-2);
}

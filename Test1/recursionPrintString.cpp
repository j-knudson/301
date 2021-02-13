/*
	Recursion Practice
	Print String Function
  Write the digits of a non-negative integer in a vertical column
*/

/*
	What is a smaller solution?
		if n = 1   print n
	How to use smaller solution?
		if n > 1  print last digit and return remaining
	What is the base case?
		If N == 1; Print N
*/
#include <iostream>

void DigitPrinter(int num);
int main()
{

  std::cout << "Enter a number and I will print each digit\n";
  int userNum;
  std::cin >> userNum;
  std::cout << '\n';
  DigitPrinter(userNum);
  return 0;
}

void DigitPrinter(int num)
{
  if (num < 10)
  {
    std::cout << num << '\n';
  }
  else
  {
    DigitPrinter(num/10);
    std::cout << num%10 << '\n';
  }

}

/*
	Recursion Practice
	Return the sum of first N integers
*/

/*
	What is a smaller solution?
		what is num of n-1?
	How to use smaller solution?
		if n > 1  return sum+= sum(n-1)
	What is the base case?
		if n <= 1 sum = n
*/
#include <iostream>
int SumOfN(int num);

int main()
{
  std::cout << "Enter an integer and I will print the sum of each number up to that integer \n";
  int userNum;
  std::cin >> userNum;
  int sum = SumOfN(userNum);
  std::cout << "The sum of first " <<userNum <<" integers is " <<sum <<std::endl;
  return 0;
}

int SumOfN(int num)
{
  //static int total;
  if (num < 1)
    return num;
  else
  {
    //total += num;
    return SumOfN(num-1)+num;
  }
  //return total;

}

/*
	Recursion Practice
  Generate a triangle of n *'s recursively
*/

/*
	What is a smaller solution?
		Generate n-1 stars
	How to use smaller solution?
		Call to Print (n-1) stars
	What is the base case?
		if n == 1, print 1 star if n == 0 don't print
*/

#include <iostream>
void pattern(int NumStars);
void asterisks(int k);

int main()
{
  std::cout << "Enter an integer and I will make a triangle of *'s with a max line of that number" << '\n';
  int stars;
  std::cin >> stars;
  pattern(stars);
  return 0;
}

void pattern(int NumStars)
{
  if (NumStars == 1)
    std::cout << '*' << '\n';
  else
    pattern(NumStars-1);
    asterisks(NumStars);
    std::cout << '\n';

}

void asterisks(int k)
{
  if (k > 0)
  {
    asterisks(k-1);
    std::cout << "*";
  }
}

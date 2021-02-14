/*
	Recursion Practice
  Solve the Tower's of Hanoi puzzle with recursion
*/

/*
	What is a smaller solution?
		If N is > 1; move N-1 discs to Pole C
	How to use smaller solution?
		Use Pole A and Pole C as spare poles and go back and forth as many times as needed while putting largest disk on Pole B
	What is the base case?
		if n == 1, Move N from Pole A to Pole B
*/

#include <iostream>

void MoveDisc(int n, char source, char dest, char spare);
int main()
{
  std::cout << "Enter the number of discs" << '\n';
  int discs;
  std::cin >> discs;

  MoveDisc(discs, 'A', 'B', 'C');

  return 0;
}

void MoveDisc(int n, char source, char dest, char spare)
{
  if (n == 1)
  {
      std::cout << "Move top disk from " <<source << " to " << dest <<'\n';
      return;
  }
  else
  {
    MoveDisc(n-1, source, spare, dest);
    //std::cout << "Move disc " << n << "from " << source << "to " << dest << '\n';
    MoveDisc(1, source, dest, spare);
    MoveDisc(n-1, spare, dest, source);
  }

}

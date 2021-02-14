/*
	Recursion Practice
  A system with N planets, but Enterprise only has time to vist K of them.
  How many selections of K planets are possible?
*/
/*
   Planets remaining to visit if Planet P is visited is (sytems-1, planets-1)
   If planet P is not visited (sytems-1, planets)
*/


#include <iostream>
int spock(int system, int visited);

int main()
{
  std::cout << "Input a number of planets in the system and planets able to be visited, Spock will calculate\n" <<
  " the different number of groups of planets able to be visited" << std::endl;
  int sys, visit;
  std::cin >> sys; std::cin >> visit;

  int result = spock(sys, visit);
  std::cout << "Spock says you can visit " <<result <<" different groups of planets" << '\n';
}

int spock(int n, int k)
{
  if (k == 0 || k == n)
    return 1;
  else if (k > n)
    return 0;
  else
    return spock(n-1, k-1)+spock(n-1, k);
}

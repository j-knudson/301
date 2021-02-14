/*
	Recursion Practice
  Find Greatest Common Divisor
*/

/*
GCD of m and n > m = (gcd, (m, n-m))
*/
#include <iostream>
int gcd(int m, int n);

int main()
{
  std::cout << "Enter two integers and I will find their GCD" << '\n';
  int num1, num2;
  std::cin >> num1;
  std::cin >> num2;

  int div = gcd(num1, num2);
  std::cout << "The GCD is " <<div << '\n';


}

int gcd(int m, int n)
{
  if (m == n)
    return m;
  else if (n > m)
    return gcd(m, n-m);
  else
    return gcd(m-n, n);
}

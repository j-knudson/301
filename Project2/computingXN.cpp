/This program will prompt the user for inputs of x and n and calculate
//the result of x^n using a recursive function

#include <iostream>
using namespace std;

float exp(float x,int n);
//Precondition: x is a real number, n is non-negative
//Postcondition: The value of x^n is returned
int main()
{
  cout << "Please enter a real value:" <<endl;    //prompt for a value
  float userValue;                                //holds our value
  cin >> userValue;
  cout << "Please enter a non-negative integer exponent:" <<endl; //prompt for exponent
  int userExponent;
  cin >> userExponent;  //holds exponent userValue

  float productResult = exp(userValue, userExponent); //call function exp with user's real number and userExponent
                                                      //result stored in productResult
  cout << userValue <<" ^ "<<userExponent << " = " <<productResult; //display productResult to terminal

  return 0;
}

float exp(float x, int n)
{
  static float product = 1;          // value to hold result; start at 1 - base case result is 1
  if (n == 0)                   // Assert: Exponent, N, is zero --> this is base case and product = 1
    return product;                   // for any value x x^0 = 1
  else if (n > 1)               // iF n > 1 then need to multiply x by itself multiple times
  {
    product *= x;               //inrease value in product by a multiple of x
    return exp(x, n-1);         //calls itself with exponent value reduce by 1
  }
  else                          //ASSERT: n == 1
    return product *=x;         //return multiple of current value product * x
}

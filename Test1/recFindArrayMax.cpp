/*
	Recursion Practice
  Find the largest value in an array from index low to index high
*/

/*
	What is a smaller solution?
		From low+1 to high
	How to use smaller solution?
		compare low+1 to high to low
	What is the base case?
		if only one element low = high
*/

#include <iostream>
int max(int A[], int low, int high);

int main()
{
  int sampleArray[5] = {1, 4, 10, 3, 2};
  int arrayMax = max(sampleArray, 0, 5)
  std::cout << "The max value in the array is " << arrayMax << '\n';
  return 0;
}

int max(int A[], int low, int high)
{
  int tailMax;
  if (low == high)
    return A[low];
  else
  {
    tailMax = max(a, low+1, high)
    if (A[low] > tailMax)
      return A[low];
    else
      return tailMax;
  }
}

/*
	Recursion Practice
  Search a sorted array for a specific value
*/

/*
	What is a smaller solution?
		if n > 1; search n/2
	How to use smaller solution?
	  split an array into two parts and elimante one part that is too large/small
	What is the base case?
		if array has one element, is A[n] our target value?
*/
#include <iostream>

bool binSearch(int A[], int target, int low, int high);

int main()
{
  std::cout << "Enter an integer and I will report if that value is in the array" << '\n';
  int userNum;
  std::cin >> userNum;

  int B[10] = {1,2,3,4,5,6,7,8,9,10};

  bool found = binSearch(B, userNum, 0, 9);
  if (found)
  {
    std::cout << "The value " << userNum << " was found" << '\n';
  }
  else
    std::cout << "The value " << userNum << " was NOT found" << '\n';
  return 0;
}

bool binSearch(int A[], int target, int low, int high)
{
  int mid = (low + high)/2;
  if (low > high)
    return false;
  else if (A[mid] < target)
    return binSearch(A, target, mid+1, high);
  else if (A[mid] == target)
    return true;
  else
    return binSearch(A, target, low, mid-1);
}

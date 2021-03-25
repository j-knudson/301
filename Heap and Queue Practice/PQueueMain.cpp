//This program will test three algorithms: Insertion Sort, Merge Sort, and Quick Sort
//It uses a pseudo-random number generator to produce 3 equivalent arrays of values and then tests the algorithms

#include <iostream>
#include <cstdlib>	//for rand() and srand()
#include <cctype>	//for tolower()
#include "pQueue.h"

//global variable
const int MAX = 5000;	//used by merge function to create local array; this variable corresponds to userArrSize and maximum value in range prompted

//function declarations
void arrayMaker(int A[], int B[], int C[], pQueue &Q,int size, int seed, bool print);	//fills arrays with random values and if selected prints those values to terminal
//Precondition: A,B,C are arrays of equal size; size is a non-negative integer corresponding to size of A,B,C; print is set to TRUE for displaying values to terminal or False to not display; 
//Postcondition: Arrays A,B,C were filled with the same random values, and if print == True those values were printed to the terminal 
void printArray(int A[], int size);	//prints the values in an array to the terminal
//Postcondition: contents of the array were printed to the terminal

int insertionSort(int A[], int size);	//uses insertion sort algorithm to sort array and returns comparisons made
//Precondition: size is non-negative value corresponding to number of elements in A
//Postcondition: A was sorted in ascending order and the number of comparisions made to complete the sort is returned

void mergeSort(int A[], int low, int high, int &counter); //recursive function that uses merge to to sort an algorithm in ascending order; updates counter to track comparisons used in sorting
//Precondition: Counter is initialized to 0 when called from main; low/high are non-negative values; high is elements in array-1
//Postcondition: A was sorted in ascending order and counter updated to number of comparisons needed to sort the array 
void merge(int A[], int low, int mid, int high, int &counter);//used by mergeSort to recombine arrays in ascending order
//Precondition: A MAX constant for maximum size of A[] was set; A is composed of integer values; mid is non-negative value for middle element of array 
//Postcondition: A was sorted in ascending order between elements low and high; counter updated to track number of comparisons made in sorting 

void quickSort(int A[], int low, int high, int &counter); //recursive function that uses partition to sort an algorithm in ascending order; updates counter to track comparisons used in sorting
//Precondition: Counter is initialized to zero before called from main; A is filled with integer values; 
//Postcondition: A is sorted in ascending order and counter updated to track comparisons made 
void partition(int A[], int low, int high, int pivot, int& i, int& j, int &counter); //used by quickSort to create segments around a pivot value that is moved into order
//Postcondition: Pivot  moved into correct position in array; i and j updated to end/start points of smaller than pivot and larger than pivot segments


int main()
{
	std::cout << "Please enter the number of values to generate and sort (Interger Range 1:5000): \n"; 
	int userArrSize; 
	std::cin >> userArrSize; 

	std::cout << "Please enter an integer for the seed value\n";
	int userSeed; 
	std::cin >> userSeed; 

	std::cout << "Print the values? (y/n)  \n";
	char userPrint; 
	std::cin >> userPrint; 
	bool displayValues = false;						//variable for arrayMaker() to hold whether to display; 
	if (tolower(userPrint) == 'y')			//check if the user wants to print values
		displayValues = true;				//TRUE = print values to terminal
	

	int* array1 = new int[userArrSize];			//dynamically create an array of size corresponding to user input; array 1 used for inertionSort 
	int* array2 = new int[userArrSize];			//create a second array for Merge Sort
	int* array3 = new int[userArrSize];			//create a third array for Quick Sort
	pQueue queue1;
	
	arrayMaker(array1, array2, array3, queue1, userArrSize, userSeed, displayValues); //call function to make three identical arrays of random values 

	int count = insertionSort(array1, userArrSize);							//create a variable to hold the efficiency number for array sorting and try Insertion Sort

	std::cout <<std::endl <<  "Insertion Sort count = " << count << std::endl;	//Display Insertion Sort Results
	//printArray(array1, userArrSize); std::cout << std::endl; 
	int comparisons = 0;													//variable for merge sort comparisons 
	mergeSort(array2, 0, userArrSize-1, comparisons);
	std::cout << "Merge Sort count = " << comparisons << std::endl;
	
	
	//printArray(array2, userArrSize);

	comparisons = 0; //reset counter for third sorting comparison
	quickSort(array3, 0, userArrSize - 1, comparisons);		//call quickSort
	std::cout << "Quick Sort count = " << comparisons << std::endl; //display results

	//printArray(array3, userArrSize);

	for (int i = 0; i < userArrSize; i++)
	{
		int qVal = queue1.dequeue();
		std::cout << qVal << ' '; 
	}

	delete[] array1;
	delete[] array2;
	delete[] array3;
	return EXIT_SUCCESS; 
}


void arrayMaker(int A[], int B[], int C[], pQueue &Q, int size, int seed, bool print)
{
	srand(seed);							//for use with rand function
	for (int i = 0; i < size; ++i)
	{
		A[i] = rand() % 9999;				//fill array with values having a max of 4 digits
		B[i] = A[i];
		C[i] = A[i];
		Q.enqueue(A[i]);

		if (print)							//Check if the values should be displayed 
		{
			std::cout << A[i] << ' ';		//Display contents of array with a space in between 
		}
	}
}

int insertionSort(int A[], int size)		
{
	int count = 0; 
	for (int i = 1; i < size; ++i)			//create a loop startign at 1 and moving upward through all elements in the array
	{
		++count; 
		int j = i;							//create a new placeholder to move down elements in the array
		while (j > 0 && A[j] < A[j - 1])	//if there are still elements for placeholder to move down; if element value is less than neighbor (element minus 1 or leftward element) value and if so exchange values
		{
			++count;
			std::swap(A[j], A[j - 1]);  //if elements need to be exchanged, flip them
			--j;							//move placeholder down a spot and check again
			
		}
	}
	return count; 
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << A[i] << ' ';
	}
}

void mergeSort(int A[], int low, int high, int &counter)
{
	int mid;	//Create a local variable for splitting the array in two 
	if (low < high)					//check if there is room to further split the array
	{
		mid = (low + high) / 2;		//get the midpoint of the array
		mergeSort(A, low, mid, counter);		//recursive call for the lower half of the array
		mergeSort(A, mid + 1, high, counter); //recursive call for the top half of the array
		merge(A, low, mid, high, counter);		//work back up the recursive splits by calling the merge function to recombine them in order
	}
}

void merge(int A[], int low, int mid, int high, int &counter)
{
	//int* b = new int[high];		//create a local copy of the array
	int b[MAX];										//create local copy of array; max is global and currently set to 5000
	int lowerIndex, upperIndex, mergeIndex;			//indexing variables

	for (int i = low; i <= high; ++i)	//set up a loop to fill our local copy with the values from the passed in array
	{
		b[i] = A[i];
	}
	//std::cout << std::endl << "A: ";  printArray(A, high);
	//std::cout << std::endl << "B: ";  printArray(b, high);
	lowerIndex = low;			//create index for the lower half split
	upperIndex = mid + 1;		//create  index for the upper half split
	mergeIndex = low;			//Index for the primary array where smallest value between lower and upper is added

	while (lowerIndex <= mid && upperIndex <= high)	//while both array halves still have elements 
	{
		if (b[lowerIndex] < b[upperIndex])			//if the value in lower array half is smaller than the higher array half value
		{
			A[mergeIndex] = b[lowerIndex];	//set the value in the argument (primary) array to the lower value 
			++lowerIndex; 					//increment lower array index
		}
		else								//otherwise conduct the same operation for the upper half
		{
			A[mergeIndex] = b[upperIndex];
			++upperIndex;
		}
		++mergeIndex;						//increment index for primary array
		++counter;							//increment comparisons variable
	}	

	while (lowerIndex <= mid)				//if upper half is out of elements but there are still elements in lower half
	{
		A[mergeIndex] = b[lowerIndex];		//add value in lower half to primary array
		++lowerIndex; ++mergeIndex;			//increment the indexes
		++counter;							//increment comparisons variable
	}

	while (upperIndex <= high)				//other possibilty; lower half runs out of elements but there are still some in upper half
	{
		A[mergeIndex] = b[upperIndex];		//fill primary array with the upper half elements
		++upperIndex; ++mergeIndex;			//increment the indexes
		++counter;							//increment comparisons variable
	}
	//delete[] b; 
}

void quickSort(int A[], int low, int high, int &counter)
{
	int pivot; //create a variable for our pivot point 
	int lastSmallerS, firstLargerS;		//will be arguments for recursive calls, last value of smaller segment and first value for larger segment

	if (low < high)		//segment has more than 1 value 
	{
		pivot = A[low];			//a basic pivot selection   could be different 
		partition(A, low, high, pivot, lastSmallerS, firstLargerS, counter);
		quickSort(A, low, lastSmallerS, counter);		//recursive call to sort the smaller than pivot segment
		quickSort(A, firstLargerS, high, counter);		//recursive call to sort the larger than pivot segment 
	}	
}

void partition(int A[], int low, int high, int pivot, int& i, int& j, int &counter)
{
	int lastSmallerS = low - 1; //set the smaller than pivot segment index to beginning (far left) of array
	int firstUnknown = low;		//set the unknown segment index to beginning of array
	int firstLargerS = high + 1; //set the larger than pivot segment index to end (far right) of array

	while (firstUnknown < firstLargerS) //while there are still elements to examine
	{
		if (A[firstUnknown] < pivot)		//Check if the unknown value should be in the smaller than pivot segment
		{
			++lastSmallerS; //move smallerSegment pivot into position
			std::swap(A[firstUnknown], A[lastSmallerS]); //swap to place firstUnknown value in its place in the smaller than pivot segment
			++firstUnknown; //increment firstUnknown to examine the next unknown element
			++counter;		//increment comparisions counter
		}
		else if (A[firstUnknown] == pivot)			//if value is equal to pivot it will stay in place and values sort around it 
		{
			++firstUnknown;		//increment unknown value index to examine next unknown element
			++counter;			//increment comparisons counter
		}
		else					//if A[firstUnknown] > pivot and goes into the larger segment
		{
			--firstLargerS;		//decrement the larger segement index to move into position (it moves from right to left or larger value to small) 
			std::swap(A[firstUnknown], A[firstLargerS]);	//swap values to move larger than pivot value into the larger than pivot segment
			++counter;			//increment comparisons counter
		}
	}
	i = lastSmallerS;	//sets the end point of the smaller segment for recursive call (will be high/end point of the smaller partition)
	j = firstLargerS;	//sets the start point of the larger segment for recursive call (is low of the larger partition)
	
}
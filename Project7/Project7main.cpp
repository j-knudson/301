//This program will test three algorithms: Insertion Sort, Merge Sort, and Quick Sort
//It uses a pseudo-random number generator to produce 3 equivalent arrays of values and then tests the algorithms

#include <iostream>
#include <cstdlib>	//for rand() and srand()
#include <cctype>	//for tolower()

//global variable
const int MAX = 5000;	//used by merge function to create local array; this variable corresponds to userArrSize and maximum value in range prompted

//function declarations
void arrayMaker(int A[], int B[], int C[], int size, int seed, bool print);
int insertionSort(int A[], int size);
void printArray(int A[], int size);
void mergeSort(int A[], int low, int high, int &counter);
void merge(int A[], int low, int mid, int high, int &counter);

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
	
	arrayMaker(array1, array2, array3, userArrSize, userSeed, displayValues); //call function to make three identical arrays of random values 

	int count = insertionSort(array1, userArrSize);							//create a variable to hold the efficiency number for array sorting and try Insertion Sort

	std::cout <<std::endl <<  "Insertion Sort count = " << count << std::endl;	//Display Insertion Sort Results
	//printArray(array1, userArrSize); std::cout << std::endl; 
	int comparisons = 0; 
	mergeSort(array2, 0, userArrSize-1, comparisons);
	std::cout <<std::endl << "Merge Sort count = " << comparisons << std::endl;
	
	
	//printArray(array2, userArrSize);

	delete[] array1;
	delete[] array2;
	delete[] array3;
	return EXIT_SUCCESS; 
}


void arrayMaker(int A[], int B[], int C[], int size, int seed, bool print)
{
	srand(seed);							//for use with rand function
	for (int i = 0; i < size; ++i)
	{
		A[i] = rand(); 
		B[i] = A[i];
		C[i] = A[i];
		if (print)							//Check if the values should be displayed 
		{
			std::cout << A[i] << ' ';
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
		merge(A, low, mid, high, counter);
	}
}

void merge(int A[], int low, int mid, int high, int &counter)
{
	//int* b = new int[high];		//create a local copy of the array
	int b[MAX];
	int lowerIndex, upperIndex, mergeIndex;			//indexing variables

	for (int i = low; i <= high; ++i)	//set up a loop to fill our local copy with the values from the passed in array
	{
		b[i] = A[i];
	}
	//std::cout << std::endl << "A: ";  printArray(A, high);
	//std::cout << std::endl << "B: ";  printArray(b, high);
	lowerIndex = low; 
	upperIndex = mid + 1; 
	mergeIndex = low; 

	while (lowerIndex <= mid && upperIndex <= high)	//while both array halves still have elements 
	{
		if (b[lowerIndex] < b[upperIndex])			//if the value in lower array half is smaller than the higher array half value
		{
			A[mergeIndex] = b[lowerIndex];		//set the value in the argument array to the lower value 
			++lowerIndex; 					//increment lower array index
		}
		else						//otherwise conduct the same operation for the upper half
		{
			A[mergeIndex] = b[upperIndex];
			++upperIndex;
		}
		++mergeIndex;					//increment index for primary array
		++counter;					//increment comparisons variable
	}	

	while (lowerIndex <= mid)			//if upper half is out of elements but there are still elements in lower half
	{
		A[mergeIndex] = b[lowerIndex];		//add b value in lower half to primary array
		++lowerIndex; ++mergeIndex;			//increment the indexes
		++counter;				//increment comparisons variable
	}

	while (upperIndex <= high)			//other possibilty; lower half runs out of elements but there are still some in upper half
	{
		A[mergeIndex] = b[upperIndex];		//fill primary array with the upper half elements
		++upperIndex; ++mergeIndex;			//increment the indexes
		++counter;				//increment comparisons variable
	}
	//delete[] b; 
}
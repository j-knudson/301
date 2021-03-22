//This program will test three algorithms: Insertion Sort, Merge Sort, and Quick Sort
//It uses a pseudo-random number generator to produce 3 equivalent arrays of values and then tests the algorithms

#include <iostream>
#include <cstdlib>	//for rand() and srand()
#include <cctype>	//for tolower()

//function declarations
void arrayMaker(int A[], int B[], int C[], int size, int seed, bool print);
int insertionSort(int A[], int size);
void printArray(int A[], int size);

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
	bool displayValues;						//variable for arrayMaker() to hold whether to display; 
	if (tolower(userPrint) == 'y')			//check if the user wants to print values
		displayValues = true;				//TRUE = print values to terminal
	

	int* array1 = new int[userArrSize];			//dynamically create an array of size corresponding to user input; array 1 used for inertionSort 
	int* array2 = new int[userArrSize];			//create a second array for Merge Sort
	int* array3 = new int[userArrSize];			//create a third array for Quick Sort
	
	arrayMaker(array1, array2, array3, userArrSize, userSeed, displayValues); //call function to make three identical arrays of random values 

	int count = insertionSort(array1, userArrSize);							//create a variable to hold the efficiency number for array sorting and try Insertion Sort

	std::cout <<std::endl <<  "Insertion Sort count = " << count << std::endl;
	printArray(array1, userArrSize);

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
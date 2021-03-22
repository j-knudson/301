//This program will test three algorithms: Insertion Sort, Merge Sort, and Quick Sort
//It uses a pseudo-random number generator to produce 3 equivalent arrays of values and then tests the algorithms

#include <iostream>
#include <cstdlib>	//for rand() and srand()
#include <cctype>	//for tolower()

//function declarations
void arrayMaker(int A[], int B[], int C[], int size, int seed, bool print);

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
	

	int* array1 = new int[userArrSize];			//dynamically create an array of size corresponding to user input 
	int* array2 = new int[userArrSize];
	int* array3 = new int[userArrSize];
	arrayMaker(array1, array2, array3, userArrSize, userSeed, displayValues); 


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